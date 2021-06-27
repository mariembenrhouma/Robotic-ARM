/*
---- Transmitter Code ----
*/

#include <SPI.h>              /*the communication interface with the modem*/
#include "RF24.h"             /*the library which helps us to control the radio modem*/

int msg;

//define the flex sensor input pins
int flex_5 = A5;
int flex_4 = A4;
int flex_3 = A3;
int flex_2 = A2;
int flex_1 = A1;

//define variables for flex sensor values
int flex_5_val;
int flex_4_val;
int flex_3_val;
int flex_2_val;
int flex_1_val;

RF24 radio(9,10);                       /*9 and 10 are a digital pin numbers to which signals CE and CSN are connected. (création de l'objet radio)*/
                                      
const uint64_t pipe = 0xE8E8F0F0E1LL;   /*adresse du canal de communication qui va recevoir les données de la part de Arduino.*/


void setup(void){
  Serial.begin(9600);
  radio.begin();                      /* initialisation du module NRF24L01.*/
  radio.openWritingPipe(pipe);        /* pipe représente l'adresse du canal de communication. Cette fonction permet au module émetteur 
                                         d'ouvrir le canal de communication avec le module récepteur avec lequel il va communiquer.*/
}

void loop(){

  flex_5_val = analogRead(flex_5); 
                            
  flex_5_val = map(flex_5_val, 0,1023, 0, 10); /* Remappe un nombre d'une plage à une autre. Autrement dit, une valeur comprise entre 0 et 1023 sera code entre 0 et 10 .*/
  msg = flex_5_val;
  radio.write(msg, sizeof(msg));    /*envoi des données*/

  flex_4_val = analogRead(flex_4);
                            
  flex_4_val = map(flex_4_val, 0,1023, 11, 20);
  msg = flex_4_val;
  radio.write(msg, sizeof(msg));

  flex_3_val = analogRead(flex_3);
                             
  flex_3_val = map(flex_3_val, 0,1023, 21, 30);
  msg = flex_3_val;
  radio.write(msg, sizeof(msg));

  flex_2_val = analogRead(flex_2);
                             
  flex_2_val = map(flex_2_val,0,1023, 31, 40);
  msg[0] = flex_2_val;
  radio.write(msg, sizeof(msg));

  flex_1_val = analogRead(flex_1);
                            
  flex_1_val = map(flex_1_val, 0,1023, 41, 50);
  msg = flex_1_val;
  radio.write(msg, sizeof(msg));
}
