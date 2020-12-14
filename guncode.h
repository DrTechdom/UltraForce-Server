#ifndef _GUNCODE_H
#define _GUNCODE_H

// Load up the libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
//#include <printf.h>

// define the pins
#define CE_PIN   9
#define CSN_PIN 8
#define RX_LED 2
#define TX_LED 4

// Create a Radio
RF24 radio(CE_PIN, CSN_PIN); 

// Variables
const int max_clients = 5;
String gameData_roster[max_clients][4]; // 8 clients max so far
// 1 = name
// 2 = team
// 3 = reg status
long gameData_wait_time_mills = 0;

//Default game values in seconds
int gameData_game_time = 10;
int gameData_wait_time = 10;
int gameData_friendly_fire = 0;
int gameData_respawn_time = 5;
int gameData_status = 0;

int long last_ping = 0;
bool reg_pong_flip = true;

String console_input = "";

// Timers
long int timer_registation = 5000;
long int timer_listen = 0;

// The tx/rx address
const uint64_t pipeNum[max_clients+1] = { 0xF0F0F0F066 , 0xF0F0F0F0AA , 0xF0F0F0F0AB ,0xF0F0F0F0AC , 0xF0F0F0F0AD , 0xF0F0F0F0AE };


#endif
