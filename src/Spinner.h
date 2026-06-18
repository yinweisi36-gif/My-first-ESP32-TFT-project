#ifndef SPINNER_H
#define SPINNER_H

#include <Adafruit_ILI9341.h>

class Spinner {
public:
    Spinner(int centerX, int centerY, int radius, int dotCount, int dotSize, int tailLength);

    void update();
    void draw(Adafruit_ILI9341 &tft, uint8_t activeR, uint8_t activeG, uint8_t activeB, uint16_t bgColor);

private:
    int cx, cy;
    int radius;
    int dotCount;
    int dotSize;
    int tailLength;     // 拖尾长度（影响多少个点参与渐隐）
    int activeIndex;

    uint16_t blendColor(Adafruit_ILI9341 &tft, uint8_t r, uint8_t g, uint8_t b, float brightness, uint16_t bgColor);
};

#endif