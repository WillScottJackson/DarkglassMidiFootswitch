// 
// 
// 

#include "RGBLED.h"


RGBLED::RGBLED()
{

}
RGBLED::RGBLED(unsigned int nRedPin, unsigned int nGreenPin, unsigned int nBluePin)
{
	m_nRedPin = nRedPin;
	m_nGreenPin = nGreenPin;
	m_nBluePin = nBluePin;

	pinMode(m_nRedPin, OUTPUT);
	pinMode(m_nGreenPin, OUTPUT);
	pinMode(m_nBluePin, OUTPUT);

	// Assume no values for now 
	m_nRedVal = 0;
	m_nGreenVal = 0;
	m_nBlueVal = 0;

	// Update at 60 Hz by default 
	m_nRefreshTime = 16;
	m_eBehaviour = STATIC;
	m_nLastUpdateTime = millis();
}

RGBLED::~RGBLED()
{

}

void RGBLED::SetRGBValues(uint8_t nRedVal, uint8_t nGreenVal, uint8_t nBlueVal)
{
	m_nRedVal = nRedVal;
	m_nGreenVal = nGreenVal;
	m_nBlueVal = nBlueVal;

	UpdateLED();
}

void RGBLED::SetLEDBehaviour(LEDBehaviour eBehaviour)
{
	m_eBehaviour = eBehaviour;
	UpdateLED();
}

void RGBLED::SetRefreshTime(uint32_t nRefreshTime)
{
	m_nRefreshTime = nRefreshTime;
	UpdateLED();
}

void RGBLED::UpdateLED()
{
	// If the time elapsed beteween updates is more than the refresh time, update the LED
	if (millis() - m_nLastUpdateTime > m_nRefreshTime)
	{
		switch (m_eBehaviour)
		{
		case STATIC:
			analogWrite(m_nRedPin, m_nRedVal);
			analogWrite(m_nGreenPin, m_nGreenVal);
			analogWrite(m_nBluePin, m_nBlueVal);
			break;

		// Increment/decrement the value depending on which direction
		case SWELL:
			break;

		// Cycle through each colour by blending in and out different colours
		case CYCLE:
			break;

		// Impose random changes to the values at random(ish) time intervals
		case FLICKER:
			break;

		// Flash the LEDs at a given time interval
		case FLASH:
			break;

		// By default, assume it's just a static LED for now
		default:
			analogWrite(m_nRedPin, m_nRedVal);
			analogWrite(m_nGreenPin, m_nGreenVal);
			analogWrite(m_nBluePin, m_nBlueVal);
			break;
		}
			
	}
}