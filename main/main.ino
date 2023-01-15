#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

// PUSHBUTTON
int PB_NAND = A0;
int PB_AND = A1;
int PB_OR = A2;
int PB_NOR = A3;

// INPUT IC AND OR NAND
int IN1 = 0;
int IN2 = 1;

// OUTPUT IC AND OR NAND
int GATE1 = 2;
int GATE2 = 3;
int GATE3 = 4;
int GATE4 = 5;

// INPUT IC NOR
int IN1_NOR = 6;
int IN2_NOR = 7;

// OUTPUT IC NOR
int GATE1_NOR = 8;
int GATE2_NOR = 9;
int GATE3_NOR = 10;
int GATE4_NOR = 11;

int BUZZ_1 = 12;
int LED_1 = 13;

int a = 0;
int b = 0;
int c = 0;
int d = 0;

void setup(){
  lcd.init();
  //lcd.begin();
  //Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(IN1_NOR, OUTPUT);
  pinMode(IN2_NOR, OUTPUT);

  pinMode(GATE1, INPUT);
  pinMode(GATE2, INPUT);
  pinMode(GATE3, INPUT);
  pinMode(GATE4, INPUT);

  pinMode(GATE1_NOR, INPUT);
  pinMode(GATE2_NOR, INPUT);
  pinMode(GATE3_NOR, INPUT);
  pinMode(GATE4_NOR, INPUT);

  pinMode(PB_NAND, INPUT_PULLUP);
  pinMode(PB_AND, INPUT_PULLUP);
  pinMode(PB_OR, INPUT_PULLUP);

  pinMode(PB_NOR, INPUT_PULLUP);

  pinMode(BUZZ_1, OUTPUT);

}

void loop(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN1_NOR, HIGH);
  digitalWrite(IN2_NOR, HIGH);
  lcd.setCursor(00, 00);
  lcd.print("IC TESTER");;

  lcd.setCursor(0, 1); 
  lcd.print("PRESS THE BUTTON");

  if (digitalRead(PB_NAND) == LOW) {
    Serial.println("IC 7400 NAND");
    NAND();
  }

  if (digitalRead(PB_AND) == LOW) {
    Serial.println("IC 7408 AND");
    AND();
  }

  if (digitalRead(PB_NOR) == LOW) {
    Serial.println("IC 7402 NOR");
    NOR();
  }

  if (digitalRead(PB_OR) == LOW) {
    Serial.println("IC 7432 OR");
    OR();
  }
}
