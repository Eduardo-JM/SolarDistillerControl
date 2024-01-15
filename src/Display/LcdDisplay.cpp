#include "LcdDisplay.h"

/**
 * Prints seawater, receiver, heated temperature,
 * and water flow
 * @param swt seawater temperature
 * @param rt receiver temperature
 * @param hwt heated water temperature
 * @param flow_rate water flow rate
 */
void LcdDisplay::printData(float swt, float rt, float hwt, float flow_rate) {
    clearLcdScreen();
    printSeawaterTemperature(swt);
    printReceiverTemperature(rt);
    printHeatedWaterTemperature(hwt);
    printWaterFlow(flow_rate);
}

/**
 * Clears the LCD screen and returns the cursor
 * to home
 */
void LcdDisplay::clearLcdScreen() {
    lcd.clear();
    lcd.home();
}

/**
 * Prints the text in the same line,
 * leaves a blank space before printing
 * @param text
 */
void LcdDisplay::displayText(String text) {
    if (text.length() == 0)
        return;

    lcd.setCursor(++cursor.x, cursor.y);
    lcd.print(text);
    cursor.x += text.length();
}

/**
 * Prints the text in the same line,
 * leaves a blank space before printing
 * and sets cursor to the next line
 * @param text
 */
void LcdDisplay::displayTextLine(String text) {
    displayText(text);
    cursor.x = 0;
    ++cursor.y;
}

/**
 * Prints seawater temperature into a new line
 * @param temperature
 */
void LcdDisplay::printSeawaterTemperature(float temperature) {
    String text = "Seawater: " + String(temperature) + " C";
    displayTextLine(text);
}

/**
 * Prints heated water temperature into a new line
 * @param temperature
 */
void LcdDisplay::printHeatedWaterTemperature(float temperature) {
    String text = "Heated W: " + String(temperature) + " C";
    displayTextLine(text);
}

/**
 * Prints solar receiver temperature into a new line
 * @param temperature
 */
void LcdDisplay::printReceiverTemperature(float temperature) {
    String text = "Receiver: " + String(temperature) + " C";
    displayTextLine(text);
}

/**
 * Prints water flow rate into a new line
 * @param temperature
 */
void LcdDisplay::printWaterFlow(float flow_rate) {
    String text = "Flow: " + String(flow_rate) + "ml/min";
    displayTextLine(text);
}