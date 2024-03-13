#include "robot_info_class.cpp"

class AGVRobotInfo : public RobotInfo {
private:
    std::string maximum_payload;

public:
    AGVRobotInfo(const std::string& description, const std::string& serial, const std::string& ip, const std::string& firmware, const std::string& payload, ros::NodeHandle& nh)
        : RobotInfo(description, serial, ip, firmware, nh), maximum_payload(payload) {}

    void publish_data() override {
        robotinfo_msgs::RobotInfo10Fields robot_info_msg;
        robot_info_msg.data_field_01 = "robot_description: " + getRobotDescription();
        robot_info_msg.data_field_02 = "serial_number: " + getSerialNumber();
        robot_info_msg.data_field_03 = "ip_address: " + getIPAddress();
        robot_info_msg.data_field_04 = "firmware_version: " + getFirmwareVersion();
        robot_info_msg.data_field_05 = "maximum_payload: " + maximum_payload;
        robot_info_msg.data_field_06 = "";
        robot_info_msg.data_field_07 = "";
        robot_info_msg.data_field_08 = "";
        robot_info_msg.data_field_09 = "";
        robot_info_msg.data_field_10 = "";

        robot_info_pub.publish(robot_info_msg);
    }
};