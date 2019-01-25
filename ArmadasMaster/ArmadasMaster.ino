/*======================= RF Variables ======================*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(15, 14); // CE, CSN
const byte addresses[][6] = {"00001", "00002"};

/*===================== Values ========================*/

int val1, val2, val3, val4, val5, val6, val7, val8 = 0;

/*=========================== SIM800L =======================*/
#include <Sim800l.h>
#include <SoftwareSerial.h> //is necesary for the library!! 
Sim800l Sim800l;  //to declare the library
String textSms, numberSms,MyString;
char* text;
char* number = "0773357892";
uint8_t index1;
bool error;




/*======================= Totaliser =======================*/
volatile int counter = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //sim800setup();
  nrfsetup();
}

void loop() {
  master_request();
  //checkforsmsreq();
  sendtopc();
  //warn();
}
