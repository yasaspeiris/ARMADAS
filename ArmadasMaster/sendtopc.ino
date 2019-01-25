void sendtopc(){

  Serial.print((val4*(4.8/402.0)-2.1));//Flowrate (val4*(4.79/402)-2.1447f)
  Serial.print(",");
  Serial.print(val1*(0.7f/134.0)+4.991f);//pH val1*(1.6f/322.0)+5.1f
  Serial.print(",");
  Serial.print(val2*(3.11/479.00)-1.233f);//Chlorine val2*(4.97/404)-2.214
  Serial.print(",");
  Serial.print((val3)*(221.1f/571.00f)-73.92f);//Conductivity ((val3)*(0.15f/125.00f))-0.216f
  Serial.print(",");
  Serial.print(val5/1000.000f);
  Serial.println(",");
}
