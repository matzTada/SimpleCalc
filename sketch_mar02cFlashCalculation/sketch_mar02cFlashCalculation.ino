/*
 * Simple Calculator (Imcomplete)
 * 4x4 Matrix Keypad connected to Arduino
  This code prints the key pressed on the keypad to the serial port

  Check GitHub(https://github.com/matzTada/SimpleCalc) for further information.

  references
  http://playground.arduino.cc/Code/Keypad
  http://www.learningaboutelectronics.com/Articles/Arduino-keypad-circuit.php

  http://img.hqew.com/File/Images/250000-259999/251308/Electronic/2012816113627928480.jpg
  http://garretlab.web.fc2.com/arduino/introduction/beginning_with_7segment_led/

  2017/3/19 modified by TadaMatz
*/

#include <Keypad.h>

const byte numRows = 4; //number of rows on the keypad
const byte numCols = 4; //number of columns on the keypad

//keymap defines the key pressed according to the row and columns just as appears on the keypad
char keymap[numRows][numCols] =
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

//Code that shows the the keypad connections to the arduino terminals
byte rowPins[numRows] = {0, 1, 19, 18}; //from LEFT Rows 0 to 3
byte colPins[numCols] = {17, 16, 15, 14}; //Columns 0 to 3

//initializes an instance of the Keypad class
Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);


//============================7seg4digits
const int cathode_pins[] = {12, 8, 5, 3, 2, 11, 6};    // {1,2,3,4,5,6,7}th from LEFT (a,b,c,d,e,f,g,df) アノードに接続するArduinoのピン
const int anode_pins [] = {7, 9, 10, 13};  // {1, 2, 3, 4}th from RIGHT (dig4, dig3, dig2, dig1) カソードに接続するArduinoのピン
const int number_of_cathode_pins = sizeof(cathode_pins) / sizeof(cathode_pins[0]);
const int number_of_anode_pins = sizeof(anode_pins) / sizeof(anode_pins[0]);

const int digits[] = {
  0b00111111, // 0
  0b00000110, // 1
  0b01011011, // 2
  0b01001111, // 3
  0b01100110, // 4
  0b01101101, // 5
  0b01111101, // 6
  0b00100111, // 7
  0b01111111, // 8
  0b01101111, // 9
};

// 数字(n)を表示する
void display_number (int n) {
  for (int i = 0; i < number_of_cathode_pins; i++) {
    digitalWrite(cathode_pins[i], digits[n] & (1 << i) ? LOW : HIGH);
  }
}

void clear_segments() {
  for (int j = 0; j < number_of_cathode_pins; j++) {
    digitalWrite(cathode_pins[j], HIGH);
  }
}

void display_numbers (int n) {
  for (int i = 0; i < number_of_anode_pins; i++) {
    digitalWrite(anode_pins[i], HIGH);
    display_number(n % 10); // 最後の一桁を表示する
    delay(1);
    clear_segments();
    digitalWrite(anode_pins[i], LOW);
    n = n / 10; // 10で割る
  }
}

int num = 0;
String currentStr = "0000";
int operand = 0;
char ope = ' ';

void setup()
{
  //Serial.begin(9600);

  //============================7seg4digits
  for (int i = 0; i < number_of_cathode_pins; i++) {
    pinMode(cathode_pins[i], OUTPUT);  // cathode_pinsを出力モードに設定する
  }
  for (int i = 0; i < number_of_anode_pins; i++) {
    pinMode(anode_pins[i], OUTPUT);  // anode_pinsを出力モードに設定する
    digitalWrite(anode_pins[i], LOW);
  }
}

//If key is pressed, this key is stored in 'keypressed' variable
//If key is not equal to 'NO_KEY', then this key is printed out
//if count=17, then count is reset back to 0 (this means no key is pressed during the whole keypad scan process
void loop()
{
  char keypressed = myKeypad.getKey();
  if (keypressed != NO_KEY)
  {
    if ('0' <= keypressed && keypressed <= '9') {
      currentStr += keypressed;
      num = currentStr.substring(currentStr.length() - 4, currentStr.length()).toInt();
    }
    else {
      switch (keypressed) {
        case 'A':
          operand = num;
          ope = '+';
          break;
        case 'B':
          operand = num;
          ope = '-';
          break;
        case 'C':
          operand = num;
          ope = '*';
          break;
        case 'D':
          operand = num;
          ope = '/';
          break;
        case '#':
          switch (ope) {
            case '+':
              num = operand + num;
              break;
            case '-':
              num = operand - num;
              break;
            case '*':
              num = operand * num;
              break;
            case '/':
              num = operand / num;
              break;
            default:
              break;
          }
          break;
        case '*':
          num = 0;
          operand = 0;
          break;
      }
      currentStr = "0000";
    }
    //    Serial.print(keypressed);
  }
  display_numbers(num);
}
