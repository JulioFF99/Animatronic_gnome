

void cw_servo1(int s1_p_fin,int s1_inc){ // bajar gnomo
  unsigned long currentTime = millis();
    if(currentTime-previousServo1time>timeIntervalServo1 && s1_cw==true) {
      previousServo1time = currentTime;
      servo1.writeMicroseconds(cont_servo1);
      cont_servo1=cont_servo1+s1_inc;
      Serial.print("contador servo 1 \t");
      Serial.println(cont_servo1);
    }
  if(cont_servo1>=s1_p_fin){
    cont_servo1=s1_p_fin;
    s1_cw=false;
    Serial.println("fin de carrera abajo servo 1");
  }
}

void ccw_servo1(int s1_p_ini,int s1_inc){ //subir gnomo
  unsigned long currentTime = millis();
  if(currentTime-previousServo1time>timeIntervalServo1 && s1_cw==false) {
      previousServo1time = currentTime;
      servo1.writeMicroseconds(cont_servo1);
      cont_servo1=cont_servo1-s1_inc;
      //Serial.print("contador servo 1 \t");
      Serial.println(cont_servo1);
    }
  if(cont_servo1<=s1_p_ini){
    cont_servo1=s1_p_ini;
    s1_cw=true;
    Serial.println("fin de carrera arriba servo 1");
  }
}

// mover boca cw o ccw
void cw_servo2(int inc_servo2){ //cw
  unsigned long currentTime = millis();
    if(currentTime-previousServo2time>timeIntervalServo2 && s2_cw==true) {
      previousServo2time = currentTime;
      servo2.writeMicroseconds(cont_servo2);
      Serial.print("contador servo 2 \t");
     Serial.println(cont_servo2);
      cont_servo2=cont_servo2+inc_servo2;
    } 

  if(cont_servo2>=s2_p_fin){
    cont_servo2=s2_p_fin;
    s2_cw=false;
  }
}
void ccw_servo2(int inc_servo2){ //ccw
  unsigned long currentTime = millis();
    if(currentTime-previousServo2time>timeIntervalServo2 && s2_cw==false) {
      previousServo2time = currentTime;
      servo2.writeMicroseconds(cont_servo2);
      Serial.print("contador servo 2 \t");
      Serial.println(cont_servo2);
      cont_servo2=cont_servo2-inc_servo2;
    }
    
  if(cont_servo2<=s2_p_ini){
    cont_servo2=s2_p_ini;
    s2_cw=true;
  }
}
//mover gorro
void cw_servo3(int inc_servo3){
  unsigned long currentTime = millis();
    if(currentTime-previousServo3time>timeIntervalServo3 && s3_cw==true) {
      previousServo3time = currentTime;
      servo3.writeMicroseconds(cont_servo3);
      Serial.print("contador servo 3 \t");
      Serial.println(cont_servo3);
      cont_servo3=cont_servo3+inc_servo3;
    } 

  if(cont_servo3>=s3_p_fin){
    cont_servo2=s3_p_fin;
    s3_cw=false;
  }
}
void ccw_servo3(int inc_servo3){
  unsigned long currentTime = millis();
    if(currentTime-previousServo3time>timeIntervalServo3 && s3_cw==false) {
      previousServo3time = currentTime;
      servo3.writeMicroseconds(cont_servo3);
      Serial.print("contador servo 3 \t");
      Serial.println(cont_servo3);
      cont_servo3=cont_servo3-inc_servo3;
    }
    
  if(cont_servo3<=s3_p_ini){
    cont_servo3=s3_p_ini;
    s3_cw=true;
  }
}