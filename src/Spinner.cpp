#include "Spinner.h"
#include <math.h>

Spinner::Spinner(int centerX, int centerY, int r, int count, int size, int tail) {
    cx = centerX;
    cy = centerY;
    radius = r;
    dotCount = count;
    dotSize = size;
    tailLength = tail;
    activeIndex = 0;
}

void Spinner::update() {
    activeIndex = (activeIndex + 1) % dotCount;
}

// 把"亮度比例"(0.0~1.0) 和背景色做混合，模拟渐隐
uint16_t Spinner::blendColor(Adafruit_ILI9341 &tft, uint8_t r, uint8_t g, uint8_t b, float brightness, uint16_t bgColor) {
    // 从bgColor反推出背景的RGB（这里假设背景是黑色0,0,0，最简单情况）
    uint8_t finalR = r * brightness;
    uint8_t finalG = g * brightness;
    uint8_t finalB = b * brightness;
    return tft.color565(finalR, finalG, finalB);
}

void Spinner::draw(Adafruit_ILI9341 &tft, uint8_t activeR, uint8_t activeG, uint8_t activeB, uint16_t bgColor) {
    for (int i = 0; i < dotCount; i++) {
        float angle = (2.0 * PI * i) / dotCount;
        int x = cx + radius * cos(angle);
        int y = cy + radius * sin(angle);

        // 计算这个点"落后"头部多少步（环形距离，处理绕圈的情况）
        int distance = activeIndex - i;
        if (distance < 0) distance += dotCount;

        if (distance < tailLength) {
            // 在尾巴范围内：距离越近亮度越高
            float brightness = 1.0 - ((float)distance / tailLength);
            uint16_t color = blendColor(tft, activeR, activeG, activeB, brightness, bgColor);
            tft.fillCircle(x, y, dotSize, color);
        } else {
            // 尾巴范围外：完全变成背景色（相当于擦除）
            tft.fillCircle(x, y, dotSize, bgColor);
        }
    }
}