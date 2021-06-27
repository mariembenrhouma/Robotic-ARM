/*
---- Receiver Code ----
*/

#include <Servo.h>    /*he library which helps us to control the servo motor*/
#include <SPI.h>      /*the communication interface with the modem*/
#include "RF24.h"     /*the library which helps us to control the radio modem*/

//define the servo name
Servo myServo1;
Servo myServo3;
Servo myServo4;
Servo myServo2;
Servo myServo5;

RF24 radio(9,10);     

const uint64_t pipe = 0xE8E8F0F0E1LL; /*the address of the modem,that will receive data from the Arduino.*/

int msg[1];

int data;
int pos; 

void setup(){

  //define the servo input pins
  myServo1.attach(1);
  myServo3.attach(2); 
  myServo4.attach(3); 
  myServo2.attach(4); 
  myServo5.attach(5); 
  
  radio.begin();                    
  radio.openReadingPipe(1, pipe);   
  radio.startListening();           /*enable receiving data via modem*/
  }

void loop(){
  if(radio.available()){
    radio.read(msg, sizeof(msg));    /*Cette fonction permet au module récepteur de recevoir les données.*/

    if(msg[0] <11 && msg [0]>-1){
      data = msg[0], pos=map(data, 0,10,0,180);
      myServo1.write(pos);      /* definir l'angle*/
    }
    if(msg[0]<21 && msg[0]>10){
      data = msg[0], pos=map(data, 11, 20, 0,180);
      myServo3.write(pos);
    }
    if(msg[0] <31 && msg[0]>20){
      data = msg[0], pos=map(data, 21, 30, 0,180);
      myServo4.write(pos);
    }
    if(msg[0] <41 && msg[0] >30){
      data = msg[0], pos=map(data, 31, 40, 0,180);
      myServo2.write(pos);
    }
    if(msg[0] <51 && msg[0] >40){
      data = msg[0], pos=map(data, 41, 50, 0,180);
      myServo5.write(pos);
    }
  }
}
