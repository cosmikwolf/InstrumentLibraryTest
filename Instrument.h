#ifndef Instrument_h
#define Instrument_h

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>

#define CHORUS_DELAY_LENGTH (16*AUDIO_BLOCK_SAMPLES)
// Allocate the delay lines for left and right channels


class Instrument
{

	public:
		Instrument();
		
		void init(AudioOutputI2S i2s1);
		void noteOn(uint8_t midiNote);
		void noteOff();
		
		float midiFreq[128] = { 8.17, 8.66, 9.17, 9.72, 10.30, 10.91, 11.56, 12.24, 12.97, 13.75, 14.56, 15.43, 16.35, 17.32, 18.35, 19.44, 20.60, 21.82, 23.12, 24.49, 25.95, 27.50, 29.13, 30.86, 32.70, 34.64, 36.70, 38.89, 41.20, 43.65, 46.24, 48.99, 51.91, 55.00, 58.27, 61.73, 65.40, 69.29, 73.41, 77.78, 82.40, 87.30, 92.49, 97.99, 103.82, 110.00, 116.54, 123.47, 130.81, 138.59, 146.83, 155.56, 164.81, 174.61, 184.99, 195.99, 207.65, 220.00, 233.08, 246.94, 261.62, 277.18, 293.66, 311.12, 329.62, 349.22, 369.99, 391.99, 415.30, 440.00, 466.16, 493.88, 523.25, 554.36, 587.32, 622.25, 659.25, 698.45, 739.98, 783.99, 830.60, 880.00, 932.32, 987.76, 1046.50, 1108.73, 1174.65, 1244.50, 1318.51, 1396.91, 1479.97, 1567.98, 1661.21, 1760.00, 1864.65, 1975.53, 2093.00, 2217.46, 2349.31, 2489.01, 2637.02, 2793.82, 2959.95, 3135.96, 3322.43, 3520.00, 3729.31, 3951.06, 4186.00, 4434.92, 4698.63, 4978.03, 5274.04, 5587.65, 5919.91, 6271.92, 6644.87, 7040.00, 7458.62, 7902.13, 8372.01, 8869.84, 9397.27, 9956.06, 10548.08, 11175.30, 11839.82, 12543.85 };

		AudioSynthWaveform       	waveform1;     
		AudioSynthWaveform       	waveform2;     
		AudioSynthWaveform       	waveform3;     
		AudioEffectEnvelope      	ampEnvelope;   
		AudioEffectEnvelope      	filterEnvelope;
		AudioMixer4              	mixer1;        
		AudioFilterStateVariable 	filter1;       
		AudioOutputI2S 						i2s1;

		short l_delayline[CHORUS_DELAY_LENGTH];
		short r_delayline[CHORUS_DELAY_LENGTH];

	private:
};

#endif