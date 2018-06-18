int eingang=A0; //Das Wort „eingang“ steht jetzt für den Wert „A0“ (Bezeichnung
//vom Analogport 0)
int LED=13;
//Das Wort „LED“ steht jetzt für den Wert 13
int sensorwert=0;
//Variable für den Sensorwert mit 0 als Startwert
void setup()
  {
  //Hier beginnt das Setup.
  pinMode (LED,OUTPUT); //Der Pin mit der LED (Pin 13) ist jetzt ein Ausgang.
  }
void loop()
  {
  //Mit dieser Klammer wird der Loop-Teil geöffnet.
  sensorwert= analogRead(eingang);
  //Die Spannung am Drehregler wird auslesen
  //und wie im vorherigen Sketch als Zahl zwischen 0 und 1023 unter der Variable
  //„sensorwert“ gespeichert.
  digitalWrite (LED,HIGH);
  //Die LED wird eingeschaltet
  delay(sensorwert);
  // Die LED bleibt für so viele Millisekunden eingeschaltet,
  //wie der Wert von „sensorwert“ es gespeichert hat.
  digitalWrite(LED, LOW);
  //Die LED wird ausgeschaltet.
  delay(sensorwert);
  // Die LED bleibt für so viele Millisekunden ausgeschaltet,
  //wie der Wert von „sensorwert“ es gespeichert hat.
  }
// Mit dieser Klammer wird der Loop-Teil geschlossen
//Der Loop-Teil wird nun erneut gestartet. Wenn sich der Wert des ausgelesenen
//Drehreglers ändert, dann ändert sich auch die Zeit zwischen den Ein- und Aus-
//Phasen der LED. Das Blinken wird dadurch schneller und langsamer. Das längste
//delay beträgt in diesem Sketch 1023ms (Millisekunden). Wenn man längere delays
//benötigt, dann baut man eine kleine mathematische Zeile in den Code ein.
//Beispiel: Man ändert die Zeile „sensorwert =analogRead(eingang);“ in
//„sensorwert =analogRead(eingang)*2;“ Damit wird der abgespeicherte Sensorwert
//um den Faktor 2 vergrößert. Da längste delay wäre dann 2046ms usw...
