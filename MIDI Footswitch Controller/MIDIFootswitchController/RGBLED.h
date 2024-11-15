// RGBLED.h

#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Hardware_Defs.h"

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
	RGBLED(LED led);
	~RGBLED();

	void SetRGBValues(uint8_t redVal, uint8_t greenVal, uint8_t blueVal);
	void SetLEDBehaviour(LEDBehaviour behaviour);
	void SetRefreshTime(uint32_t refreshTime);
	void UpdateLED();

private:

	LED _led;
	uint32_t _refreshTime;
    uint32_t _lastUpdateTime;
	uint32_t  _currentTime;

	LEDBehaviour _behaviour;

	uint8_t _redVal;
	uint8_t _greenVal;
	uint8_t _blueVal;
};
