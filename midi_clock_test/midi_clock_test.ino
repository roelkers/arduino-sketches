long bpm = 150;
long tempo = 1000/(bpm/60);

long prevMillis = 0;
long interval = tempo/24;    //interval is the number of milliseconds defined by tempo formula.

#include <MIDI.h>

MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI);
const int channel = 1;

void setup() {
  MIDI.begin();
}

void loop () {

  //MIDI.read(); //is there incoming MIDI?
  unsigned long currentMillis = millis();
  if(currentMillis - prevMillis > interval) {
   // save the last time.
     prevMillis = currentMillis;
    MIDI.sendRealTime(midi::Clock);

  }
}
