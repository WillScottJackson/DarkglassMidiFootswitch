
#include "RGBLED.h"


RGBLED::RGBLED()
{

}
RGBLED::RGBLED(LED led)
{
	_led = led;

	pinMode(_led.redPin, OUTPUT);
	pinMode(_led.greenPin, OUTPUT);
	pinMode(_led.bluePin, OUTPUT);

	// Assume no values for now 
	_redVal = 0;
	_greenVal = 0;
	_blueVal = 0;

	// Update at 60 Hz by default 
	_refreshTime = 16;
	_behaviour = STATIC;
	_lastUpdateTime = millis();
}

RGBLED::~RGBLED()
{

}

void RGBLED::SetRGBValues(uint8_t redVal, uint8_t greenVal, uint8_t blueVal)
{
	_redVal = redVal;
	_greenVal = greenVal;
	_blueVal = blueVal;

	UpdateLED();
}

void RGBLED::SetLEDBehaviour(LEDBehaviour behaviour)
{
	_behaviour = behaviour;
	UpdateLED();
}

void RGBLED::SetRefreshTime(uint32_t refreshTime)
{
	_refreshTime = refreshTime;
	UpdateLED();
}

void RGBLED::UpdateLED()
{
	// If the time elapsed beteween updates is more than the refresh time, update the LED
	if (millis() - _lastUpdateTime > _refreshTime)
	{
		switch (_behaviour)
		{
		case STATIC:
			analogWrite(_led.redPin, _redVal);
			analogWrite(_led.greenPin, _greenVal);
			analogWrite(_led.bluePin, _blueVal);
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
			analogWrite(_led.redPin, _redVal);
			analogWrite(_led.greenPin, _greenVal);
			analogWrite(_led.bluePin, _blueVal);
			break;
		}
	}
}
