void OR() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("IC 7432 OR!");


  /*============= 0 0 ==============*/
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  //GATE1
  if (digitalRead(GATE1) == LOW) {
    a = a + 1 ;
    
  }

  //GATE2
  if (digitalRead(GATE2) == LOW) {
    b = b + 1 ;
    
  }


  //GATE3
  if (digitalRead(GATE3) == LOW) {
    c = c + 1 ;
    
  }


  //GATE4
  if (digitalRead(GATE4) == LOW) {
    d = d + 1 ;
    
  }

  
  delay(1000);


  /*============= 0 1 ==============*/
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  //GATE1
  if (digitalRead(GATE1) == HIGH) {
    a = a + 1;
    
  }


  //GATE2
  if (digitalRead(GATE2) == HIGH) {
    b = b + 1 ;
    
  }

  //GATE3
  if (digitalRead(GATE3) == HIGH) {
    c = c + 1 ;
    
  }

  //GATE4
  if (digitalRead(GATE4) == HIGH) {
    d = d + 1 ;
    
  }

  
  delay(1000);


  /*============= 1 0 ==============*/
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  //GATE1
  if (digitalRead(GATE1) == HIGH) {
    a = a + 1 ;
    
  }


  //GATE2
  if (digitalRead(GATE2) == HIGH) {
    b = b + 1 ;
    
  }

  //GATE3
  if (digitalRead(GATE3) == HIGH) {
    c = c + 1 ;
    
  }

  //GATE4
  if (digitalRead(GATE4) == HIGH) {
    d = d + 1 ;
    
  }
  
  delay(1000);


  /*============= 1 1 ==============*/
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);

  //GATE1
  if (digitalRead(GATE1) == HIGH) {
    a = a + 1;
    
  }

  //GATE2
  if (digitalRead(GATE2) == HIGH) {
    b = b + 1 ;
    
  }


  //GATE3
  if (digitalRead(GATE3) == HIGH) {
    c = c + 1 ;
    
  }

  //GATE4
  if (digitalRead(GATE4) == HIGH) {
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
    lcd.print("IC 7432 OR!");
    lcd.setCursor(0, 1);
    lcd.print("GATE 1 BAD");
  }
  delay(1000);

  if (b == 4) {
    lcd.setCursor(0, 1);
    lcd.print("GATE 2 GOOD");
  }
  else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("IC 7432 OR!");
    lcd.setCursor(0, 1);
    lcd.print("GATE 2 BAD");
  }
  delay(1000);

  if (c == 4) {
    lcd.setCursor(0, 1);
    lcd.print("GATE 3 GOOD");
  }
  else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("IC 7432 OR!");
    lcd.setCursor(0, 1);
    lcd.print("GATE 3 BAD");
  }
  delay(1000);

  if (d == 4) {
    lcd.setCursor(0, 1);
    lcd.print("GATE 4 GOOD");
  }
  else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("IC 7432 OR!");
    lcd.setCursor(0, 1);
    lcd.print("GATE 4 BAD");
  }
  delay(1000);
  lcd.clear();

  if (a == 4 && b == 4 && c == 4 && d == 4 ) {
    lcd.setCursor(0, 0);
    lcd.print("IC 7432 OR!");
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
    cnt_or = cnt_or + 1;
    EEPROM.write(address_2, cnt_or);
  }
  else {
    digitalWrite(LED_MERAH, HIGH);
    digitalWrite(BUZZER, HIGH);
    delay(2000);
    digitalWrite(BUZZER, LOW);

    lcd.setCursor(0, 0);
    lcd.print("IC 7432 OR!");
    lcd.setCursor(0, 1);
    lcd.print("IC BAD");
    Serial.println("IC BAD");
  }

  /*============ COUNTER ===========*/
  if (cnt_or == 100 ) {
    lcd.clear();
    lcd.print("IC 7432 AND!");
    lcd.setCursor(0, 1);
    lcd.print("IC PASSED");
  }

  delay(3000);
  lcd.clear();

  /*============ EEPROM ============*/
  val_2 = EEPROM.read(address_2);
  lcd.setCursor(0, 0);
  lcd.print("TEST 7432 PASSED");
  lcd.setCursor(0, 1);
  lcd.print("IC TEST");
  lcd.print(val_2);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  lcd.clear();
  digitalWrite(BUZZER, LOW);
  digitalWrite(LED_MERAH, LOW);
  digitalWrite(LED_HIJAU, LOW);
  
}
