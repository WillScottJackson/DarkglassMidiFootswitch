// Hardware Defs
#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

typedef struct 
{
	uint8_t redPin;
	uint8_t greenPin;
	uint8_t bluePin;

} LED;

namespace HardwareDefinitions
{
	namespace LEDs
	{
		static constexpr LED LED1{ 4, 44, 46 };
		static constexpr LED LED2{ 7, 5, 6 };
		static constexpr LED LED3{ 10, 9, 8 };
		static constexpr LED LED4{ 13, 12, 11 };
	}

	namespace Footswitches
	{
		constexpr uint8_t Footswitch1 = 19;
		constexpr uint8_t Footswitch2 = 18;
		constexpr uint8_t Footswitch3 = 2;
		constexpr uint8_t Footswitch4 = 3;
		constexpr uint8_t Footswitch5 = 34;
		constexpr uint8_t Footswitch6 = 32;
	}

	namespace HardwareTiming
	{
		constexpr auto SwitcHoldTime = 1500;
		constexpr auto DebounceTime = 30;
	}
}
