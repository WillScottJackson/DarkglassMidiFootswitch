// RGBLED.h

#ifndef _RGBLED_h
#define _RGBLED_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

enum LEDBehaviour
{
	STATIC, 
	SWELL, 
	CYCLE,
	FLICKER,
	FLASH
};

class RGBLED
{
public:
	RGBLED();
	RGBLED(unsigned int nRedPin, unsigned int nGreenPin, unsigned int nBluePin);
	~RGBLED();

	void SetRGBValues(uint8_t nRedVal, uint8_t nGreenVal, uint8_t nBlueVal);
	void SetLEDBehaviour(LEDBehaviour eBehaviour);
	void SetRefreshTime(uint32_t nRefreshTime);
	void UpdateLED();

private:

	

	uint32_t m_nRefreshTime;
    uint32_t m_nLastUpdateTime;
	uint32_t  m_nCurrentTime;

	LEDBehaviour m_eBehaviour;
	unsigned int m_nRedPin;
	unsigned int m_nGreenPin;
	unsigned int m_nBluePin;

	uint8_t m_nRedVal;
	uint8_t m_nGreenVal;
	uint8_t m_nBlueVal;

};


#endif

