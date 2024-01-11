//
// Created by eduar on 10/01/2024.
//

#include "DistilledWaterPump.h"

void DistilledWaterPump::startFlow() {

    if (is_pumping) {
        if (millis() - last_on > DW_PUMPING_TIME)
            deactivateRelay();
        return;
    }

    if (levelSensor.readLevelSensor()) {
        activateRelay();
        return;
    }

    if (ezoPmp.getCurrentStatus()) {
        if (millis() - last_on > DW_FORCE_PUMPING_TIME) {
            activateRelay();
            return;
        }
    }

    deactivateRelay();
}