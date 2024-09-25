#ifndef DISTRACTER_H
#define DISTRACTER_H

#include <U8g2lib.h>
#include <Arduino.h>
const static unsigned char dot[] U8X8_PROGMEM = {0x7c,0x00,0x82,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x82,0x00,0x7c,0x00};

class Distracter { 
  bool isInnerRectangeVisible = true;
  unsigned long lastTimeInnerRectangleVisibilityChanged = 0;
  unsigned long innerRectangeVisibilityRange = 700;

  public:
    void display(U8G2_SSD1306_128X64_NONAME_F_HW_I2C& display) {
      display.drawXBMP(117, 2, 9, 9, dot);

      if (isInnerRectangeVisible) {
        display.drawBox(119, 4, 5, 5);
      }
    }

    void update(bool isInnerRectangeForeced) {
      if (isInnerRectangeForeced) {
        isInnerRectangeVisible = true;
        return;
      }

      if (millis() - lastTimeInnerRectangleVisibilityChanged >= innerRectangeVisibilityRange) {
        isInnerRectangeVisible = !isInnerRectangeVisible;
        lastTimeInnerRectangleVisibilityChanged = millis();
      }

      // if (!isInnerRectangeVisible && millis() - lastTimeInnerRectangleVisibilityChanged >= innerRectangeVisibilityRange) {
      //   isInnerRectangeVisible = true;
      //   lastTimeInnerRectangleVisibilityChanged = millis();
      // } 

      // if (isInnerRectangeVisible) {
      //   display.drawBox(119, 4, 5, 5);

      //   if (millis() - lastTimeDistractionOn >= distractionDuration) {
      //     isDistractionOn = false;
      //     lastTimeDistractionOn = millis();
      //   }
      // }  
      
    }


};

#endif