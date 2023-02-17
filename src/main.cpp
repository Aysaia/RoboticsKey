//Ricardo Isai Gonzalez Hernandez
//Mauricio Daniel Coronado Hernández
//Alejandro González Quintanilla
//Jorge Andrés García Guerra

#include <Arduino.h>
#include <SoftwareSerial.h>
int RX = 10;
int TX = 11;
SoftwareSerial Genotronex(RX, TX); 
int relay1 =13;
int relay2 = 12;
String password = "Password1234"; 
int BluetoothData; 
bool passed = false;

void setup() {
  Genotronex.begin(9600);
  Genotronex.println("Bluetooth On please press 1 or 0 blink LED ..");
  pinMode(relay1,OUTPUT);
  pinMode(relay2,OUTPUT);
}

void loop() {
   if (Genotronex.available()){
      BluetoothData=Genotronex.read();

      if(BluetoothData=='1' && passed){   
        digitalWrite(relay1,1);
        digitalWrite(relay2,1);
      }
      if (BluetoothData=='0' && passed){
        digitalWrite(relay1,0);
        digitalWrite(relay2,0);
      }

      if(password = BluetoothData) passed = !passed;
    }
delay(100);
}
