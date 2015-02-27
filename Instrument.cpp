#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <instrument.h>

Instrument::Instrument() { 

}

void Instrument::init(AudioOutputI2S i2s1){
  AudioConnection patchCord1(waveform1, 0, mixer1, 0);
  AudioConnection patchCord2(waveform2, 0, mixer1, 1);
  AudioConnection patchCord3(waveform3, 0, mixer1, 2);
  AudioConnection patchCord4(mixer1, ampEnvelope);
  AudioConnection patchCord5(waveform1, filterEnvelope);
  AudioConnection patchCord6(ampEnvelope, 0, filter1, 0);
  AudioConnection patchCord7(filterEnvelope, 0, filter1, 1);
  AudioConnection patchCord8(filter1, 0, i2s1, 0);
  AudioConnection patchCord9(filter1, 0, i2s1, 1);

  Serial.println("instrument init begin");
  this -> i2s1 = i2s1;
  waveform1.begin(0.5, 220.1, WAVEFORM_SQUARE); 
  waveform2.begin(0.5, 440, WAVEFORM_SINE); 
  waveform3.begin(0.5, 440, WAVEFORM_SAWTOOTH);
  mixer1.gain(0, 0.7); 
  mixer1.gain(1, 0.7);    
  mixer1.gain(2, 0.7);    
  ampEnvelope.delay(0);
  ampEnvelope.attack(0);
  ampEnvelope.hold(50.0);		
  ampEnvelope.decay(200.0);
  ampEnvelope.sustain(1.0);
  ampEnvelope.release(0.0);
  filterEnvelope.delay(0);
  filterEnvelope.attack(0);
  filterEnvelope.hold(10.0);		
  filterEnvelope.decay(100.0);
  filterEnvelope.sustain(1.0);
  filterEnvelope.release(0.0);
  filter1.frequency(400);
  filter1.resonance(3);
  filter1.octaveControl(5);
  Serial.println("instrument init end");
}


void Instrument::noteOn(uint8_t midiNote){
  waveform1.frequency(midiFreq[midiNote]);
  waveform2.frequency(midiFreq[midiNote]);
  waveform3.frequency(midiFreq[midiNote]);
  ampEnvelope.noteOn();
  filterEnvelope.noteOn();
}

void Instrument::noteOff(){
  ampEnvelope.noteOff();
  filterEnvelope.noteOff();
}