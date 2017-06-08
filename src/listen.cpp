#include <iostream>
#include <string.h>

#include <ros_mesg_test/MapInfo.h>
#include <ros_mesg_test/obs.h>
#include <ros/ros.h>

void sub_callback(const ros_mesg_test::MapInfo::ConstPtr& msg){

    for(int i = 0; i < msg->obsData.size(); ++i ){
        const ros_mesg_test::obs &data = msg->obsData[i];
        ROS_INFO_STREAM("StartingCol: " << data.startingCol << "EndingCol: " << data.endingCol <<
        "StartingRow: " << data.startingRow << "ENdingRow: " << data.endingRow );
    }


}

int main(int argc, char* argv[]) {
    ros::init(argc, argv, "listen_node");

    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("msg", 1000, sub_callback);

    ros::spin();

}