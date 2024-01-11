//
// Created by eduar on 10/01/2024.
//

#include "HeatedWaterPump.h"

void HeatedWaterPump::startFlow() {

    if (is_pumping) {
        if (millis() - last_on > HW_PUMPING_TIME)
            deactivateRelay();
        return;
    }

    if (ezoPmp.getCurrentStatus()) {
        if (millis() - last_on > HW_FORCE_PUMPING_TIME) {
            activateRelay();
            return;
        }
    }

    if (ezoPmp.getVolumeDispensed() > 0) {
        if (temperatureSensor.getTemperature() < HW_EVACUATION_TEMPERATURE){
            activateRelay();
            ezoPmp.clearVolumeDispensed();
            return;
        }
    }

    deactivateRelay();
}