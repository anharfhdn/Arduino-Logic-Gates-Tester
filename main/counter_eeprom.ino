void readEEPROM() {
  val_4 = EEPROM.read(address_4);
  cnt_nor = val_4;
}
