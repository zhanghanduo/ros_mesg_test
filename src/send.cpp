
#include <iostream>
#include <string.h>

#include <ros_mesg_test/MapInfo.h>
#include <ros_mesg_test/obs.h>
#include <ros/ros.h>

using namespace std;

int main(int argc, char* argv[]){
    ros::init(argc, argv, "send_node");

    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<ros_mesg_test::MapInfo>("msg", 1000);

    ros_mesg_test::MapInfo map_info;
    ros_mesg_test::obs obstacles;

    obstacles.startingCol = 1;
    obstacles.endingCol = 25;
    obstacles.startingRow = 2;
    obstacles.endingRow = 100;

    map_info.obsData.push_back(obstacles);

    obstacles.startingCol = 3;
    obstacles.endingCol = 26;
    obstacles.startingRow = 4;
    obstacles.endingRow = 102;

    map_info.obsData.push_back(obstacles);

    ros::Rate r(1);
    while(ros::ok()){
        pub.publish(map_info);
        ros::spinOnce();
        r.sleep();
    }


}

