

void mp3_setup(){
  mySoftwareSerial.begin(9600);
  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Usa softwareSerial para communicarte con el módulo mp3.
    Serial.println(F("No es posible iniciar:"));
    Serial.println(F("1.Comprueba las conexiones"));
    Serial.println(F("2.Por favor inserte una tarjeta SD"));
    while(true);
  }
  Serial.println(F("DFPlayer Mini online."));
  myDFPlayer.volume(vol);  //setea el volumen

}
