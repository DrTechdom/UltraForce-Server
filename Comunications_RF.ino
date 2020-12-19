void SendMSG(String address , String command , String data){
   // Stop listening, so we can send!
  radio.stopListening();
  //radio.openWritingPipe(pipeNum[1]);

  delay(5);

  String msg = "";
  msg = address;
  msg += "x";
  msg += command;

  if (data != "") {
    msg += "x";
    msg += data;
  } 
  char text[20];
  msg.toCharArray(text,msg.length()+1);
  digitalWrite(TX_LED, HIGH);
  
  if (!radio.write(text, msg.length()+1)) {
    Serial.println("<CONSOLE> Radio transmission failed");
  }
 
 // Serial.print("<CONSOLE - > "); Serial.print(address); Serial.print(" ("); Serial.print(msg.length()+1); Serial.print(") >"); Serial.println(text);
  delay(5);

  digitalWrite(TX_LED, LOW);
  radio.startListening();
}

void radio_check() {
    delay(50); // Wait for client to come back
    digitalWrite(RX_LED, HIGH);
    String msg_combine = "";
    char text[32] = {0};
    String text_str = "";
 
    radio.read(&text, sizeof(text));
    text_str = text; // Convert char to string to deal with
    int clientID = text_str.substring(0,3).toInt();

  //  Serial.print("<REMOTE OUTPUT>"); Serial.println(text_str);
  //  Serial.print("<REMOTE NODE #"); Serial.print(text_str.substring(0,3)); Serial.print("> "); Serial.println(text_str.substring(4,8));
    

   //Client Registration
   if (text_str.substring(4,8) == "CREG") {
    //Confirm Registation
    SendMSG(text_str.substring(0,3) , "REGG" , "OK");
    
    gameData_roster[clientID][3] = "1"; // Mark player as registered
    Serial.print("<REMOTE NODE #"); Serial.print(text_str.substring(0,3)); Serial.println("> New Registration ");

//    gameData_roster[clientID][1] = names[clientID]; // Mark player as registered
   }

   // PONG
   else if (text_str.substring(4,8) == "PONG") {
    ping_ended[clientID] = text_str.substring(9).toInt(); /* Convert for results */

    //Serial.print("<REMOTE NODE #"); Serial.print(text_str.substring(0,3)); Serial.print("> Ping time: "); Serial.println(ping_started-ping_ended[clientID]);

    /* Send results to client */
    SendMSG(text_str.substring(0,3), "PSTA" , String(ping_started-ping_ended[clientID]));
    
    //Check if client is registered, if not tell client to re-register
    if (gameData_roster[clientID][3] == "0") {
      SendMSG(text_str.substring(0,3) , "REGG" , "NONE");
    }
   }
   digitalWrite(RX_LED, LOW);
}
