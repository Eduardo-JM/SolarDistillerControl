#include "DistillerControl.h"

/**
 * Starts fuzzy control.
 * This starts controlling the EZO-PMP pump
 * to regulate the flow rate dispensed to the
 * solar receiver
 */
void DistillerControl::initFuzzyControl() {
    fuzzyController.handlePumpFlow(
            seawaterTemperatureSensor.getTemperature(),
            receiverTemperatureSensor.getTemperature(),
            heatedWaterTemperatureSensor.getTemperature()
            );
}

/**
 * This method starts controlling the peristaltic
 * pumps that fills and drains the distiller
 * containers
 */
void DistillerControl::initPumpControl() {
    s_pump.startFlow();
    h_pump.startFlow();
    d_pump.startFlow();
}