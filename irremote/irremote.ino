#include <Servo.h>
Servo servoblau;
//„servoblau“
//Die Servobibliothek wird aufgerufen.
//Erstellt für das Programm ein Servo mit dem Namen
void setup()
{
  servoblau.attach(8);
}
//Servo wird mit Pin8 verbunden
void loop()
{
  servoblau.write(0);
  delay(3000);
  //Das Programm stoppt für 3 Sekunden
  servoblau.write(90);
  delay(3000);
  
  //Position 3 ansteuern mit dem Winkel 180°
  //Das Programm stoppt für 3 Sekunden
  servoblau.write(20);
  delay(3000);

  //Position 2 ansteuern mit dem Winkel 90°
  //Das Programm stoppt für 3 Sekunden
  servoblau.write(180);
  delay(3000);
  //Position 1 ansteuern mit dem Winkel 0°
  //Position 4 ansteuern mit dem Winkel 20°
  //Das Programm stoppt für 3 Sekunden
  servoblau.write(45);
  delay(3000);
}
