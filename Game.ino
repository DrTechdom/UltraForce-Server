void startGame() {
  String msg_combine = "";
  
  // Set names
  for(int i=1; i < max_clients+1; i++) {
    if (gameData_roster[i][1] != "") {
      Serial.print("Name: "); Serial.print(gameData_roster[i][1]); Serial.print(" - Team: "); Serial.println(gameData_roster[i][2]);
      //Set name
      msg_combine = "N";  msg_combine += i; msg_combine += gameData_roster[i][1];
      SendMSG("000" , "set" , msg_combine);
      delay(200);
      
      //Set Team
      msg_combine = "T";  msg_combine += i; msg_combine += gameData_roster[i][2];
      SendMSG("000" , "set" , msg_combine);
      delay(200);
    }
  }

  // Set game time
  msg_combine = "G"; msg_combine += gameData_game_time;
  SendMSG("000" , "set" , msg_combine);
  delay(200);

  // Set game wait time
  msg_combine = "W"; msg_combine += gameData_wait_time;
  SendMSG("000" , "set" , msg_combine);
  delay(200);

  // Set game friendly fire rule
  msg_combine = "F"; msg_combine += gameData_friendly_fire;
  SendMSG("000" , "set" , msg_combine);
  delay(200);
  
  // Set game respawn time
  msg_combine = "R"; msg_combine += gameData_respawn_time;
  SendMSG("000" , "set" , msg_combine);
  delay(200);
}
