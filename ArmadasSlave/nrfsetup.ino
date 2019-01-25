void nrfsetup() {
  radio.begin();
  radio.openWritingPipe(addresses[1]); // 00001
  radio.openReadingPipe(1, addresses[0]); // 00002
  radio.setPALevel(RF24_PA_MAX);
}




void decidewhat() {
  char rmessage = ' ';
  while (1) {
    radio.startListening();
    if (radio.available()) {
      radio.read(&rmessage, sizeof(rmessage));
      Serial.println(rmessage);
      break;
    }

  }

  if (rmessage == 'a') {//ph
    delay(5);
    sendvalue(selectanaloginput(1));
  } else if (rmessage == 'b') {//chlorine
    delay(5);
    sendvalue(selectanaloginput(2));
  } else if (rmessage == 'c') {//cond
    delay(5);
    sendvalue(selectanaloginput(3));
  } else if (rmessage == 'd') {//flowrate
    delay(5);
    sendvalue(selectanaloginput(5));
  }else if (rmessage == 'e') {
    delay(5);
    //totaliserval = counter;
    sendvalue(counter);
  }else if (rmessage == 'f') {
    delay(5);
    sendvalue(readpowermeter());
  }


}

int selectanaloginput(int x) {
  if (x == 1) {
    digitalWrite(Apin, LOW);
    digitalWrite(Bpin, LOW);
    digitalWrite(Cpin, LOW);
    delay(5);
    return analogRead(A0);

  } else if (x == 2 ) {
    digitalWrite(Apin, HIGH);
    digitalWrite(Bpin, LOW);
    digitalWrite(Cpin, LOW);
    delay(5);
    return analogRead(A0);


  } else if (x == 3) {
    digitalWrite(Apin, LOW);
    digitalWrite(Bpin, HIGH);
    digitalWrite(Cpin, LOW);
    delay(5);
    return analogRead(A0);

  }
  else if (x == 4) {
    digitalWrite(Apin, HIGH);
    digitalWrite(Bpin, HIGH);
    digitalWrite(Cpin, LOW);
    delay(5);
    return analogRead(A0);


  } else if (x == 5 ) {
    digitalWrite(Apin, LOW);
    digitalWrite(Bpin, LOW);
    digitalWrite(Cpin, HIGH);
    delay(5);
    return analogRead(A0);


  } else if (x == 6 ) {
    digitalWrite(Apin, HIGH);
    digitalWrite(Bpin, LOW);
    digitalWrite(Cpin, HIGH);
    delay(5);
    return analogRead(A0);


  } else if (x == 7) {
    digitalWrite(Apin, LOW);
    digitalWrite(Bpin, HIGH);
    digitalWrite(Cpin, HIGH);
    delay(5);
    return analogRead(A0);


  } else if (x == 8) {
    digitalWrite(Apin, HIGH);
    digitalWrite(Bpin, HIGH);
    digitalWrite(Cpin, HIGH);
    delay(5); 
    return analogRead(A0);

  }
}


void sendvalue(int message) {

  radio.stopListening();
  radio.write(&message, sizeof(message));
  Serial.println("SENT");
  //delay(100);

}

void waitforack() {

  while (1) {
    radio.startListening();
    if (radio.available()) {
      char rmessage;
      radio.read(&rmessage, sizeof(rmessage));
      Serial.println(rmessage);
      break;
    }

  }
}
