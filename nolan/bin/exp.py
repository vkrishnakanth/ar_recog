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
        self.old_vel += (vel - self.old_vel) * 0.1

        # save values for next time
        self.old_time = new_time
        self.old_value = new_value

        return self.old_vel

distance = Delta()
yRot = Delta()


def handleTag(msg):
    global pub
    global lastDir
    global lastSeen

    width = msg.image_width
    height = msg.image_height

    toggle = Toggle_cam()
    toggle.t_cam()
    print "this is camera", toggle.cam_channels

    if toggle.cam_channels == 0:
        print "following the tag"
        biggest = Tag()
        for tag in msg.tags:
                if tag.diameter > biggest.diameter:
                        biggest = tag

        if biggest.diameter == 0:
                twist = Twist()
                twist.linear.x = 0
                if (time() - lastSeen > .5):
                        twist.angular.z = .5*lastDir
                pub.publish(twist)
                return
        print "Tag detected"
        lastSeen = time()

        cx = 0; cy = 0
        for i in [0, 2, 4, 6]:
                cx = cx + biggest.cwCorners[i]
                cy = cy + biggest.cwCorners[i+1]
        cx = cx / 4. / width
        cy = cy / 4. / height

        twist = Twist()
        if biggest.distance - 500 > 8:
                twist.linear.x = ((biggest.distance - 500.) / 500.) * .25
        if twist.linear.x < 0:
                twist.linear.x = 0
        twist.angular.z = (-(cx - .5)/.5)
        if twist.angular.z < 0:
                lastDir = -1
        else:
                lastDir = 1
        pub.publish(twist)
        print twist
    # elif toggle.cam_channels == 1:
    else:
        print "keeping position"
        biggest = Tag()
        twist = Twist()
        for tag in msg.tags:
            if tag.diameter > biggest.diameter:
                biggest = tag

        if biggest.diameter == 0:
                twist.linear.x = 0
                if (time() - lastSeen > .5):
                    twist.linear.z = .5*lastDir
                pub.publish(twist)
                return
        lastSeen = time()
        cx = 0
        cy = 0
        for i in [0, 2, 4, 6]:
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
            twist.linear.z = dist_vel * 0.25
        else:
            # otherwise try to move within stopping_dist
            twist.linear.z = dist * 0.25
        print twist.linear.z
        twist.linear.x = max(0.03, min(0.05, twist.linear.x))   #change done here for stopping at a optimal distance after seeing the tag by krishna

        # try to face perpendicular to the tag
        yRot_velocity = yRot.get_velocity(biggest.yRot)
        if abs(biggest.yRot) < 0.5:
            # if we are mostly facing perpendicular, just try to stay still
            twist.linear.y = yRot_velocity * 0.25
        else:
            # otherwise, rotate towards being in front of the tag
            #t wist.linear.y = biggest.yRot * 0.25
            twist.linear.y = max(-0.05, min(0.05, twist.linear.y))

        # rotate to face the tag
        twist.angular.z = (-(cx - .5)/.5)

        if twist.angular.z < 0:
            lastDir = -1
        else:
            lastDir = 1
        pub.publish(twist)
        print "printing twist"
        print twist


class Toggle_cam():

    def __init__(self):
        self.camselectclient = rospy.ServiceProxy('/ardrone/setcamchannel', CamSelect)
        self.cam_channels = 2

    def t_cam(self):
        while not rospy.is_shutdown():
            new_time = time()
            new_time = round(new_time)
            # print new_time
            if new_time % 2 == 0:
                self.camselectclient(1)
                self.cam_channels = 1
                sleep(3)
                print "cam channel", self.cam_channels
            else:
                self.camselectclient(0)
                self.cam_channels = 0
                sleep(3)
                print "cam_channel", self.cam_channels

            return self.cam_channels

toggle = Toggle_cam()


if __name__ == "__main__":
    global pub
    global lastDir
    global lastSeen
    global cam_channels
    lastSeen = 0
    lastDir = -1
    rospy.init_node('nolan', anonymous=True)
    pub = rospy.Publisher('cmd_vel', Twist)
    rospy.Subscriber("tags", Tags, handleTag)
    rospy.spin()
