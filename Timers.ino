void timers() {
  
  // Game start time
  if ((millis() - gameData_wait_time_mills) > (gameData_wait_time * 1000) && gameData_status == 2) {
    gameData_status = 1;
    gameData_wait_time_mills = millis();
    Serial.println("<CONSOLE> Game starting!");
  }
 
  // In-Game end time
  if ((millis() - gameData_wait_time_mills) > (gameData_game_time * 1000) && gameData_status == 1) {
    gameData_status = 0;
    Serial.println("<CONSOLE> Game has finished");
  }

  // Registation query
  if (timer_registation == millis()) {
    // 15 second reset
    timer_registation = millis() + 5000;

    if (reg_pong_flip) {
      SendMSG("000","REG" , "");
      reg_pong_flip = false;
    }else{
      SendMSG("000","PING" , "");
      reg_pong_flip = true;
    }
  }

   // Game data query
  if (timer_registation <= millis() && gameData_status == 0 ) {
    // 20 second reset
    timer_registation = millis() + 5000;
  } 
}
