void NOR() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("IC 7402 NOR");


  /*============= 0 0 ==============*/
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  //GATE1
  if (digitalRead(GATE1_NOR) == HIGH) {
    a = a + 1 ;
    
  }


  //GATE2
  if (digitalRead(GATE2_NOR) == HIGH) {
    b = b + 1 ;
    
  }


  //GATE3
  if (digitalRead(GATE3_NOR) == HIGH) {
    c = c + 1 ;
    
  }


  //GATE4
  if (digitalRead(GATE4_NOR) == HIGH) {
    d = d + 1 ;
    
  }

  
  delay(1000);


  /*============= 0 1 ==============*/
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  //GATE1
  if (digitalRead(GATE1_NOR) == LOW) {
    a = a + 1;
    
  }


  //GATE2
  if (digitalRead(GATE2_NOR) == LOW) {
    b = b + 1 ;
    
  }


  //GATE3
  if (digitalRead(GATE3_NOR) == LOW) {
    c = c + 1 ;
    
  }


  //GATE4
  if (digitalRead(GATE4_NOR) == LOW) {

    d = d + 1 ;
    
  }

  
  delay(1000);


  /*============= 1 0 ==============*/
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  //GATE1
  if (digitalRead(GATE1_NOR) == LOW) {
    a = a + 1 ;
    
  }

  //GATE2
  if (digitalRead(GATE2_NOR) == LOW) {
    b = b + 1 ;
    
  }


  //GATE3
  if (digitalRead(GATE3_NOR) == LOW) {
    c = c + 1 ;
    
  }

  //GATE4
  if (digitalRead(GATE4_NOR) == LOW) {
    d = d + 1 ;
    
  }

  delay(1000);


  /*============= 1 1 ==============*/
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);

  //GATE1
  if (digitalRead(GATE1_NOR) == LOW) {
    a = a + 1;
    
  }


  //GATE2
  if (digitalRead(GATE2_NOR) == LOW) {
    b = b + 1 ;
    
  }


  //GATE3
  if (digitalRead(GATE3_NOR) == LOW) {
    c = c + 1 ;
    
  }

  //GATE4
  if (digitalRead(GATE4_NOR) == LOW) {
    d = d + 1 ;
    
  }

  
  delay(1000);


  /*========  KONDISI GATE =========*/
  if (a == 4) {
    lcd.setCursor(0, 1);
    lcd.print("GATE 1 GOOD");
  }
  else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("IC 7402 NOR!");
    lcd.setCursor(0, 1);
    lcd.print("GATE 1 BAD");
  }
  delay(2000);

  if (b == 4) {
    lcd.setCursor(0, 1);
    lcd.print("GATE 2 GOOD");
  }
  else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("IC 7402 NOR!");
    lcd.setCursor(0, 1);
    lcd.print("GATE 2 BAD");
  }
  delay(2000);

  if (c == 4) {
    lcd.setCursor(0, 1);
    lcd.print("GATE 3 GOOD");
  }
  else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("IC 7402 NOR!");
    lcd.setCursor(0, 1);
    lcd.print("GATE 3 BAD");
    e = 1;
  }
  delay(2000);

  if (d == 4) {
    lcd.setCursor(0, 1);
    lcd.print("GATE 4 GOOD");
  }
  else {
    lcd.clear();
    lcd.setCursor(00, 00);
    lcd.print("IC 7402 NOR!");
    lcd.setCursor(00, 1);
    lcd.print("GATE 4 BAD");
  }
  delay(2000);
  lcd.clear();

  if (a == 4 && b == 4 && c == 4 && d == 4 ) {
    lcd.setCursor(0, 0);
    lcd.print("IC 7402 NOR!");
    lcd.setCursor(0, 1);
    lcd.print("IC GOOD");


    digitalWrite(LED_HIJAU, HIGH);
    digitalWrite(BUZZER, HIGH);
    delay(200);
    digitalWrite(BUZZER, LOW);
    delay(200);
    digitalWrite(BUZZER, HIGH);
    delay(200);
    digitalWrite(BUZZER, LOW);
    delay(200);
    digitalWrite(BUZZER, HIGH);
    delay(200);
    digitalWrite(BUZZER, LOW);
    delay(200);
    digitalWrite(BUZZER, HIGH);
    delay(200);
    digitalWrite(BUZZER, LOW);
    delay(200);

    /*======== EEPROM COUNTER ========*/
    cnt_nor = cnt_nor + 1;
    data_4 = cnt_nor;
    EEPROM.write(address_4, data_4);
  }
  else {
    lcd.setCursor(0, 0);
    lcd.print("IC 7402 NOR!");
    lcd.setCursor(0, 1);
    lcd.print("IC BAD");

    digitalWrite(LED_MERAH, HIGH);
    digitalWrite(BUZZER, HIGH);
    delay(2000);
    digitalWrite(BUZZER, LOW);
  }

  if (e == 1 ) {
    lcd.clear();
    lcd.print("IC 7402 NOR!");
    lcd.setCursor(0, 1);
    lcd.print("GATE 3 BAD");
  }

  /*============ COUNTER ===========*/
  if (cnt_nor == 5 ) {
    lcd.clear();
    lcd.print("IC 7402 NOR!");
    lcd.setCursor(0, 1);
    lcd.print("IC PASSED");
  }

  delay(2000);
  lcd.clear();

  /*============ EEPROM ============*/
  val_4 = EEPROM.read(address_4);
  lcd.setCursor(0, 0);
  lcd.print("TEST 7402 PASSED");
  lcd.setCursor(0, 1);
  lcd.print("IC TEST  ");
  lcd.print(val_4);

  a = 0;
  b = 0;
  c = 0;
  d = 0;
  delay(2000);
  lcd.clear();
  digitalWrite(BUZZER, LOW);
  digitalWrite(LED_MERAH, LOW);
  digitalWrite(LED_HIJAU, LOW);
  
}
