// 
// 
// 

#include "MIDI.h"

MIDI::MIDI()
{
	m_nLastHeaderTime = millis();
	m_uiLastHeader = 0;
}

MIDI::~MIDI()
{

}

void MIDI::SendHeader(uint8_t uiHeader)
{
	// If the last header is different, or if the refresh time elapsed
	if (uiHeader != m_uiLastHeader || (millis() - m_nLastHeaderTime)> nHeaderRefreshTime)
	{
		Serial.write(uiHeader);
		Serial.flush();
		m_uiLastHeader = uiHeader;
		m_nLastHeaderTime = millis();
	}
}

void MIDI::SendMessage(uint8_t uiMessageType, uint8_t uiChannel, uint8_t uiData)
{
	uiChannel--;
	uint8_t uiStatusByte = uiMessageType | uiChannel;

	uiStatusByte |= 0b10000000;
	uiData &= 0b01111111;

	SendHeader(uiStatusByte);

	Serial.write(uiData);
	Serial.flush();
}

void MIDI::SendMessage(uint8_t uiMessageType, uint8_t uiChannel, uint8_t uiData, uint8_t uiData2)
{
	uiChannel--;
	uint8_t uiStatusByte = uiMessageType | uiChannel;

	uiStatusByte |= 0b10000000;
	uiData &= 0b01111111;
	uiData2 &= 0b01111111;

	SendHeader(uiStatusByte);

	Serial.write(uiData);
	Serial.write(uiData2);
	Serial.flush();
}