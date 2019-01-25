void modbussetup() {
  pinMode(MAX485_RE_NEG, OUTPUT);
  pinMode(MAX485_DE, OUTPUT);
  // Init in receive mode
  digitalWrite(MAX485_RE_NEG, 0);
  digitalWrite(MAX485_DE, 0);

  ss.begin(9600);

  // Modbus slave ID 1
  node1.begin(5, ss);

  node1.preTransmission(preTransmission);
  node1.postTransmission(postTransmission);

  delay(1000);
}


float readpowermeter() {
  boolean flag = 0;
  uint8_t result;

  result = node1.readHoldingRegisters(0x0A8C, 2); //read 4 registers from 0x0000
  if (result == node1.ku8MBSuccess)
  {

        unsigned long high = node1.getResponseBuffer(0);
        unsigned long low = node1.getResponseBuffer(1);
        long int num = ((high << 16) | low);
        float wppval = *(float*)&num / 1000.00f;
        return wppval;
        
  } else {
    flag = 1;
  }
  node1.clearResponseBuffer();
}
