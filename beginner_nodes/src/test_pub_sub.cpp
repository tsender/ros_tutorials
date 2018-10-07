#include "beginner_nodes/test_pub_sub.h"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "test_pub_sub");
    TestPubSub tps;
    tps.Loop();
}

TestPubSub::TestPubSub() : nh("test_pub_sub")
{
    sub = nh.subscribe<beginner_msgs::MyMsg>("test", 1, &TestPubSub::TestCB, this);
    pub = nh.advertise<beginner_msgs::MyMsg>("test", 1);
}

void TestPubSub::TestCB(const beginner_msgs::MyMsg::ConstPtr& msg)
{
    ROS_INFO("My message time: %f", msg->header.stamp.toSec());
    ROS_INFO("My message x: %f", msg->velocity.x);
    ROS_INFO("My message count: %i", msg->count);
}

void TestPubSub::Loop()
{
    ros::Rate rate(1);
    while(ros::ok())
    {
        beginner_msgs::MyMsg msg;
        msg.header.stamp = ros::Time::now();
        msg.velocity.x = 6;
        msg.velocity.y = 5;
        msg.velocity.z = 4;
        msg.count = 2;
        pub.publish(msg);
        ros::spinOnce();
        rate.sleep();
    }
}