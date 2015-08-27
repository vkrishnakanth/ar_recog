#!/usr/bin/env python
import roslib; roslib.load_manifest('nolan')
import rospy

from geometry_msgs.msg import Twist
from std_msgs.msg import Empty, UInt8
from ardrone_autonomy.srv import CamSelect
from time import time,sleep

class toggle_cam:
	def __init__(self):
	
		self.camselectclient = rospy.ServiceProxy('/ardrone/setcamchannel', CamSelect)

	def t_cam(self):	

		
		self.camselectclient(1);
		sleep(1);
		self.camselectclient(0);
		print "hello"	
	

if __name__ == '__main__':
	rospy.init_node('camselect', anonymous=True)
	cam = toggle_cam() 
	cam.t_cam()
	rospy.spin()
	


