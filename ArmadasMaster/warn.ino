void warn(){
  if(val1 > 900){
    error = Sim800l.sendSms(number, "WARNING");
  }
}
