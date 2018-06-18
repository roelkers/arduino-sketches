#include <LiquidCrystal.h>
// LCD-Bibliothek laden
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // In dieser Zeile wird festgelegt,
//welche Pins des Mikrocontrollerboards für das LCD verwendet wird (Am besten
//erstmal nicht verändern).
void setup() {
lcd.begin(16, 2);
//Im Setup wird angegeben, wie viele Zeichen und Zeilen
//verwendet werden. Hier: 16 Zeichen in 2 Zeilen
}
void loop() {
lcd.setCursor(0, 0);
//Startposition der Darstellung auf dem LCD festlegen.
//Bedeutet: Erstes Zeichen in der ertsen Zeile.
lcd.print("Antonie und Bea!!");
//erscheinen.
lcd.setCursor(0, 1);
//zweiten Zeile.
// lcd.setCursor(0,1) bedeutet: Erstes Zeichen in der
lcd.print("Hallo 1000!!!");
//auftauchen.
}
