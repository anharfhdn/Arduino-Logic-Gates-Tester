void OR() {
  lcd.clear();
  lcd.setCursor(00, 00);
  lcd.print("IC 7432 OR!");

  ////////////////////////// 0 0
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  //GATE1
  if (digitalRead(GATE1) == LOW) {
    Serial.println("0 0 = 1, GATE 1 IS OK");
    a = a + 1 ;
    Serial.println(a);
  } else {
    Serial.println("GATE 1 NOT OK");
  }

  delay(1000);

  //GATE2
  if (digitalRead(GATE2) == LOW) {
    Serial.println("0 0 = 1, GATE 2 IS OK");
    b = b + 1 ;
    Serial.println(b);
  } else {
    Serial.println("GATE 2 NOT OK");
  }

  //GATE3
  if (digitalRead(GATE3) == LOW) {
    Serial.println("0 0 = 1, GATE 3 IS OK");
    c = c + 1 ;
    Serial.println(c);
  } else {
    Serial.println("GATE 3 NOT OK");
  }

  //GATE4
  if (digitalRead(GATE4) == LOW) {
    Serial.println("0 0 = 1, GATE 4 IS OK");
    d = d + 1 ;
    Serial.println(d);
  } else {
    Serial.println("GATE 1 NOT OK");
  }

  Serial.println("\n");
  delay(1000);

  /////////////////////////////// 0 1
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  //GATE1
  if (digitalRead(GATE1) == HIGH) {
    Serial.println("0 1 = 1, GATE 1 IS OK");
    a = a + 1;
    Serial.println(a);
  } else {
    Serial.println("GATE 1 NOT OK");
  }

  //GATE2
  if (digitalRead(GATE2) == HIGH) {
    Serial.println("0 1 = 1, GATE 2 IS OK");
    b = b + 1 ;
    Serial.println(b);
  } else {
    Serial.println("GATE 2 NOT OK");
  }

  //GATE3
  if (digitalRead(GATE3) == HIGH) {
    Serial.println("0 1 = 1, GATE 3 IS OK");
    c = c + 1 ;
    Serial.println(c);
  } else {
    Serial.println("GATE 3 NOT OK");
  }

  //GATE4
  if (digitalRead(GATE4) == HIGH) {
    Serial.println("0 1 = 1, GATE 4 IS OK");
    d = d + 1 ;
    Serial.println(d);
  } else {
    Serial.println("GATE 1 NOT OK");
  }

  Serial.println("\n");
  delay(1000);

  ////////////////////// 1 0
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  //GATE1
  if (digitalRead(GATE1) == HIGH) {
    Serial.println("1 0 = 1, GATE 1 IS OK");
    a = a + 1 ;
    Serial.println(a);
  } else {
    Serial.println("GATE 1 NOT OK");
  }

  //GATE2
  if (digitalRead(GATE2) == HIGH) {
    Serial.println("1 0 = 1, GATE 2 IS OK");
    b = b + 1 ;
    Serial.println(b);
  } else {
    Serial.println("GATE 2 NOT OK");
  }

  //GATE3
  if (digitalRead(GATE3) == HIGH) {
    Serial.println("1 0 = 1, GATE 3 IS OK");
    c = c + 1 ;
    Serial.println(c);
  } else {
    Serial.println("GATE 3 NOT OK");
  }

  //GATE4
  if (digitalRead(GATE4) == HIGH) {
    Serial.println("1 0 = 1, GATE 4 IS OK");
    d = d + 1 ;
    Serial.println(d);
  } else {
    Serial.println("GATE 1 NOT OK");
  }

  Serial.println("\n");
  delay(1000);

  //////////////////////////// 1 1
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);

  //GATE1
  if (digitalRead(GATE1) == HIGH) {
    Serial.println("1 1 = 0, GATE 1 IS OK");
    a = a + 1;
    Serial.println(a);
  } else {
    Serial.println("GATE 1 NOT OK");
  }

  //GATE2
  if (digitalRead(GATE2) == HIGH) {
    Serial.println("1 1 = 0, GATE 2 IS OK");
    b = b + 1 ;
    Serial.println(b);
  } else {
    Serial.println("GATE 2 NOT OK");
  }

  //GATE3
  if (digitalRead(GATE3) == HIGH) {
    Serial.println("1 1 = 0, GATE 3 IS OK");
    c = c + 1 ;
    Serial.println(b);
  } else {
    Serial.println("GATE 3 NOT OK");
  }

  //GATE4
  if (digitalRead(GATE4) == HIGH) {
    Serial.println("1 1 = 0, GATE 4 IS OK");
    d = d + 1 ;
    Serial.println(b);
  } else {
    Serial.println("GATE 4 NOT OK");
  }

  Serial.println("\n");
  delay(1000);

  /////////////////////////////////////////////////////////
  if (a == 4) {
    Serial.println("GATE 1 PERFECT");
    lcd.setCursor(00, 1);
    lcd.print("GATE 1 GOOD");
  } else {
    Serial.println("GATE 1 BAD");

    lcd.clear();
    lcd.setCursor(00, 00);
    lcd.print("IC 7432 OR!");
    lcd.setCursor(00, 1);
    lcd.print("GATE 1 BAD");
  }

  delay(1000);

  if (b == 4) {
    Serial.println("GATE 2 PERFECT");
    lcd.setCursor(00, 1);
    lcd.print("GATE 2 GOOD");
  } else {
    Serial.println("GATE 2 BAD");

    lcd.clear();
    lcd.setCursor(00, 00);
    lcd.print("IC 7432 OR!");
    lcd.setCursor(00, 1);
    lcd.print("GATE 2 BAD");
  }

  delay(1000);

  if (c == 4) {
    Serial.println("GATE 3 PERFECT");
    lcd.setCursor(00, 1);
    lcd.print("GATE 3 GOOD");
  } else {
    Serial.println("GATE 3 BAD");

    lcd.clear();
    lcd.setCursor(00, 00);
    lcd.print("IC 7432 OR!");
    lcd.setCursor(00, 1);
    lcd.print("GATE 3 BAD");
  }

  delay(1000);
  //lcd.clear();

  if (d == 4) {
    Serial.println("GATE 4 PERFECT");
    lcd.setCursor(00, 1);
    lcd.print("GATE 4 GOOD");
    lcd.setCursor(00, 00);
    lcd.print("IC 7432 OR!");
  } else {
    Serial.println("GATE 4 BAD");

    lcd.clear();
    lcd.setCursor(00, 00);
    lcd.print("IC 7432 OR!");
    lcd.setCursor(00, 1);
    lcd.print("GATE 4 BAD");
  }

  delay(1000);
  lcd.clear();

  if (a == 4 && b == 4 && c == 4 && d == 4 ) {
    lcd.setCursor(00, 00);
    lcd.print("IC 7432 OR!");

    lcd.setCursor(00, 1);
    lcd.print("IC GOOD");

    Serial.println("IC PERFECT");
    digitalWrite(BUZZ_1, HIGH);
  } else {
    digitalWrite(LED_1, HIGH);
    Serial.println("IC BAD");

    lcd.setCursor(00, 00);
    lcd.print("IC 7432 OR!");

    lcd.setCursor(00, 1);
    lcd.print("IC BAD");
  }

  delay(3000);
  a = 0;
  b = 0;
  c = 0;
  d = 0;
  lcd.clear();
  digitalWrite(BUZZ_1, LOW);
  digitalWrite(LED_1, LOW);
  Serial.println("\n");
}
