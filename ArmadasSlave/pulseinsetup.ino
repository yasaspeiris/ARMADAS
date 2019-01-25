void pulsesetup() {
  pinMode(2, INPUT);
  attachInterrupt(digitalPinToInterrupt(3), count, RISING);
}


void count(){
  counter++;
}
