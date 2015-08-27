#!/usr/bin/env python
import roslib; roslib.load_manifest('nolan')
import rospy
 
from ar_recog.msg import Tag, Tags
from geometry_msgs.msg import Twist
from std_msgs.msg import Empty
from time import time,sleep
from ardrone_autonomy.srv import CamSelect
		 
class Delta:
	def __init__(self):
		self.old_value = 0
		self.old_time = 0
		self.old_vel = 0
 
	def get_velocity(self, new_value):
		new_time = time()
 
		# velocity = distance / time
		vel = (new_value - self.old_value) / (new_time - self.old_time)
 
		# smooth velocity
		self.old_vel = self.old_vel + (vel - self.old_vel) * 0.1
 
		# save values for next time
		self.old_time = new_time
		self.old_value = new_value
 
		return self.old_vel
 
distance = Delta()
yRot = Delta()

class Handle_tags:
	def __init__(self):
		self.tasklet
		
	def tasklet(self, cam_channels):
		self.cam_channel = cam_channels
		if self.cam_channel == 1:
			self.up_ugv(Tag)
			print "following the tag"
		else:
			self.down_drone(Tag)
			print "keep position"
		
	def up_ugv(self, Tag):
		global pub
		global lastDir 
		global lastSeen
		print "started following"
		biggest = Tag()
		if biggest.diameter == 0:
			twist = Twist()
			twist.linear.x = 0
			if (time() - lastSeen > .5):
				twist.angular.z = .5*lastDir
			pub.publish(twist)
 
		# reset velocity and distance
			distance.get_velocity(0)
			yRot.get_velocity(0)
			return
 
		lastSeen = time()
 
    #Determines the co-ordinates of corners in the ar_image square
		cx = 0; cy = 0
		for i in [0,2,4,6]:
			cx = cx + biggest.cwCorners[i]
			cy = cy + biggest.cwCorners[i+1]
		cx = cx / 4. / width
		cy = cy / 4. / height

 
		twist = Twist()
 
	# move foward and backward, trying to stop at stopping_dist
		stopping_dist = 2000.
		dist = (biggest.distance - stopping_dist) / stopping_dist
		print "distance is %f" %biggest.distance
		print "dist is %f " %dist
		dist_vel = distance.get_velocity(dist)
		if abs(dist) < 0.25:
		# if we are close enough to the stopping distance, just try to stop
			twist.linear.x = dist_vel * 0.5
			twist.angular.z = 0
		else:
		# otherwise try to move within stopping_dist
			twist.linear.x = dist * 0.5
			twist.angular.z = 0
		print twist.linear.x

		pub.publish(twist)
		twist.angular.z = (-(cx - .5)/.25)

		#Keep itself from the tag at certain distance
		if (twist.angular.z < 0):
			lastDir = -1
			twist.linear.x = (1/(biggest.diameter))*40
			if (biggest.diameter>120):
				twist.linear.x= -(biggest.diameter)*0.0025
			if (biggest.diameter<120 and biggest.diameter>100):
				twist.linear.x = 0
		else:
			lastDir = 1
			twist.linear.x = (1/(biggest.diameter))*40
			if (biggest.diameter>120):
				twist.linear.x = -(biggest.diameter)*0.0025
			if (biggest.diameter<120 and biggest.diameter>100):
				twist.linear.x = 0
		pub.publish(twist)
		print twist
		print "Diameter is %f " %biggest.diameter	

	def down_drone(self, Tag):
		global pub
		global lastDir 
		global lastSeen
		print "positioning"
		if biggest.diameter == 0:
			twist = Twist()
			twist.linear.x = 0
		if (time() - lastSeen > .5):
			twist.angular.z = .5*lastDir
		pub.publish(twist)
 
		# reset velocity and distance
		distance.get_velocity(0)
		yRot.get_velocity(0)
		return
 
		lastSeen = time()
 
		cx = 0; cy = 0
		for i in [0,2,4,6]:
			cx = cx + biggest.cwCorners[i]
			cy = cy + biggest.cwCorners[i+1]
		cx = cx / 4. / width
		cy = cy / 4. / height
 
 
		twist = Twist()
 
	# move foward and backward, trying to stop at stopping_dist
		stopping_dist = 2000.
		dist = (biggest.distance - stopping_dist) / stopping_dist
		print biggest.distance
		print dist
		dist_vel = distance.get_velocity(dist)
		if abs(dist) < 0.25:
			# if we are close enough to the stopping distance, just try to stop
			twist.linear.x = dist_vel * 0.25
		else:
			# otherwise try to move within stopping_dist
			twist.linear.x = dist * 0.25
		print twist.linear.x
		twist.linear.x = max(0.03, min(0.05, twist.linear.x))   #change done here for stopping at a optimal distance after seeing the tag by krishna
 
		# try to face perpendicular to the tag
		yRot_velocity = yRot.get_velocity(biggest.yRot)
		if abs(biggest.yRot) < 0.5:
			# if we are mostly facing perpendicular, just try to stay still
			twist.linear.y = yRot_velocity * 0.25
		else:
			# otherwise, rotate towards being in front of the tag
			#twist.linear.y = biggest.yRot * 0.25
			twist.linear.y = max(-0.05, min(0.05, twist.linear.y))
 
	# rotate to face the tag
		twist.angular.z = (-(cx - .5)/.5)
 
		if (twist.angular.z < 0):
			lastDir = -1
		else:
			lastDir = 1
		pub.publish(twist)
		print twist
	
class toggle_cam:
	def __init__(self):
		self.camselectclient = rospy.ServiceProxy('/ardrone/setcamchannel', CamSelect)

	def t_cam(self):	
		while not rospy.is_shutdown():
			sleep(3);
			self.camselectclient(1);
			cam_channels = 1
			drone = Handle_tags()
			drone.tasklet(cam_channels)
			print "cam toggled : channel 1"
			sleep(6);
			self.camselectclient(0);
			cam_channels = 0
			print "cam toggled : channel 0"
			drone.tasklet(cam_channels)
			
if __name__ == "__main__":
	global pub
	global lastDir 
	global lastSeen
	
	lastSeen = 0
	lastDir = -1
 
	rospy.init_node('nolan', anonymous=True)
	toggle = toggle_cam()
	try:
		toggle.t_cam()
	except rospy.ROSInterruptException:
		pass
	pub = rospy.Publisher('cmd_vel', Twist)
	rospy.Subscriber("tags", Tags, handleTags)	
	takeoff_pub =rospy.Publisher('/ardrone/takeoff', Empty)
	rospy.spin()

