#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);


int e,f,g,h;
/*============ COUNTER ===========*/
int cnt_and;
int cnt_or;
int cnt_nand;
int cnt_nor =0;

/*============ EEPROM ============*/
int address_1 = 0;
int address_2 = 0;
int address_3 = 0;
int address_4 = 0;

/*========= VALUE DATA =========*/
int data_1;
int data_2;
int data_3;
int data_4;

/*========= VALUE EEPROM =========*/
int val_1;
int val_2;
int val_3;
int val_4;

/*========== PUSHBUTTON ==========*/
int PB_AND = A0;
int PB_OR = A1;
int PB_NAND = A2;
int PB_NOR = A3;
int PB_RESET = 13;
/*============ INPUT =============*/
int IN1 = 0;
int IN2 = 1;

/*============ OUTPUT ============*/
//AND, OR, NAND
int GATE1 = 2;
int GATE2 = 3;
int GATE3 = 4;
int GATE4 = 5;
//NOR
int GATE1_NOR = 6;
int GATE2_NOR = 7;
int GATE3_NOR = 8;
int GATE4_NOR = 9;
//BUZZER, LED
int BUZZER = 10;
int LED_MERAH = 11;
int LED_HIJAU = 12;

/*============ COUNTER GATE ============*/
int a = 0;
int b = 0;
int c = 0;
int d = 0;

void AND();
void NAND();
void OR();
void NOR();
void readEEPROM();

void setup() {
  lcd.begin();

  pinMode(PB_AND, INPUT_PULLUP);
  pinMode(PB_OR, INPUT_PULLUP);
  pinMode(PB_NAND, INPUT_PULLUP);
  pinMode(PB_NOR, INPUT_PULLUP);
  pinMode(PB_RESET, INPUT_PULLUP);

  pinMode(GATE1, INPUT);
  pinMode(GATE2, INPUT);
  pinMode(GATE3, INPUT);
  pinMode(GATE4, INPUT);
  pinMode(GATE1_NOR, INPUT);
  pinMode(GATE2_NOR, INPUT);
  pinMode(GATE3_NOR, INPUT);
  pinMode(GATE4_NOR, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(LED_MERAH, OUTPUT);
  pinMode(LED_HIJAU, OUTPUT);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW); 
  
  readEEPROM();
  //val_4 = EEPROM.read(address_4);
 // cnt_nor = val_4;
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("IC TESTER");
  lcd.setCursor(0, 1);
  lcd.print("PRESS THE BUTTON");

  if (digitalRead(PB_AND) == LOW) {
    AND();
  }
  if (digitalRead(PB_OR) == LOW) {
    OR();
  }
  if (digitalRead(PB_NAND) == LOW) {
    NAND();
  }
  if (digitalRead(PB_NOR) == LOW) {
    NOR();
  }
  if (digitalRead(PB_RESET) == LOW) {
    cnt_nor = 0;
    digitalWrite(BUZZER, HIGH);
    delay(200);
    digitalWrite(BUZZER, LOW);
    delay(200);
  }
}
