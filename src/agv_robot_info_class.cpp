#include "robot_info_class.cpp"
#include "hydraulic_system_monitor.cpp"

class AGVRobotInfo : public RobotInfo {
private:
    std::string maximum_payload;
    HydraulicSystemMonitor hydraulic_system;

public:
    AGVRobotInfo(const std::string& description, const std::string& serial, const std::string& ip, const std::string& firmware,
                 const std::string& payload, const std::string& temp, const std::string& fill_level, const std::string& pressure,
                 ros::NodeHandle& nh)
        : RobotInfo(description, serial, ip, firmware, nh), maximum_payload(payload),
          hydraulic_system(temp, fill_level, pressure) {}

    void publish_data() override {
        robotinfo_msgs::RobotInfo10Fields robot_info_msg;
        robot_info_msg.data_field_01 = "robot_description: " + getRobotDescription();
        robot_info_msg.data_field_02 = "serial_number: " + getSerialNumber();
        robot_info_msg.data_field_03 = "ip_address: " + getIPAddress();
        robot_info_msg.data_field_04 = "firmware_version: " + getFirmwareVersion();
        robot_info_msg.data_field_05 = "maximum_payload: " + maximum_payload;
        robot_info_msg.data_field_06 = "hydraulic_oil_temperature: " + hydraulic_system.getHydraulicOilTemperature();
        robot_info_msg.data_field_07 = "hydraulic_oil_tank_fill_level: " + hydraulic_system.getHydraulicOilTankFillLevel();
        robot_info_msg.data_field_08 = "hydraulic_oil_pressure: " + hydraulic_system.getHydraulicOilPressure();
        robot_info_msg.data_field_09 = "";
        robot_info_msg.data_field_10 = "";

        robot_info_pub.publish(robot_info_msg);
    }
};