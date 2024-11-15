// MIDI.h

#ifndef _MIDI_h
#define _MIDI_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "MIDIMessageDefs.h"

const unsigned long int nHeaderRefreshTime = 1000;

class MIDI
{
public:
	MIDI();
	~MIDI();
	
	void SendMessage(uint8_t uiMessageType, uint8_t uiChannel, uint8_t uiData);
	void SendMessage(uint8_t uiMessageType, uint8_t uiChannel, uint8_t uiData, uint8_t uiData2);

private: 

	void SendHeader(uint8_t uiHeader);
	uint8_t m_uiLastHeader;
	unsigned long int m_nLastHeaderTime;
};

#endif

