#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <instrument.h>

AudioControlSGTL5000    audioDevice;
AudioOutputI2S i2s1;
Instrument instrument1;

void setup(){
	Serial.begin(9600);
  Serial.println("Audio Setup debug 1");

  AudioMemory(16);
  Serial.println("Audio Setup debug 2");

  audioDevice.enable();
  Serial.println("Audio Setup debug 3");

  audioDevice.volume(0.6);
  Serial.println("Audio Setup debug 4");

  instrument1.init(i2s1);

  Serial.println("Audio Setup debug 5");

}

void loop(){
	Serial.println("Audio loop start");

	instrument1.noteOn(24);
  delay(50);
  instrument1.noteOff();
  instrument1.noteOn(36);
  delay(50);
  instrument1.noteOff();
  instrument1.noteOn(48);
  delay(50);
  instrument1.noteOff();
  instrument1.noteOn(60);
  delay(50);
  instrument1.noteOff();
Serial.println("Audio loop end");

}