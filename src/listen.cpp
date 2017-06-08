#include <iostream>
#include <string.h>

#include <ros_mesg_test/MapInfo.h>
#include <ros_mesg_test/obs.h>
#include <ros_mesg_test/point2.h>
#include <ros/ros.h>

void sub_callback(const ros_mesg_test::MapInfoConstPtr& msg){

    ROS_INFO_STREAM("resolution: " << msg->resolution);

    for(int i = 0; i < msg->num; ++i ){
        const ros_mesg_test::obs &data = msg->obsData[i];

        ROS_INFO_STREAM("This is: " << i);

        ROS_INFO_STREAM("StartingCol: " << data.startingCol << "EndingCol: " << data.endingCol <<
                       "StartingRow: " << data.startingRow << "ENdingRow: " << data.endingRow );

        ROS_INFO_STREAM("point1 x: " << data.points[0].x << "point1 y: " << data.points[0].y <<
                       "point2 x: " << data.points[1].x << "point2 y: " << data.points[2].y );
    }


}

int main(int argc, char* argv[]) {
    ros::init(argc, argv, "listen_node");

    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("msg", 1000, sub_callback);

    ros::spin();

}