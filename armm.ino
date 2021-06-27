#define BLYNK_PRINT Serial

#include <SoftwareSerial.h>
SoftwareSerial SwSerial(10, 11); // RX, TX

#include <BlynkSimpleSerialBLE.h>

#include <Servo.h>
char auth[] = "F1MGUFj6IKLJxAabXgkGbAs18gZt6PH8";
Servo monServo1;
Servo monServo2;
Servo monServo3;
Servo monServo4;
Servo monServo5;

#include <SoftwareSerial.h> // appel de la bibliothèque du bluetooth
//SoftwareSerial DebugSerial(2, 3); // RX, TX
SoftwareSerial HC05(0,1);  // RX, TX
 
int position ;
int vitesse = 15; 
int positionAvant ;
int pos ;

void setup()  
{ 
  monServo1.attach(3);
  monServo2.attach(5);
  monServo3.attach(6);
  monServo4.attach(9);
  monServo5.attach(11);
  HC05.begin(9600);
  Serial.begin(9600);
  Blynk.begin(Serial, auth);
} 

void loop()
{
  Blynk.run();
  while (HC05.available()) {  
  int position = HC05.read();
  if (position >= 1000 && position <1180) {
      pos=position;
      pos = map(pos, 1000, 1180, 0, 180);
      if (positionAvant!=pos) {
         if (positionAvant<pos) {
              for (int i = positionAvant; i <= pos; i++){
                  monServo1.write(pos);
                  delay(vitesse);
              }
         }            
         else {
             for (int i = positionAvant; i >= position; i--) {
                  monServo1.write(pos); 
                  delay(vitesse);
             }              
      }
     }
     positionAvant=pos;   
   }
   
  if (position >= 2000 && position <2180) {
      pos=position;
      pos = map(pos, 2000, 2180, 0, 180);
      if (positionAvant!=pos) {
         if (positionAvant<pos) {
              for (int i = positionAvant; i <= pos; i++){
                  monServo2.write(pos);
                  delay(vitesse);
              }
         }            
         else {
             for (int i = positionAvant; i >= position; i--) {
                  monServo2.write(pos); 
                  delay(vitesse);
             }              
      }
     }  
     positionAvant=pos;
  }
  if (position >= 3000 && position <3180) {
      pos=position;
      pos = map(pos, 3000, 3180, 0, 180);
      if (positionAvant!=pos) {
         if (positionAvant<pos) {
              for (int i = positionAvant; i <= pos; i++){
                  monServo3.write(pos);
                  delay(vitesse);
              }
         }            
         else {
             for (int i = positionAvant; i >= position; i--) {
                  monServo3.write(pos); 
                  delay(vitesse);
             }              
         }
       }  
      positionAvant=pos;
  }
  if (position >= 4000 && position <4180) {
      pos=position;
      pos = map(pos, 4000, 4180, 0, 180);
      if (positionAvant!=pos) {
         if (positionAvant<pos) {
              for (int i = positionAvant; i <= pos; i++){
                  monServo4.write(pos);
                  delay(vitesse);
              }
         }            
         else {
             for (int i = positionAvant; i >= position; i--) {
                  monServo4.write(pos); 
                  delay(vitesse);
             }              
           }
      }  
      positionAvant=pos;
  }  
  if (position >= 5000 && position <5180) {
      pos = position;
      pos = map(pos, 1000, 1180, 0, 180);
      if (positionAvant!=pos) {
         if (positionAvant<pos) {
              for (int i = positionAvant; i <= pos; i++){
                  monServo5.write(pos);
                  delay(vitesse);
              }
         }            
         else {
             for (int i = positionAvant; i >= position; i--) {
                  monServo5.write(pos); 
                  delay(vitesse);
             }              
            }
      }
      positionAvant=pos;
    }
  }
}
