//
// Created by eduar on 14/01/2024.
//

#ifndef DESALINATOR_LCDDISPLAY_H
#define DESALINATOR_LCDDISPLAY_H

#define LCD_COLS 20
#define LCD_ROWS 4

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

typedef struct LcdCursor {
    unsigned int x;
    unsigned int y;
} LcdCursor;

class LcdDisplay {
public:
    LcdDisplay() : lcd (0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE){
        lcd.begin (LCD_COLS, LCD_ROWS);
        lcd.setBacklightPin(3, POSITIVE);
        lcd.setBacklight(HIGH);
        clearLcdScreen();
        this->cursor.x = 0;
        this->cursor.y = 0;
    }
    void printData(float swt, float rt, float hwt, float flow_rate);
private:
    void displayText(String text);
    void displayTextLine(String text);
    void clearLcdScreen();
    void printSeawaterTemperature(float temperature);
    void printHeatedWaterTemperature(float temperature);
    void printReceiverTemperature(float temperature);
    void printWaterFlow(float flow_rate);
    LiquidCrystal_I2C lcd;
    LcdCursor cursor;

};


#endif //DESALINATOR_LCDDISPLAY_H
