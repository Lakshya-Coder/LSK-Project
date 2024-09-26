#ifndef ANIMATION_H
#define ANIMATION_H

#include <U8g2lib.h>
#include <Arduino.h>

class Animation {
  
  int circleRadius;
  bool isNeedToShowAnimation = false;
  bool isFilling = false;
  bool isAnimationIsCompelete = true;

  public:
    void reset() {
      circleRadius = 1;
      isNeedToShowAnimation = false;
      isFilling = true;
      isAnimationIsCompelete = false;
    }

    void display(U8G2_SSD1306_128X64_NONAME_F_HW_I2C& display) {
      if (!isNeedToShowAnimation || isAnimationIsCompelete) return;

      display.drawFilledEllipse(64, 32, circleRadius, circleRadius);
    }

    void update() {
      if (!isNeedToShowAnimation || isAnimationIsCompelete) return;

      if (circleRadius >= (128/2) + 10) {
        isFilling = false;
      }

      if (isFilling) {
        circleRadius += 4;
      } else {
        circleRadius -= 4;     
      }

      if (circleRadius <= 0) {
        isAnimationIsCompelete = true;
      }

    }

    void startAnimation() {
      reset();
      isNeedToShowAnimation = true;
    }

    void stopAnimation() {
      isNeedToShowAnimation = false;
    }

    bool isHalfAnimationCompeleted() {
      return !isFilling;
    }

    bool _isAnimationIsCompelete() {
      return isAnimationIsCompelete;
    }
};

#endif 