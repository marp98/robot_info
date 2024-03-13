#include <ros/ros.h>
#include "agv_robot_info_class.cpp"

int main(int argc, char** argv) {
    ros::init(argc, argv, "agv_robot_info_node");
    ros::NodeHandle nh;

    AGVRobotInfo agv_robot("Mir100", "567A359", "169.254.5.180", "3.5.8", "100 Kg", nh);
    
    ros::Rate loop_rate(1); 

    while (ros::ok()) {
        agv_robot.publish_data();
        loop_rate.sleep();
        ros::spinOnce();
    }

    return 0;
}