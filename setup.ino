void setup()
{

  // Start the serial
  Serial.begin(9600);
  while(!Serial);
  Serial.println("<CONSOLE> Guncode Console Starting....");

  // Pin setup
  pinMode(RX_LED,OUTPUT);
  pinMode(TX_LED,OUTPUT);

  //LED test
  digitalWrite(RX_LED, HIGH);
  digitalWrite(TX_LED, HIGH);
  delay(1000);
  digitalWrite(RX_LED, LOW);
  digitalWrite(TX_LED, LOW);
  delay(1000);
  
  // Start the radio, again set to min & slow as I'm guessing while testing theire really close to each other
 // printf_begin(); // Debugging
  radio.begin();
  radio.setPALevel(RF24_PA_HIGH);   // RF24_PA_MIN ,RF24_PA_LOW, RF24_PA_HIGH, RF24_PA_MAX
  if (!radio.setDataRate( RF24_2MBPS )) { Serial.println("<CONSOLE> Set data rate failed!"); } // RF24_250KBPS, RF24_1MBPS, RF24_2MBPS
  //radio.setRetries(15, 4);
  radio.setChannel(22);
  radio.setCRCLength(RF24_CRC_8);
  //radio.enableAckPayload();
  //radio.setPayloadSize(20);
  radio.setAutoAck(0);
  
  /* Radio 1
   *  
   *  Open Listening and wriring pipe
   */
  radio.openWritingPipe(0xF0F0F0F066);
  radio.openReadingPipe(1, 0xF0F0F0F0AA);
  radio.openReadingPipe(2, 0xF0F0F0F0AB);
  radio.openReadingPipe(3, 0xF0F0F0F0AC);
  radio.openReadingPipe(4, 0xF0F0F0F0AD);
  radio.openReadingPipe(5, 0xF0F0F0F0AE);
  radio.startListening();
  //radio.printDetails();

  gameData_wait_time_mills = millis();

  #include "game_data.h"

//  radio.printDetails();
}
