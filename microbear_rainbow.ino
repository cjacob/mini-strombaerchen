// LED-Funktionen werden mit Hilfe der Bibliothek "FastLED" programmiert.
// Um diese zu nutzen fügen wir sie hier hinzu:
#include "FastLED.h"

//FastLED Basics
#define DATA_PIN    4  // unserer "Data In" Pin ist an Pin 4 angeschlossen
#define LED_TYPE    WS2812B // Der Typ unserer LEDs
#define COLOR_ORDER RGB // brauchen wir nicht, bei manchen Chips muss man die Reihenfolge ändern
#define NUM_LEDS    3 // Falls jemand 3 LEDs hat. Geht auch mit einer
CRGB leds[NUM_LEDS];

#define BRIGHTNESS          255 // Helligkeit festlegen
#define FRAMES_PER_SECOND  120

//Festlegen der Farbe und Anzahl des Blinkens
//Für unsere "Blink"-Funkion weiter unten
int color = 233; // zwischen 0 und 255
int count = 5; // Anzahl Blinken
int pause = 300; // Pause in Millisekunden

//Diese Funktion wird einmal beim Start ausgeführt
void setup() {
  //Hier werden Funktionen der LED-Bibliothek initialisiert
  pinMode(BUILTIN_LED, OUTPUT);
  //FastLED Set Up tell FastLED about the LED strip configuration
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  // Helligkeit festlegen
  FastLED.setBrightness(BRIGHTNESS);
}

//Diese Funktion wird anschließend in Dauerschleife ausgeführt
//Bei uns wird abwechselnd ein Regenbogen und ein Blinken angezeigt
void loop() {
  //Regenbogen
  for( int i = 0; i < 254; i++) {
    leds[0] = CHSV( i, 255, 255);
    leds[1] = CHSV( i, 255, 255);
    leds[2] = CHSV( i, 255, 255);
    FastLED.show();
    delay(20);
  }
  
  delay(300);
  
  //Blinken in gewählter Farbe
  for (int i=0; i < count; i++) {
    leds[0] = CHSV( color, 255, 255);
    leds[1] = CHSV( color, 255, 255);
    leds[2] = CHSV( color, 255, 255);
    FastLED.show();
    delay(pause);
    leds[0] = CHSV( color, 255, 0);
    leds[1] = CHSV( color, 255, 0);
    leds[2] = CHSV( color, 255, 0);
    FastLED.show();
    delay(pause);
  }

  // Wer nur den Regenbogen, nur Blinken oder nur eine Farbe haben möchte, kann den Code entsprechen anpassen.
  /*
   So können größere Teile des Codes auskommentiert werden
   */
  
  // Zur Info:
  //      Farbe,  Sättigung, Helligkeit
  //CHSV( color,  255,       0);
}
