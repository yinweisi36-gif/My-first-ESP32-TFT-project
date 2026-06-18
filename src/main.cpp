

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

#define TFT_CS   10
#define TFT_DC    8
#define TFT_RST   9

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

void setup() {
    Serial.begin(115200);
    delay(1000);
    Serial.println("Starting...");

    tft.begin();
    tft.setRotation(1);
    tft.fillScreen(ILI9341_YELLOW);

    tft.setTextColor(ILI9341_BLACK);
    tft.setTextSize(4.5);
    tft.setCursor(20, 5);
    tft.println("Hello World!");

    tft.setTextColor(ILI9341_RED);
    tft.setTextSize(2);
    tft.setCursor(60, 160);
    tft.println("Built by INVISIBLE");
    tft.setCursor(60, 190);
    tft.println("A personal project");

    Serial.println("Display initialized successfully!");
}

void loop() {
}