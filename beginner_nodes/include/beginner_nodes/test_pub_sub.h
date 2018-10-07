#ifndef TEST_PUB_SUB_H
#define TEST_PUB_SUB_H

#include "ros/ros.h"
#include "std_msgs/Int8.h"
#include "beginner_msgs/MyMsg.h"

class TestPubSub
{
private:
    ros::NodeHandle nh;
    ros::Subscriber sub;
    ros::Publisher pub;
public:
    TestPubSub();
    void TestCB(const beginner_msgs::MyMsg::ConstPtr& msg);
    void Loop();
};

#endif