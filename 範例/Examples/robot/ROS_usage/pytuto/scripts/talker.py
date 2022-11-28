#!/usr/bin/env python
# license removed for brevity
import rospy
from std_msgs.msg import String
from sensor_msgs.msg import LaserScan

def talker():
    pub = rospy.Publisher('/scan', LaserScan, queue_size=10)
    rospy.init_node('talker', anonymous=True)
    rate = rospy.Rate(0.1) # 10hz
    while not rospy.is_shutdown():
        #hello_str = "hello world %s" % rospy.get_time()
        hello_str = LaserScan()
        hello_str.header.stamp = rospy.get_rostime()
        rospy.loginfo(hello_str)
        pub.publish(hello_str)
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
