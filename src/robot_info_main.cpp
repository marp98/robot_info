#include <ros/ros.h>
#include "robot_info_class.cpp"

int main(int argc, char** argv) {
    ros::init(argc, argv, "robot_info_node");
    ros::NodeHandle nh;

    RobotInfo robot("Mir100", "567A359", "169.254.5.180", "3.5.8", nh);

    ros::Rate loop_rate(1); 

    while (ros::ok()) {
        robot.publish_data();
        loop_rate.sleep();
        ros::spinOnce();
    }

    return 0;
}