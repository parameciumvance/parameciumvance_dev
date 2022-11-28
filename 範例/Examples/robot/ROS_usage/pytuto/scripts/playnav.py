#! /usr/bin/env python
import rospy

# Brings in the SimpleActionClient
import actionlib

# Brings in the messages used by the fibonacci action, including the
# goal message and the result message.
from move_base_msgs.msg import *
from geometry_msgs.msg import PointStamped

def callback(data):
    # Creates the SimpleActionClient, passing the type of the action
    # (FibonacciAction) to the constructor.
    

    # Waits until the action server has started up and started
    # listening for goals.
    print(f"get data {data.point}")
    client.wait_for_server()

    # Creates a goal to send to the action server.
    goal = MoveBaseGoal()
    goal.target_pose.header.frame_id = "map"
    goal.target_pose.header.stamp = rospy.Time.now()
    goal.target_pose.pose.position = data.point
    goal.target_pose.pose.orientation.w = 1
    print("initializing")

    # Sends the goal to the action server.
    client.send_goal(goal)
    print("sending")

    # Waits for the server to finish performing the action.
    client.wait_for_result()
    print("waiting")

    # Prints out the result of executing the action
    zz = client.get_result()  # A FibonacciResult
    print('reached')

if __name__ == '__main__':
    try:
        # Initializes a rospy node so that the SimpleActionClient can
        # publish and subscribe over ROS.
        rospy.init_node('playnav')
        client = actionlib.SimpleActionClient('move_base', MoveBaseAction)
        rospy.Subscriber("clicked_point", PointStamped, callback)
        rospy.spin()

        
    except rospy.ROSInterruptException:
        print("program interrupted before completion", file=sys.stderr)