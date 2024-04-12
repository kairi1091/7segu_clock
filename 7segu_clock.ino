#include <Adafruit_NeoPixel.h>
#define PIN 27        //INが接続されているピンを指定
#define NUMPIXELS 74  //LEDの数を指定
const int digitSegments[10][18] = {
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 },  // 0
  { 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 },  // 1
  { 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1 },  // 2
  { 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1 },  // 3
  { 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1 },  // 4
  { 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1 },  // 5
  { 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },  // 6
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 },  // 7
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },  // 8
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1 }   // 9
};

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);  //800kHzでNeoPixelを駆動

void setup() {
  pixels.begin();  //NeoPixelを開始
  Serial.begin(115200);
}

int s[4] = { 9, 3, 5, 8 };

void loop() {
  pixels.clear();
  //  int digitSegments1 = digitSegments[s[i]][x] - 1;
  for (int i = 0; i < 4; i++) {     //各ケタ
    for (int j = 0; j < 18; j++) {  //1ケタ分のLED（18個）の表示
      if (i == 2) {
        pixels.setPixelColor(i * 18 + j + 2, pixels.Color(10 * digitSegments[s[i]][j], 10 * digitSegments[s[i]][j], 10 * digitSegments[s[i]][j]));
      } else if (i == 3) {
        pixels.setPixelColor(i * 18 + j + 2, pixels.Color(10 * digitSegments[s[i]][j], 10 * digitSegments[s[i]][j], 10 * digitSegments[s[i]][j]));
      } else {
        pixels.setPixelColor(i * 18 + j, pixels.Color(10 * digitSegments[s[i]][j], 10 * digitSegments[s[i]][j], 10 * digitSegments[s[i]][j]));
      }
    }
  }
  pixels.setPixelColor(36, pixels.Color(10, 10, 10));
  pixels.setPixelColor(37, pixels.Color(10, 10, 10));
  pixels.show();  //LEDに色を反映
  delay(60000);
}
