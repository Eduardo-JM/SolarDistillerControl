//
// Created by eduar on 09/01/2024.
//

#include "DistillerControl.h"

void DistillerControl::initFuzzyControl() {
    fuzzyController.handlePumpFlow(
            seawaterTemperatureSensor.getTemperature(),
            receiverTemperatureSensor.getTemperature(),
            heatedWaterTemperatureSensor.getTemperature()
            );
}

void DistillerControl::initPumpControl() {
    s_pump.startFlow();
    h_pump.startFlow();
    d_pump.startFlow();
}