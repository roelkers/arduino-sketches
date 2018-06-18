// Dieses Mal nutzen wir auch den ersten Programmabschnitt. Hier werden
//Variablen eingetragen. Das bedeutet, dass sich hinter einem Buchstaben oder
//einem Wort eine Zahl verbirgt. Bei uns ist die LED an Pin 4 angeschlossen und
//der Piezo-Speaker an Pin 5. Damit man die beiden Pins später nicht
//verwechselt, benennen wir Pin4 und Pin5 einfach um.
int LED=4; // Das Wort „LED“ steht jetzt für die Zahl „4“.
int pieps=5;
// Das Wort „Pieps“ steht jetzt für die Zahl „5“.
void setup()
{
// Wir starten mit dem Setup.
pinMode(LED, OUTPUT);
// Pin 4 (Pin „LED“) ist ein Ausgang.
pinMode(pieps, OUTPUT);
// Pin 5 (Pin „Pieps“) ist ein Ausgang.
}
void loop()
{
// Das Hauptprogramm beginnt.
digitalWrite(LED, HIGH);
digitalWrite(pieps, HIGH);
delay(1000);
// Schalte den Piezo-Lautsprecher an.
//Warte 1000 Millisekunden. (Es piepst und leuchtet.)
digitalWrite(LED, LOW);
digitalWrite(pieps, LOW);
delay(1000);
//Schalte die LED an
// Schalte die LED aus.
//Schalte den Piezo aus.
//Warte 1000 Millisekunden. (kein Lärm, kein Licht)
}
// Hier am Ende springt das Programm an den Start des Loop-Teils. also wird
//es gleich wieder piepsen und leuchten. Wenn man die Pause (delay) verkleinert
//oder vergrößert,piepst und leuchtet es schneller oder langsamer.
