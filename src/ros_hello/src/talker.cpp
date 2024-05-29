//ROS头文件
#include <ros/ros.h>
#include "std_msgs/String.h"

int main(int argc, char **argv)
{
  //用于解析ROS参数，第三个参数为本节点名
  ros::init(argc, argv, "talker");

  //实例化句柄，初始化node
  ros::NodeHandle nh;

  //创建publisher
  ros::Publisher pub = nh.advertise<std_msgs::String>("hello_info", 100);

  //定义发布的频率 
  ros::Rate loop_rate(1.0);
  //循环发布msg
  int count = 0;
  while (ros::ok())
  {
    //以指数增长，每隔1秒更新一次
    std_msgs::String msg;
    std::stringstream ss;
    ss << "Hello World !" <<"Times: "<< count++;
    msg.data = ss.str();
    ROS_INFO("%s", msg.data.c_str());
   
    //以1Hz的频率发布msg
    pub.publish(msg);
    //根据前面定义的频率, sleep 1s
    loop_rate.sleep();//根据前面的定义的loop_rate,设置1s的暂停
  }

  return 0;
} 

