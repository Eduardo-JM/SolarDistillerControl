#include "SeawaterPump.h"

void SeawaterPump::startFlow() {
    if (levelSensor.readLevelSensor())
        deactivateRelay();
    else
        activateRelay();
}