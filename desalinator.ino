#include <Arduino.h>
#include <math.h>
#include "src/FuzzyControl/EzoPmp.h"
#include "src/utils.h"
#include "src/DistillerControl.h"

EzoPmp ezo_pmp;
DistillerControl control(ezo_pmp);

void setup() {
    Serial.begin(9600);
    Serial3.begin(9600);
}

/**
 * This method executes everytime serial port_0
 * receives a char. This method will read the inputString
 * until a CR (delimiter) is received.
 */
void serialEvent3() {
    String str = Serial3.readStringUntil(CARRIAGE_RETURN);
    ezo_pmp.setResponse(str);
}

void loop() {
    ezo_pmp.setMaxFlowRate();
    control.initFuzzyControl();
    control.initPumpControl();
    delay(5000);
}
