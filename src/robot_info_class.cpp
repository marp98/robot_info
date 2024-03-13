#include <string>
#include <ros/ros.h>
#include <robotinfo_msgs/RobotInfo10Fields.h>

class RobotInfo {
protected:
    std::string robot_description;
    std::string serial_number;
    std::string ip_address;
    std::string firmware_version;
    ros::Publisher robot_info_pub;

public:
    RobotInfo(const std::string& description, const std::string& serial, const std::string& ip, const std::string& firmware, ros::NodeHandle& nh)
        : robot_description(description), serial_number(serial), ip_address(ip), firmware_version(firmware) {
        robot_info_pub = nh.advertise<robotinfo_msgs::RobotInfo10Fields>("robot_info", 10);
    }

    std::string getRobotDescription() const {
        return robot_description;
    }

    std::string getSerialNumber() const {
        return serial_number;
    }

    std::string getIPAddress() const {
        return ip_address;
    }

    std::string getFirmwareVersion() const {
        return firmware_version;
    }

    virtual void publish_data() {
        robotinfo_msgs::RobotInfo10Fields robot_info_msg;
        robot_info_msg.data_field_01 = "robot_description: " + robot_description;
        robot_info_msg.data_field_02 = "serial_number: " + serial_number;
        robot_info_msg.data_field_03 = "ip_address: " + ip_address;
        robot_info_msg.data_field_04 = "firmware_version: " + firmware_version;
        robot_info_msg.data_field_05 = "";
        robot_info_msg.data_field_06 = "";
        robot_info_msg.data_field_07 = "";
        robot_info_msg.data_field_08 = "";
        robot_info_msg.data_field_09 = "";
        robot_info_msg.data_field_10 = "";

        robot_info_pub.publish(robot_info_msg);
    }
};