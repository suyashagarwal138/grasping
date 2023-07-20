#include <ros/ros.h>
#include "ros_package_template/RosPackageTemplate.hpp"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "grasp_det");

  //  topics will resolve to ros_package_template/ros_package_template_node/topic
  //  changed this to namespaced node handle
  ros::NodeHandle nodeHandle("grasp_detector");

  ros_package_template::GraspDetector graspDetector(nodeHandle);
  // define the publisher data member of the graspDetector object.
  // set it to advertise a message of type Grasp, which is from the moveit documentation.
  graspDetector.set_pub(nodeHandle.advertise<moveit_msgs::Grasp>("grasps",1000));
  
  ros::Rate loop_rate(0.4);

  while(ros::ok()){

    // declare a grasp message
    moveit_msgs::Grasp grasp_msg;

    grasp_msg.id = "This topic works!";

    // try without ROS_INFO first

    graspDetector.get_pub().publish(grasp_msg);

    ros::spinOnce();
    loop_rate.sleep();

  }

  ros::spin();
  return 0;
}
