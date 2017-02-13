#include <FastLED.h>

#define BRIGHTNESS 64
#define DEFAULT_SAT 223
#define MAX_BRIGHTNESS 127
#define MAX_SAT 255
#define MIN_BRIGHTNESS 63
#define MIN_SAT 191
#define NUM_LEDS 5
#define PIN 12

CRGB leds[NUM_LEDS];

const CHSVPalette16 HAT_COLORS(
    // Red
    CHSV(0, 255, 255),
    CHSV(0, 156, 255),

    // Orange/Yellow
    CHSV(24, 255, 255),
    CHSV(24, 156, 255),

    // Yellow
    CHSV(35, 255, 255),
    CHSV(35, 156, 255),

    // Yellow-Green
    CHSV(50, 255, 246),
    CHSV(50, 155, 248),

    // Cyan
    CHSV(128, 255, 153),
    CHSV(128, 155, 178),

    // Light Blue
    CHSV(146, 238, 164),
    CHSV(146, 146, 187),

    // Blue/Purple
    CHSV(180, 226, 175),
    CHSV(180, 137, 195),

    // Violet
    CHSV(231, 255, 205),
    CHSV(231, 155, 217)
);


void randomSparklesPattern() {
    uint16_t pos = random16(NUM_LEDS);
    static uint8_t hue = 0;

    fadeToBlackBy(leds, NUM_LEDS, 32);
    leds[pos] += CHSV(random8(), DEFAULT_SAT, MAX_BRIGHTNESS);
    ++hue;
}

void setup() {
    FastLED.addLeds<NEOPIXEL, PIN>(leds, NUM_LEDS);
    FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
    randomSparklesPattern();
    FastLED.show();
    delay(100);
}
