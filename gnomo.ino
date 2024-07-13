//librerias
#include <Servo.h>
#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include <Stepper.h>

//-----------------variables motor a pasos
// Defines the number of steps per rotation
const int stepsPerRevolution = 2038;
const int angle=1528;//(angle*stepsPerRevolution)/360a
const int vel_step=4;

// actuadores
Servo servo1;
Servo servo2;
Servo servo3;
//----------pines-----------------
//pines servomotores
byte s1_pin=3; // mover arriba y abajo
byte s2_pin=5; // mover gorro
byte s3_pin=6; // mover boca
// modulo mp3
SoftwareSerial mySoftwareSerial(12, 13); // RX(naranja), TX(amarillo) pines por software para la comunicación con el módulo dfplayer mini. CONECTAR AMARILLO AL PIN 12
// motor a pasos
// Pins entered in sequence IN4-IN3-IN2-IN1 for proper step sequence
Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);
//------------variables modulo bluetooth------------------------
String texto = "";
String cadena; 
DFRobotDFPlayerMini myDFPlayer;
int vol = 28; // modulo mp3

//----------------variables servomotores-------------------------

// pos iniciales
 int  s1_p_ini=1080;
 int  s2_p_ini=1050;
 int  s3_p_ini=1100;
  // pos finales 
 int  s1_p_fin=1850;
 int  s2_p_fin=1700;
 int  s3_p_fin=1700;
// incremento en el ángulo servomotores
const int s1_inc=15; // incremento subir y bajar
const int s2_inc=50; // incremento gorro
const int s3_inc=50; // incremento boca

// incremento en el ángulo stepper motor
const int step_inc=15;
// tiempo anterior servos
 long previousServo1time = 0;
 long previousServo2time = 0;
 long previousServo3time = 0;
 //tiempo anterior stepper
 long previousSteppertime=0;

 // delay leer serial
long previousserialtime=0;
//
// delay servos
long timeIntervalServo1 = 40; // intervalo servo1 subir y bajar 
long timeIntervalServo2 = 10; // intervalo servo2 gorro
long timeIntervalServo3 = 10; // intervalo servo3 nariz
// delay stepper
long timeIntervalStepper=10;

// contadores
int cont_servo1=s1_p_ini; //contador servo1 para el arreglo de posiciones
int cont_servo2=s2_p_ini; //contador servo1 para el arreglo de posiciones
int cont_servo3=s3_p_ini; //contador servo1 para el arreglo de posiciones
int cont_stepper=0;
// cw servos
bool s1_cw=true;
bool s2_cw=true;
bool s3_cw=true;
// cw stepper motor
bool step_cw=true;

//-------------------variables para el control de rutinas
// momento en el que se completa la acción para la rutina 1
long cont_rutina1 = 0;
long paso1_rutina1 = 400;
long paso2_rutina1 = 455; //milisegundos agacharse moviendo el gorrito 12000
long paso3_rutina1 = 470; // mover la boca estando agachado 15000

// momento en el que se completa la acción para la rutina 2
long cont_rutina2 = 0;
long paso1_rutina2 = 580;
long paso2_rutina2 = 680; //milisegundos agacharse moviendo el gorrito 12000
long paso3_rutina2 = 780; // mover la boca estando agachado 15000

// momento en el que se completa la acción para la rutina 3
long cont_rutina3 = 0;
long paso1_rutina3 = 105;
long paso2_rutina3 = 230; //milisegundos agacharse moviendo el gorrito 12000
long paso3_rutina3 = 240; // mover la boca estando agachado 15000

// momento en el que se completa la acción para la rutina 4
long cont_rutina4 = 0;
long paso1_rutina4 = 350;
long paso2_rutina4 = 450; //milisegundos agacharse moviendo el gorrito 12000
long paso3_rutina4 = 460; // mover la boca estando agachado 15000

// momento en el que se completa la acción para la rutina 5
long cont_rutina5 = 0;
long paso1_rutina5 = 330;
long paso2_rutina5 = 420; //milisegundos agacharse moviendo el gorrito 12000
long paso3_rutina5 = 500; // mover la boca estando agachado 15000

// rutina on y off
bool r1_on=false;
bool r2_on=false;
bool r3_on=false;
bool r4_on=false;
bool r5_on=false;

void setup() {
  //servomotores
  servo1.attach(s1_pin);
  servo2.attach(s2_pin);
  servo3.attach(s3_pin);
  //bluetooth
  Serial.begin(9600);
  //inicializar modulo mp3
  mp3_setup();
  // 
  servo1.writeMicroseconds(s1_p_ini);
  delay(20);
  servo2.writeMicroseconds(s2_p_ini);
  delay(20);
  servo3.writeMicroseconds(s3_p_ini);
  delay(20);
  // velocidad stepper
 myStepper.setSpeed(vel_step);   
  Serial.println("setup done");
  // 
}

void loop() {
  
  
 unsigned long currentTime = millis();
  while (Serial.available()) {  
   if(currentTime-previousserialtime>15 ) {
      previousserialtime = currentTime;                  
    char c = Serial.read(); 
    cadena += c; 
    }
  }

if(((cadena == "1" && r1_on==false) || r1_on==true) && r2_on==false && r3_on==false && r4_on==false  && r5_on==false){ //rutina 1 cadena == "1"
    delay(100);
    Serial.println("inicio rutina 1");
    myDFPlayer.play(4); // dormir 
    r1_on=true;
    while(r1_on==true){
    rutina1();
    Serial.println(cont_rutina1);
    }
      
    Serial.println("final rutina 1");
  }

if(((cadena == "2" && r2_on==false) || r2_on==true) && r1_on==false && r3_on==false && r4_on==false  && r5_on==false){ //rutina 2 cadena == "2"
    delay(100);
    Serial.println("inicio rutina 2");
    myDFPlayer.play(3);// despertar
    r2_on=true;
    while(r2_on==true){
    rutina2();
    Serial.println(cont_rutina2);
    }
    
    Serial.println("final rutina 2");
  }


if(((cadena == "3" && r3_on==false) || r3_on==true) && r1_on==false && r2_on==false  && r4_on==false  && r5_on==false){ //rutina 2 cadena == "2"
    delay(100);
    Serial.println("inicio rutina 3");
    myDFPlayer.play(2); // saludo
    r3_on=true;
      while(r3_on==true){
      rutina3();
      Serial.println(cont_rutina3);
      }
    
    Serial.println("final rutina 3");
  }

if(((cadena == "4" && r4_on==false) || r4_on==true) && r1_on==false && r2_on==false && r3_on==false && r5_on==false){ //rutina 1 cadena == "1"
    delay(100);
    Serial.println("inicio rutina 4");
    myDFPlayer.play(5); // risas
    r4_on=true;
      while(r4_on==true){
      rutina4();
      Serial.println(cont_rutina4);
      }
    
    Serial.println("final rutina 4");
}

if(((cadena == "5" && r5_on==false) || r5_on==true) && r1_on==false && r2_on==false && r3_on==false && r4_on==false){ //rutina 1 cadena == "1"
  delay(100);
  Serial.println("inicio rutina 5");
  myDFPlayer.play(1); //aburrido
  r5_on=true;
    while(r5_on==true){
    rutina5();
    Serial.println(cont_rutina5);
    }
  
  Serial.println("final rutina 5");
}

if(cadena != ""){
  cadena = "";
 } 

}



