#ifndef DESALINATOR_HEATEDWATERPUMP_H
#define DESALINATOR_HEATEDWATERPUMP_H

#include "../Sensors/Thermistor.h"
#include "SupplyPump.h"
#include "../FuzzyControl/EzoPmp.h"

#define HW_EVACUATION_TEMPERATURE 35.0

#define HW_FORCE_PUMPING_TIME 1200000 // 20 MIN
#define HW_PUMPING_TIME 10000 // 10 S

class HeatedWaterPump : public SupplyPump {
public:
    HeatedWaterPump(int temperature_sensor_pin, int relay_pin, EzoPmp ezoPmp)
            : SupplyPump(relay_pin),
              temperatureSensor(temperature_sensor_pin) {
        this->ezoPmp = ezoPmp;
        this->last_on = 0;
    }
    void startFlow() override;
private:
    Thermistor temperatureSensor;
    EzoPmp ezoPmp;
};

#endif //DESALINATOR_HEATEDWATERPUMP_H
