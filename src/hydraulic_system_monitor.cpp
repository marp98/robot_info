#include <string>

class HydraulicSystemMonitor {
private:
    std::string hydraulic_oil_temperature;
    std::string hydraulic_oil_tank_fill_level;
    std::string hydraulic_oil_pressure;

public:
    HydraulicSystemMonitor(const std::string& temp, const std::string& fill_level, const std::string& pressure)
        : hydraulic_oil_temperature(temp), hydraulic_oil_tank_fill_level(fill_level), hydraulic_oil_pressure(pressure) {}

    std::string getHydraulicOilTemperature() const {
        return hydraulic_oil_temperature;
    }

    std::string getHydraulicOilTankFillLevel() const {
        return hydraulic_oil_tank_fill_level;
    }

    std::string getHydraulicOilPressure() const {
        return hydraulic_oil_pressure;
    }
};