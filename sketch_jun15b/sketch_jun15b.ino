/*
  Change brightness of LED linearly to Human eye
  32 step brightness using 8 bit PWM of Arduino
  brightness step 24 should be twice bright than step 12 to your eye.
*/

//#include <avr/pgmspace.h>
//#define CIELPWM(a) (pgm_read_word_near(CIEL8 + a)) // CIE Lightness loopup table function

/*
  5 bit CIE Lightness to 8 bit PWM conversion
  L* = 116(Y/Yn)^1/3 - 16 , Y/Yn > 0.008856
  L* = 903.3(Y/Yn), Y/Yn <= 0.008856
*/

const int table[] = {
  0,    1,    2,    3,    4,    5,    7,    9,    12,
  15,    18,    22,    27,    32,    38,    44,    51,    58,
  67,    76,    86,    96,    108,    120,    134,    148,    163,
  180,    197,    216,    235,    255
};

int brightness = 0;    // initial brightness of LED
int fadeAmount = 1;

void setup()  {
  // declare pin 9 to be an output:
  pinMode(6, OUTPUT);
}

void loop()  {
  // set the brightness of pin 9:, 0-31, 5 bit steps of brightness
  analogWrite(6, CIELPWM(brightness));

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness == 0 || brightness == 31) {
    fadeAmount = -fadeAmount ;
  }
  // wait for 500 milliseconds to see the bightness change
  delay(500);
}
