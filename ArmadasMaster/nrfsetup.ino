void nrfsetup() {
  radio.begin();
  radio.openWritingPipe(addresses[0]); // 00001
  radio.openReadingPipe(1, addresses[1]); // 00002
  radio.setPALevel(RF24_PA_MIN);
}


void requestvalue(char val) {

  for (int i = 0; i < 5; i++) {

    sendchar(val);
    for (int i = 0; i < 50; i++) {
      radio.startListening();
      if (radio.available()) {
        int rmessage;
        radio.read(&rmessage, sizeof(rmessage));
        if (val == 'a'){//flowrate
          //Serial.println(rmessage);
          val1 =rmessage; //pH
        }else if(val == 'b'){
          val2 =rmessage; //
        }else if(val == 'c'){//Chlorine
          val3 = rmessage;
        }else if(val == 'd'){//Conductivity
          val4 = rmessage;
        }else if(val == 'e'){//Totaliser
          val5 = rmessage;
        }else if(val == 'f'){//kWh
          val6 = rmessage;
        }
        break;
      }
    }
  }
}


void sendchar(char message) {

  radio.stopListening();
  radio.write(&message, sizeof(message));
  //Serial.println("SENT");

}
void sendvalue(int message) {

  radio.stopListening();
  radio.write(&message, sizeof(message));
  //Serial.println("SENT");
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
