int trigger=7;
int echo=6;
//Das Wort trigger ist jetzt die Zahl 7.
//Das Wort echo ist jetzt die Zahl 6.
long dauer=0;
//Das Wort dauer ist jetzt eine Variable, unter der die Zeit
//gespeichert wird, die eine Schallwelle bis zur Reflektion und zurück benötigt.
//Startwert ist hier 0.
long entfernung=0; //Das Wort „entfernung“ ist jetzt die variable, unter der
//die berechnete Entfernung gespeichert wird.
//Info: Anstelle von „int“ steht hier vor den beiden Variablen „long“. Das hat
//den Vorteil, dass eine größere Zahl gespeichert werden kann. Nachteil: Die
//Variable benötigt mehr Platz im Speicher.
long LED = 8;
void setup()
{
  Serial.begin (9600);
  //Serielle kommunikation starten, damit man sich später
  //die Werte am serial monitor ansehen kann.
  pinMode(trigger, OUTPUT);
  pinMode(LED,OUTPUT);
  pinMode(echo, INPUT);
  //„trigger“(Pin7) ist ein Ausgang.
  //„echo“(Pin6) ist ein Eingang.
}
void loop()
{
  digitalWrite(trigger, LOW);
  //Hier nimmt man die Spannung für kurze Zeit vom
  //Trigger-Pin, damit man später beim senden des Trigger-Signals ein rauschfreies
  //Signal hat.
  delay(5);
  //Dauer: 5 Millisekunden
  digitalWrite(trigger, HIGH);
  delay(10);
  //Jetzt sendet man eine Ultraschallwelle los
  //Dieser „Ton“ erklingt für 10 Millisekunden.
  digitalWrite(trigger, LOW);
  //Dann wird der „Ton“ abgeschaltet.
  dauer = pulseIn(echo, HIGH); //Mit dem Befehl „pulseIn“ zählt der
  //Mikrokontroller die Zeit in Millisekunden, bis der Schall zum
  //Ultraschallsensor zurückkehrt.
  entfernung = (dauer/2) / 29.1; //Nun berechnet man die Entfernung in
  //Zentimetern. Man teilt zunächst die Zeit durch zwei (Weil man ja nur eine
  //Strecke berechnen möchte und nicht die Strecke hin- und zurück). Den Wert
  //teilt man noch durch 29.1 und erhält dann den Wert in Zentimetern, da der
  //Schall in der Luft eine Geschwindigkeit von einem Zentimeter pro 29,1
  //Mikrosekunden hat.
  //Beispiel: Der Sensor misst eine Zeit von 2000 Mikrosekunden. Das sind dann
  //1000 Mikrosekunden pro Strecke. Nun teilt man 1000 durch 29.1 (Weil der Schall
  //ja 1cm pro 29,1 Mikrosekunden zurücklegt) und erhält den Wert 34,3cm
  if (entfernung >= 500 || entfernung <= 0)
    //500cm oder unter 0cm liegt,...
    //Wenn die gemessene Entfernung über
    {
    Serial.println("Kein Messwert"); //dann soll der serial monitor ausgeben „Kein
    //Messwert“, weil Messwerte in diesen Bereichen falsch oder ungenau sind.
    }
  else
    {
    //ansonsten..
    Serial.print(entfernung);
    //hier ausgegeben werden.
    //...soll der Wert der Entfernung an den serial monitor
    Serial.println("cm");
    if(entfernung < 20)
      {
        digitalWrite(LED,HIGH);
      }
    else
      {
        digitalWrite(LED,LOW);
      }
    }
  //delay(1000); //Das delay von einer Sekunde sorgt in ca. jeder neuen Sekunde für
  //einen neuen Messwert.
}
