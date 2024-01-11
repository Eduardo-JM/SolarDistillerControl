//
// Created by eduar on 10/01/2024.
//

#ifndef DESALINATOR_DISTILLEDWATERPUMP_H
#define DESALINATOR_DISTILLEDWATERPUMP_H

#include "SupplyPump.h"
#include "../Sensors/WaterLevelSensors.h"
#include "../FuzzyControl/EzoPmp.h"

#define DW_PUMPING_TIME 30000 // 30 S
#define DW_FORCE_PUMPING_TIME 900000 // 15 MIN

class DistilledWaterPump : public SupplyPump {
public:
    DistilledWaterPump(int level_sensor_pin, int relay_pin, EzoPmp ezoPmp)
            : SupplyPump(relay_pin),
              levelSensor(level_sensor_pin) {
        this->ezoPmp = ezoPmp;
        this->last_on = 0;
    }
    void startFlow() override;
private:
    WaterLevelSensors levelSensor;
    EzoPmp ezoPmp;
};


#endif //DESALINATOR_DISTILLEDWATERPUMP_H
