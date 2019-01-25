/* ============================= RF Variables ===================================*/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10); // CE, CSN
const byte addresses[][6] = {"00001", "00002"};

/* ============================= Analog Mux Variables ===================================*/

#define Apin A1
#define Bpin A2
#define Cpin A3


/*======================== Totaliser ===============================*/
volatile int counter = 0;
uint32_t totaliserval = 0;


/*===================== MODBUS ============================*/
#include <ModbusMaster.h>
#include <SoftwareSerial.h>
#define MAX485_DE      6
#define MAX485_RE_NEG  6

ModbusMaster node1;
SoftwareSerial ss(5, 4); //RX 5 TX 4

void preTransmission()
{
  digitalWrite(MAX485_RE_NEG, HIGH);
  digitalWrite(MAX485_DE, HIGH);
}

void postTransmission()
{
  digitalWrite(MAX485_RE_NEG, LOW);
  digitalWrite(MAX485_DE, LOW);
}


int meterval1 = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  analogmuxsetup();
  pulsesetup();
  modbussetup();
  nrfsetup();
  
  
  
}

void loop() {
  decidewhat();
}
