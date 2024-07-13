void rutina1(){ // habla, baja moviendo el gorrito y vuelve a hablar
 cont_rutina1++;
    if(cont_rutina1>250 && cont_rutina1<paso1_rutina1){
      cw_servo3(s3_inc); //mover boca arriba 
      ccw_servo3(s3_inc); //mover boca abajo
      //Serial.print("mover boca \t");
    }
    if(cont_rutina1>paso1_rutina1&& cont_rutina1<paso2_rutina1){
    cw_servo1(s1_p_fin,s1_inc); //bajar
    cw_servo2(s2_inc); //mover gorro derecha 
    ccw_servo2(s2_inc); //mover gorro izquierda
    //Serial.print("subir y bajar \t");
    }
    if(cont_rutina1>paso2_rutina1&& cont_rutina1<paso3_rutina1){
    cw_servo3(s3_inc); //mover boca arriba 
    ccw_servo3(s3_inc); //mover boca abajo
    //Serial.print("mover boca 2 \t");
    }
    if(cont_rutina1>paso3_rutina1){
    r1_on=false;
    cont_rutina1=0;
    }
}
void rutina2(){ // habla, sube moviendo el gorrito y vuelve a hablar
 cont_rutina2++;
    if(cont_rutina2>450 && cont_rutina2<paso1_rutina2){
      cw_servo3(s3_inc); //mover boca arriba 
      ccw_servo3(s3_inc); //mover boca abajo
      //Serial.print("mover boca \t");
    }
    if(cont_rutina2>paso1_rutina2&& cont_rutina2<paso2_rutina2){
    ccw_servo1(s1_p_ini,s1_inc); //subir
    cw_servo3(s3_inc); //mover boca arriba 
    ccw_servo3(s3_inc); //mover boca abajo
    //Serial.print("subir y bajar \t");
    }
    if(cont_rutina2>paso2_rutina2&& cont_rutina2<paso3_rutina2){
    cw_servo2(s2_inc); //mover boca arriba 
    ccw_servo2(s2_inc); //mover boca abajo
    //Serial.print("mover boca 2 \t");
    }
    if(cont_rutina2>paso3_rutina2){
    r2_on=false;
    cont_rutina2=0;
    }
}

void rutina3(){ // habla, sube moviendo el gorrito y vuelve a hablar
  if(cont_servo1>1770){
    servo1.writeMicroseconds(1350);
    delay(20);
    Serial.println("con cumplida");
    cont_servo1=1350;
  }
 cont_rutina3++;
    if(cont_rutina3<paso1_rutina3){
      //subir servo a ms
      cw_rotar_stepper(vel_step);// rotar cw
      cw_servo2(s2_inc); //mover gorro derecha 
      ccw_servo2(s2_inc); //mover gorro izquierda
      //Serial.print("mover boca \t");
    }
    if(cont_rutina3>paso1_rutina3&& cont_rutina3<paso2_rutina3){
    ccw_rotar_stepper(vel_step); //rotar ccw
    cw_servo2(s2_inc); //mover gorro derecha 
    ccw_servo2(s2_inc); //mover gorro izquierda
    //Serial.print("subir y bajar \t");
    }
    if(cont_rutina3>paso2_rutina3&& cont_rutina3<paso3_rutina3){
      //bajar servo a ms
    cw_servo3(s3_inc); //mover boca arriba 
    ccw_servo3(s3_inc); //mover boca abajo
    //Serial.print("mover boca 2 \t");
    }
    if(cont_rutina3>paso3_rutina3){
    r3_on=false;
    cont_rutina3=0;
    }
}

void rutina4(){ // habla, baja moviendo el gorrito y vuelve a hablar
 cont_rutina4++;
    if(cont_rutina4>260 && cont_rutina4<paso1_rutina4){
      cw_servo3(s3_inc); //mover boca arriba 
      ccw_servo3(s3_inc); //mover boca abajo
      //Serial.print("mover boca \t");
    }
    if(cont_rutina4>paso1_rutina4 && cont_rutina4<paso2_rutina4){
    cw_servo1(1400,25); //bajar
    cw_servo2(s2_inc); //mover gorro derecha 
    ccw_servo2(s2_inc); //mover gorro izquierda
    ccw_servo1(1100,25); //subir
    //Serial.print("subir y bajar \t");
    }
    if(cont_rutina4>paso2_rutina4 && cont_rutina4<paso3_rutina4){
    cw_servo3(s3_inc); //mover boca arriba 
    ccw_servo3(s3_inc); //mover boca abajo
    //Serial.print("mover boca 2 \t");
    }
    if(cont_rutina4>paso3_rutina4){
    r4_on=false;
    cont_rutina4=0;
    }
}

void rutina5(){ // habla, baja moviendo el gorrito y vuelve a hablar
 cont_rutina5++;
    if(cont_rutina5>180 && cont_rutina5<paso1_rutina5){
      cw_servo3(s3_inc); //mover boca arriba 
      ccw_servo3(s3_inc); //mover boca abajo
      //Serial.print("mover boca \t");
    }
    if(cont_rutina5>paso1_rutina5 && cont_rutina5<paso2_rutina5){
    cw_rotar_stepper(vel_step); //rotar cw
    cw_servo1(1400,25); //bajar
    ccw_servo1(1100,25); //subir
    ccw_rotar_stepper(vel_step); //rotar ccw
    //Serial.print("subir y bajar \t");
    }
    if(cont_rutina5>paso2_rutina5 && cont_rutina5<paso3_rutina5){
    cw_servo3(5); //mover boca arriba 
    ccw_servo3(5); //mover boca abajo
    //Serial.print("mover boca 2 \t");
    }
    if(cont_rutina5>paso3_rutina5){
    r5_on=false;
    cont_rutina5=0;
    }
}