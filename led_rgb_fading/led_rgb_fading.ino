/*
  RGB Fading
  Make rgb red fade one by one
  using a table to change pwm to eye perceptible power

*/
//#include <avr/pgmspace.h>
//#include <math.h>

int red_pin = 3, green_pin = 5, blue_pin = 6;
int on = 0, off = 1;
int tempo = 200;
int  i;
const uint8_t table[] = {
  0, 1, 2, 3, 4, 5, 7, 9,
  12, 15, 18, 22, 27, 32, 38, 44,
  51, 58, 67, 76, 86, 96, 108, 120,
  134, 148, 163, 180, 197, 216, 235, 255
};

const uint8_t _ledTable[256] = {
  0,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
  1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
  1,   2,   2,   2,   2,   2,   2,   2,   2,   3,   3,   3,   3,   3,   4,   4,
  4,   4,   4,   5,   5,   5,   5,   6,   6,   6,   6,   7,   7,   7,   7,   8,
  8,   8,   9,   9,   9,  10,  10,  10,  11,  11,  12,  12,  12,  13,  13,  14,
  14,  15,  15,  15,  16,  16,  17,  17,  18,  18,  19,  19,  20,  20,  21,  22,
  22,  23,  23,  24,  25,  25,  26,  26,  27,  28,  28,  29,  30,  30,  31,  32,
  33,  33,  34,  35,  36,  36,  37,  38,  39,  40,  40,  41,  42,  43,  44,  45,
  46,  46,  47,  48,  49,  50,  51,  52,  53,  54,  55,  56,  57,  58,  59,  60,
  61,  62,  63,  64,  65,  67,  68,  69,  70,  71,  72,  73,  75,  76,  77,  78,
  80,  81,  82,  83,  85,  86,  87,  89,  90,  91,  93,  94,  95,  97,  98,  99,
  101, 102, 104, 105, 107, 108, 110, 111, 113, 114, 116, 117, 119, 121, 122, 124,
  125, 127, 129, 130, 132, 134, 135, 137, 139, 141, 142, 144, 146, 148, 150, 151,
  153, 155, 157, 159, 161, 163, 165, 166, 168, 170, 172, 174, 176, 178, 180, 182,
  184, 186, 189, 191, 193, 195, 197, 199, 201, 204, 206, 208, 210, 212, 215, 217,
  219, 221, 224, 226, 228, 231, 233, 235, 238, 240, 243, 245, 248, 250, 253, 255
};

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(red_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
  pinMode(blue_pin, OUTPUT);
  Serial.begin(9600);
  digitalWrite(blue_pin, off);
  digitalWrite(green_pin, off);
  digitalWrite(red_pin, off);
  Serial.println("Inicio");
}

// the loop function runs over and over again forever
void loop() {

  int rgb[] = {red_pin, green_pin, blue_pin};
  int j;

  for (j = 0; j < 3; j++) {
    // Serial.println("Sobe");
    for (i = 0; i <= 255; i++) {
      analogWrite(rgb[j], 255 - _ledTable[i]);
      Serial.println(_ledTable[i]);
      delay(30);
    }

    // Serial.println("Desce");
    for (i = 255; i >= 0; i--) {
      analogWrite(rgb[j], 255 - _ledTable[i]);
      Serial.println(_ledTable[i]);
      delay(30);
      //Serial.println(i);
    }
  }


}


//    for (i = 255; i >= 0; i--) {
//    analogWrite(red_pin, 255-(int)&br[i]);
//    delay(30);
//  }

//  for (i = 0; i < 32; i++) {
//    analogWrite(red_pin, 255 - table[i]);
//    Serial.println(table[i]);
//    delay(tempo);
//  }
//  for (i = 31; i >= 0; i--) {
//    analogWrite(red_pin, 255 - table[i]);
//    Serial.println(table[i]);
//    delay(tempo);
//  }
//  delay(1000);


//
// // digitalWrite(red_pin, on);
//  analogWrite(red_pin,200);
//  delay(tempo);
//
//  digitalWrite(red_pin, off);
//  digitalWrite(green_pin, on);
//  delay(tempo);
//
//  digitalWrite(green_pin, off);
//  digitalWrite(blue_pin, on);
//  delay(tempo);



