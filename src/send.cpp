
#include <iostream>
#include <string.h>

#include <ros_mesg_test/MapInfo.h>
#include <ros_mesg_test/obs.h>
#include <ros_mesg_test/point2.h>
#include <ros/ros.h>

using namespace std;

int main(int argc, char* argv[]){
    ros::init(argc, argv, "send_node");

    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<ros_mesg_test::MapInfo>("msg", 1000);

    ros_mesg_test::point2 spoint;
    ros_mesg_test::MapInfo map_info;
    ros_mesg_test::obs obstacles;
    map_info.header.stamp = ros::Time::now();
    map_info.resolution = 0.002;

    spoint.x = 10;
    spoint.y = 11;

    obstacles.startingCol = 1;
    obstacles.endingCol = 25;
    obstacles.startingRow = 2;
    obstacles.endingRow = 100;
    obstacles.noOfPixels = 1000;
    obstacles.max_disparity = 78;
    obstacles.noOfPoints = 3;
    obstacles.points.push_back(spoint);
    spoint.x = 13;
    spoint.y = 14;
    obstacles.points.push_back(spoint);
    spoint.x = 16;
    spoint.y = 17;
    obstacles.points.push_back(spoint);
    obstacles.which_class = 1;

    map_info.obsData.push_back(obstacles);

    obstacles.startingCol = 3;
    obstacles.endingCol = 26;
    obstacles.startingRow = 4;
    obstacles.endingRow = 102;
    obstacles.noOfPixels = 2000;
    obstacles.max_disparity = 68;
    obstacles.noOfPoints = 3;
    obstacles.points.clear();
    spoint.x = 20;
    spoint.y = 21;
    obstacles.points.push_back(spoint);
    spoint.x = 23;
    spoint.y = 24;
    obstacles.points.push_back(spoint);
    spoint.x = 26;
    spoint.y = 27;
    obstacles.points.push_back(spoint);
    obstacles.which_class = 2;

    map_info.obsData.push_back(obstacles);
    map_info.num = 2;

    ros::Rate r(1);
    while(ros::ok()){
        pub.publish(map_info);
        ros::spinOnce();
        r.sleep();
    }


}

