int TMP36 = A0; //Der Sensor soll am analogen Pin A0 angeschlossen werden. Wir
//nennen den Pin ab jetzt „TMP36“
int temperatur = 0;
//Unter der Variablen „temperatur“ wird später der
//Temperaturwert abgespeichert
int temp[10]; //Damit man gute Werte erhält, liest man zunächst mehrere Werte
//aus und bildet dann den Mittelwert. Die eckige Klammer „[10]“ erzeugt hier
//gleich zehn Variablen mit den Namen „temp[0]“, „temp[2]“, „temp[3]“, ... bis ...
//„temp[9]“. Mit der Schreibweise [10] spart man also nur etwas Platz.
int time= 20; //Der Wert für „time“ gibt im Code die zeitlichen Abstände
//zwischen den einzelnen Messungen vor.

void setup() {
  
Serial.begin(9600);
// Im Setup beginnen wir die serielle Kommunikation, damit
//wir uns die Temperatur später auch anzeigen lassen können. Über die serielle
//Kommunikation sendet das Board die Messwerte an den Computer. In der Arduino-
//Software kann man unter „Tools“ den „Serial Monitor“ starten um die Messwerte
//zu sehen.
}

void loop() {
temp[0] = map(analogRead(TMP36), 0, 410, -50, 150);
delay(time);
temp[1] = map(analogRead(TMP36), 0, 410, -50, 150);
delay(time);
temp[2] = map(analogRead(TMP36), 0, 410, -50, 150);
delay(time);
temp[3] = map(analogRead(TMP36), 0, 410, -50, 150);
delay(time);
temp[4] = map(analogRead(TMP36), 0, 410, -50, 150);
delay(time);
temp[5] = map(analogRead(TMP36), 0, 410, -50, 150);
delay(time);
temp[6] = map(analogRead(TMP36), 0, 410, -50, 150);
delay(time);
temp[7] = map(analogRead(TMP36), 0, 410, -50, 150);
delay(time);
temp[8] = map(analogRead(TMP36), 0, 410, -50, 150);
delay(time);
temp[9] = map(analogRead(TMP36), 0, 410, -50, 150);
//Ab hier wird zehnmal die
//Temperatur ausgelesen. Dazwischen ist je eine kleine Pause mit der Dauer
//„time“ in Millisekunden. Aber was passiert hier genau? Sehen wir uns den
//Befehl einmal genauer an.
//temp[1] = map(analogRead(TMP36), 0, 410, -50, 150);
//Der Reihe nach:
//temp[1] – ist der Name der ersten Variablen.
//„map ( a, b, c, d, e)“ – Dies ist der sogenannte „Map-Befehl“. Hiermit kann
//man einen eingelesenen Wert (a) bei dem die Werte zwischen (b) und (c) liegen,
//in einen anderen Zahlenbereich umwandeln, und zwar in den Bereich zwischen (d)
//und (e).
//In unserem Befehl passiert folgendes:
//Der Wert des Sensors wird unmittelbar im „Map-Befehl“ ausgelesen mit
//„analogRead(TMP36)“. Die Messwerte sollten zwischen 0 und 410 liegen. Das
//entspricht am analogen Port den Werten zwischen 0 V und 2V. Die Spannung gibt
//der Sensor bei Temperaturen zwischen -50°C und +150°C aus. Diese Werte am
//analogen Port werden nun durch den „Map-Befehl“ direkt in die °Celsius Werte
//zwischen -50 und 150 umgewandelt.
temperatur=(temp[0]+temp[1]+temp[2]+temp[3]+temp[4]+temp[5]+temp[6]+temp[7]+temp
[8]+temp[9])/10; //Alles in eine Zeile! Hier werden alle zehn ermittelten
//Temperaturwerte zusammengerechnet und durch zehn geteilt. Der
//durchschnittliche Wert wird unter der Variablen „temperatur“ gespeichert
Serial.print(temperatur); //Nun wird der Wert „temperatur“ über die serielle
//Kommunikation an den PC gesendet. Nun muss man den seriellen Monitor in der
//Arduino-Software öffnen um die Temperatur am Sensor abzulesen.
Serial.println("Grad");
}
