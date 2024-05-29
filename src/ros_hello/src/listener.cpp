//ROS头文件
#include "ros/ros.h"
#include "std_msgs/String.h"


void helloCallback (const std_msgs::String::ConstPtr& msg){
   ROS_INFO("Heard: [%s]", msg->data.c_str());
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe<std_msgs::String>("hello_info", 100, helloCallback);
  //ros::spin()用于调用所有可触发的回调函数。将进入循环，不会返回，类似于在循环里反复调用ros::spinOnce()。
  ros::spin(); 
  return 0;
}

