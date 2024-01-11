//
// Created by eduar on 08/01/2024.
//

#include "SupplyPump.h"

SupplyPump::SupplyPump(int relay_pin) {
    this->relay_pin = relay_pin;
    this->is_pumping = false;
    this->last_on = 0;
}
void SupplyPump::activateRelay() {
    digitalWrite(relay_pin, HIGH);
    is_pumping = true;
    last_on = millis();
}

void SupplyPump::deactivateRelay() {
    digitalWrite(relay_pin, LOW);
    is_pumping = false;
    last_on = millis();
}