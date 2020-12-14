void loop()
{
  byte pipeNum = 0;
  timers();
  
  /*********** Radio Data ***********/
 if(radio.available()) {
    radio_check();
  }
 
 
  /****** Console Data **********/
  if (Serial.available() > 0) {
    commands();
  }
}
