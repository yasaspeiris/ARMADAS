void sim800setup() {
  Sim800l.begin(); // initializate the library.
  //error = Sim800l.delAllSms(); //clean memory of sms;
}


void checkforsmsreq() {
  textSms = Sim800l.readSms(1); //read the first sms

  if (textSms.indexOf("OK") != -1) //first we need to know if the messege is correct. NOT an ERROR
  {
    if (textSms.length() > 1)  // optional you can avoid SMS empty
    {

      numberSms = Sim800l.getNumberSms(1); // Here you have the number
      //for debugin
      //Serial.println(numberSms);
      textSms.toUpperCase();  // set all char to mayus ;)

      if (textSms.indexOf("FLOW") != -1) {
        
        MyString = String((val4*(4.8/402.0)-2.1), 1); //Convert float to String
        MyString = (MyString + " m3/h");
        // convert string to char starts here
        // Length (with one extra character for the null terminator)
        int str_len = MyString.length() + 1;
        // Prepare the character array (the buffer)
        char char_array[str_len];
        // Copy it over
        MyString.toCharArray(char_array, str_len);
        error = Sim800l.sendSms(number, char_array);
      }
      else if (textSms.indexOf("PH") != -1) {
        
        MyString = String(val1*(0.7f/134.0)+4.991f, 1); //Convert float to String
        MyString = (MyString + " pH");
        // convert string to char starts here
        // Length (with one extra character for the null terminator)
        int str_len = MyString.length() + 1;
        // Prepare the character array (the buffer)
        char char_array[str_len];
        // Copy it over
        MyString.toCharArray(char_array, str_len);
        error = Sim800l.sendSms(number, char_array);
      } else if (textSms.indexOf("CL") != -1) {
        
        MyString = String(val2*(3.11/479.00)-1.233f,1); //Convert float to String
        MyString = (MyString + " mg/l");
        // convert string to char starts here
        // Length (with one extra character for the null terminator)
        int str_len = MyString.length() + 1;
        // Prepare the character array (the buffer)
        char char_array[str_len];
        // Copy it over
        MyString.toCharArray(char_array, str_len);
        error = Sim800l.sendSms(number, char_array);
      }else if (textSms.indexOf("COND") != -1) {
        
        MyString = String((val3)*(221.1f/571.00f)-73.92f, 1); //Convert float to String
        MyString = (MyString + " uS/cm");
        // convert string to char starts here
        // Length (with one extra character for the null terminator)
        int str_len = MyString.length() + 1;
        // Prepare the character array (the buffer)
        char char_array[str_len];
        // Copy it over
        MyString.toCharArray(char_array, str_len);
        error = Sim800l.sendSms(number, char_array);
      }else if (textSms.indexOf("TOT") != -1) {
        
        MyString = String(val5/1000.000f, 4); //Convert float to String
        MyString = (MyString + " kg");
        // convert string to char starts here
        // Length (with one extra character for the null terminator)
        int str_len = MyString.length() + 1;
        // Prepare the character array (the buffer)
        char char_array[str_len];
        // Copy it over
        MyString.toCharArray(char_array, str_len);
        error = Sim800l.sendSms(number, char_array);
      }
      else {
        //Serial.println("Not Compatible");
      }


      Sim800l.delAllSms(); //do only if the message is not empty,in other case is not necesary
      //delete all sms..so when receive a new sms always will be in first position
    }



  }
}
