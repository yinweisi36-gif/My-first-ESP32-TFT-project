

/*
void setup() {
  Serial.begin(115200);
  Serial.println("Hello ESP32!");
}

void loop() {
  // 主循环代码
}
*/
#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include "Spinner.h"

#define TFT_CS   10
#define TFT_DC    8
#define TFT_RST   9

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

// 参数：圆心(160,120) 半径40 共10个点 点大小7 拖尾长度5
Spinner mySpinner(160, 120, 40, 10, 7, 5);

// ---- 在这里调整速度 ----
int frameDelay = 120;   // 毫秒。数值越小，转动越快

void setup() {
    Serial.begin(115200);
    tft.begin();
    tft.setRotation(1);
    tft.fillScreen(ILI9341_BLACK);

    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(1);
    tft.setCursor(110, 5);
    tft.println("Loading...");
}

void loop() {
    mySpinner.update();
    mySpinner.draw(tft, 255, 255, 255, ILI9341_BLACK);   // 白色头部，黑色背景
    delay(frameDelay);
}
