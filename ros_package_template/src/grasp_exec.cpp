#include "ros_package_template/RosPackageTemplate.hpp"

// STD
#include <string>

// Set the callback function to expect the message type Grasp
void graspsCallback(const moveit_msgs::Grasp::ConstPtr& msg){
    ROS_INFO("I heard: [%s]", msg->id.c_str());
}

// opens the namespace
namespace ros_package_template
{

  // class constructor. takes ref to ros::NodeHandle and initialises nodeHandle_ member variable with input.
  GraspExecutor::GraspExecutor(ros::NodeHandle &nodeHandle): nodeHandle_(nodeHandle)
  {

    // readParameters is a bool initialised in the class def in the header file.
    // if (!readParameters())
    // {
    //   ROS_ERROR("Could not read parameters.");
    //   ros::requestShutdown();
    // }

    // Here the subscriber is set up. Topic is specified by subscriberTopic_
    // Queue size is 1. subscriber is nodeHandle_
    // callback object is this class, callback function is topicCallback.
    subscriber_ = nodeHandle_.subscribe("grasps",1000,graspsCallback);

    // Create service server for "get_average" service. nodeHandle_ advertises the service.
    // serviceServer_ = nodeHandle_.advertiseService("get_average", &RosPackageTemplate::serviceCallback, this);

    // Confirm the node launched.
    ROS_INFO("Successfully launched node.");
  }

  // Destructor for RosPackageTemplate class.
  GraspExecutor::~GraspExecutor()
  {
  }

  // this function attempts to retrieve a parameter value named "subscriber_topic" using the getParam function.
  // retrieved value is stored in subscriberTopic_ member variable.
  // returns false if parameter does not exist on parameter server.
  // bool RosPackageTemplate::readParameters()
  // {
  //   std::cout << nodeHandle_.getNamespace() << std::endl;
  //   if (!nodeHandle_.getParam("subscriber_topic", subscriberTopic_))
  //     return false;
  //   return true;
  // }

  // // topicCallback takes temperature msg as arg.
  // void RosPackageTemplate::topicCallback(const sensor_msgs::Temperature &message)
  // {
  //   algorithm_.addData(message.temperature);
  // }

  // // serviceCallback defined here.
  // bool RosPackageTemplate::serviceCallback(std_srvs::Trigger::Request &request, std_srvs::Trigger::Response &response)
  // {
  //   response.success = true;
  //   response.message = "The average is " + std::to_string(algorithm_.getAverage());
  //   return true;
  // }

} /* namespace */
