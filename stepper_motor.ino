void cw_rotar_stepper(int vel_step){
  
  unsigned long currentTime = millis();
    if(currentTime-previousSteppertime>timeIntervalStepper && step_cw==true) {
    previousSteppertime = currentTime;
    myStepper.step(step_inc);
    cont_stepper=cont_stepper+step_inc;
    Serial.print("stepper cw");
    Serial.println(cont_stepper);
    }
    if(cont_stepper>=angle){
    cont_stepper=angle;
    step_cw=false;
    Serial.println("fin de carrera cw stepper");
  }

}
void ccw_rotar_stepper(int vel_step){
 
  unsigned long currentTime = millis();
    if(currentTime-previousSteppertime>timeIntervalStepper && step_cw==false) {
      previousSteppertime = currentTime;
      myStepper.step(-step_inc);
      cont_stepper=cont_stepper-step_inc;
      Serial.print("stepper ccw \t");
     Serial.println(cont_stepper);
    } 

  if(cont_stepper<=0){
    cont_stepper=0;
    step_cw=true;
    Serial.println("fin de carrera ccw stepper");
  }
}