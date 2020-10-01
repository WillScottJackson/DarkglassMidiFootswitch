// Hardware Defs

#ifndef _HARDWARE_DEFS_h
#define _HARDWARE_DEFS_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

const unsigned int nRedPin1 = 4;
const unsigned int nGreenPin1 = 44;
const unsigned int nBluePin1 = 46;

const unsigned int nRedPin2 = 7;
const unsigned int nGreenPin2 = 5;
const unsigned int nBluePin2 = 6;

const unsigned int nRedPin3 = 10;
const unsigned int nGreenPin3 = 9;
const unsigned int nBluePin3 = 8;

const unsigned int nRedPin4 = 13;
const unsigned int nGreenPin4 = 12;
const unsigned int nBluePin4 = 11;

const unsigned int nFootswitch1 = 19;
const unsigned int nFootswitch2 = 18;
const unsigned int nFootswitch3 = 2;
const unsigned int nFootswitch4 = 3;
const unsigned int nFootswitch5 = 34;
const unsigned int nFootswitch6 = 32;

const unsigned int SWITCH_HOLD_TIME = 1500;
const unsigned int DEBOUNCE_TIME = 30;

#endif