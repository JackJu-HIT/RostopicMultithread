/**
 * 该例程将订阅/person_info话题，自定义消息类型learning_topic::Person
 */
 
#include <ros/ros.h>
#include "learning_topic/Person.h"
#include <boost/thread.hpp>
#include "geometry_msgs/Twist.h"
using namespace std;
/*
// 接收到订阅的消息后，会进入消息回调函数
void personInfoCallback(const learning_topic::Person::ConstPtr& msg)
{
    // 将接收到的消息打印出来
     ros::Rate loop_rate(10);
    ROS_INFO("Subcribe Person Info: name:%s  age:%d  sex:%d", 
			 msg->name.c_str(), msg->age, msg->sex);
             loop_rate.sleep();
}
void velInfoCallback(const geometry_msgs::Twist::ConstPtr& msg)
{
    // 将接收到的消息打印出来
     ros::Rate loop_rate(10);
    ROS_INFO("Subcribe vel Info: x_linear:%f  z_angular:%f  ", 
			 msg->linear.x, msg->angular.z);
             loop_rate.sleep();
}
*/

class person_subscriber
{
private:
    /* data */
    ros::NodeHandle n;
    ros::Publisher pub;
    ros::Subscriber person_info_sub;
    ros::Subscriber vel_info_sub;
    int age;
    
public:
    person_subscriber(/* args */);
    ~person_subscriber();


   void personInfoCallback(const learning_topic::Person::ConstPtr& msg)
   {
// 将接收到的消息打印出来
/**
     ros::Rate loop_rate(10);
    ROS_INFO("Subcribe Person Info: name:%s  age:%d  sex:%d", 
			 msg->name.c_str(), msg->age, msg->sex);
             loop_rate.sleep();
*/
   age=msg->age;

   }


   void velInfoCallback(const geometry_msgs::Twist::ConstPtr& msg)
   {

    // 将接收到的消息打印出来
    // ros::Rate loop_rate(10);
    //ROS_INFO("Subcribe vel Info: x_linear:%f  z_angular:%f  ", 
	//		 msg->linear.x, msg->angular.z);
    double value=msg->linear.x;
     cout<<"x+age"<<(value+this->age)<<endl;


       //      loop_rate.sleep();



   }
    
};

person_subscriber::person_subscriber(/* args */)
{
     pub=n.advertise<geometry_msgs::Twist>("deal_pub",1000);
     person_info_sub=n.subscribe("/person_info",10,&person_subscriber::personInfoCallback,this);
     vel_info_sub=n.subscribe("/turtle1/cmd_vel",10,&person_subscriber::velInfoCallback,this);
}

person_subscriber::~person_subscriber()
{
}




int main(int argc, char **argv)
{
    // 初始化ROS节点
    ros::init(argc, argv, "person_subscriber");

    // 创建节点句柄
    ros::NodeHandle n;

    person_subscriber test;
    //ros::spin();
    ros::MultiThreadedSpinner spinner(3);//三个线程订阅
    spinner.spin();

    return 0;
}
