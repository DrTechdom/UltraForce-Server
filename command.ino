void commands() {
    console_input = ""; //clear pipe
    console_input = Serial.readString();
    Serial.print("<CONSOLE> "); Serial.println(console_input);
 
    // Console Commands
 
    if (console_input == "reg") {
      // Temperary register command, will remove later
      SendMSG("000" , "REG" , "");
      timer_registation = millis() + 5000;
    }
    else if (console_input == "ping") {
      // Pings a specific client - ALL
      SendMSG("000","PING" , "");
      timer_registation = millis() + 5000;
    }
    else if (console_input == "list" || console_input == "stat") {
      // Stats - ALL
      // lists registered and non registered players
      // shows players status and client information such as ping rate
      Serial.println("******************* Registation List ********************");
      Serial.println("= # == Player Name === Registation Status  === Last Ping =");

      for(int i=1; i < max_clients+1; i++) {
        //Player number
        Serial.print("  "); Serial.print(i);
        
        //Name
        if (gameData_roster[i][1] == "") {
          Serial.print("    "); Serial.print("Player #"); Serial.print(i);
        }else{
          Serial.print("    "); Serial.print(gameData_roster[i][1]);
        }
        
        //Status
        if (gameData_roster[i][3] == "1") {
          Serial.print("   Online        ");
        }else{
          Serial.print("   Offline        ");
        }

        //Ping
        Serial.println("     Not ready");
      }
    }
    else if (console_input.substring(0,6) == "change" || console_input.substring(0,6) == "change ") {
      //Change game time
      if (console_input.substring(7,13) == "gtime" || console_input.substring(7,13) == "gtime ") {
        int time = console_input.substring(13).toInt();
        if (time > 0) {
          gameData_game_time = time;
          Serial.print("Change game time to: "); Serial.println(gameData_game_time);
        }
      }
      
      //Change game wait time
      else if (console_input.substring(7,13) == "wtime" || console_input.substring(7,13) == "wtime ") {
        int time = console_input.substring(13).toInt();
        if (time > 0) {
          gameData_wait_time = time;
          Serial.println(time);
          Serial.print("Change wait time to: "); Serial.println(gameData_wait_time);
        }
      }

      //Change team of player
      else if (console_input.substring(7,13) == "team" || console_input.substring(7,13) == "team ") {
        int  id = console_input.substring(13).toInt();
        if (id > 0) {
          Serial.print("Change player name: team to: "); Serial.println(id);
        }       
      }

      //Change name of player
      else if (console_input.substring(7,13) == "name" || console_input.substring(7,13) == "name ") {
        
      }
      else {
        Serial.print ("Usage: gtime, wtime, team, name");
      }
    }
    else if (console_input == "update") {
      // forces an update on all clients - Idle
    }
    else if (console_input == "start") {
      // Send data
      startGame();

      // Send start command
      delay(120);
      SendMSG("000" , "SART" , "");
      gameData_wait_time_mills = millis();
      gameData_status = 2;
      Serial.println("<CONSOLE> Starting game...");
    }
    else if (console_input == "stop") {
      // Stop game - Idle
      SendMSG("000" , "STOP" , "");
      gameData_status = 0;
      Serial.println("<CONSOLE> Force Stop of game..");
    }
    else{
      Serial.print("<CONSOLE> Unknown command: "); Serial.println(console_input);
    }
}
