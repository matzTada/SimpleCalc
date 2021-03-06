/*

  Check GitHub(https://github.com/matzTada/SimpleCalc) for further information.

  references
  http://img.hqew.com/File/Images/250000-259999/251308/Electronic/2012816113627928480.jpg
  http://garretlab.web.fc2.com/arduino/introduction/beginning_with_7segment_led/

  2017/3/19 modified by TadaMatz
*/

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

// setup()　は、最初に一度だけ実行される
void setup() {
  for (int i = 0; i < number_of_cathode_pins; i++) {
    pinMode(cathode_pins[i], OUTPUT);  // cathode_pinsを出力モードに設定する
  }
  for (int i = 0; i < number_of_anode_pins; i++) {
    pinMode(anode_pins[i], OUTPUT);  // anode_pinsを出力モードに設定する
    digitalWrite(anode_pins[i], LOW);
  }
}

void loop () {
  for (int i = 0; i < 10000; i++) {
    for (int j = 0; j < 100; j++) {
      display_numbers(i);
    }
  }
}
