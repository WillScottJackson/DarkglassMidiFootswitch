/*
 Name:		MIDI_Footswitch_Controller.ino
 Created:	8/15/2020 1:54:55 PM
 Author:	Will
*/

/**
* The user interface will operate in two modes, send CC and send PC, these will be abstracted to act like they are specific 
* to the Darkglass Microtubes 900 V2 MIDI mapping I have set up, so the UI will be labelled as such. 
*/

#include <LiquidCrystal_I2C.h>
#include "MIDI.h"
#include "RGBLED.h"
#include <Wire.h>
#include "RGBLED.h"
#include "Hardware_Defs.h"
#include "FlexPrimeMidiCCDefs.h"


RGBLED RGBLEDs[4];
//Footswitch Footswitches[2];

MIDI midi = MIDI();

uint8_t nCurrentMIDIChannel = 1;
uint8_t nCurrentPCValue = 6;
uint8_t nLEDBrightness = 127;
uint8_t nCurrentImpluse = 1;
bool bCompressorOn = true;

unsigned int nLastPressedSwitch = 0;

volatile bool bHoldingSwitch5 = false;

bool bFootswitchlastHeld = false;

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4);

unsigned long int DISPLAY_REFRESH_TIME = 30;
unsigned long int nLastRefreshTime = 0;
unsigned long int nCurrentRefreshTime = 0;

// Setup LCD 
//LCDInterface lcd = LCDInterface(0x27, 20, 4);

// the setup function runs once when you press reset or power the board
void setup() 
{
    // For MIDI Comms 
    Serial.begin(MIDI_BAUD_RATE);

    InitLEDs();

    lcd.init();
    lcd.backlight();
    
    StartupSequence();
    delay(1500);
    
    attachInterrupt(digitalPinToInterrupt(HardwareDefinitions::Footswitches::Footswitch1), HandleFootSwitch1, CHANGE);
    attachInterrupt(digitalPinToInterrupt(HardwareDefinitions::Footswitches::Footswitch2), HandleFootSwitch2, CHANGE);
    attachInterrupt(digitalPinToInterrupt(HardwareDefinitions::Footswitches::Footswitch3), HandleFootSwitch3, CHANGE);
    attachInterrupt(digitalPinToInterrupt(HardwareDefinitions::Footswitches::Footswitch4), HandleFootSwitch4, CHANGE);

    // Footswitches 5 and 6 are not connected to interrupt pins, so they need to be polled
    pinMode(HardwareDefinitions::Footswitches::Footswitch5, INPUT);
    pinMode(HardwareDefinitions::Footswitches::Footswitch6, INPUT);

    // Mute the footswitch by default 
    HandleFootSwitch1();

    lcd.clear();
    UpdateDisplay();
}

void InitLEDs()
{
    RGBLED CRGBLED1 = RGBLED(HardwareDefinitions::LEDs::LED1);
    RGBLED CRGBLED2 = RGBLED(HardwareDefinitions::LEDs::LED2);
    RGBLED CRGBLED3 = RGBLED(HardwareDefinitions::LEDs::LED3);
    RGBLED CRGBLED4 = RGBLED(HardwareDefinitions::LEDs::LED4);

    RGBLEDs[0] = CRGBLED1;
    RGBLEDs[1] = CRGBLED2;
    RGBLEDs[2] = CRGBLED3;
    RGBLEDs[3] = CRGBLED4;
}

void ZeroLEDs()
{
    for (int i = 0; i < 4; ++i) RGBLEDs[i].SetRGBValues(0, 0, 0);
}

void UpdateDisplay()
{
        //lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(" Impulse  Compressor");

        // Update this line based on current parameters 
        lcd.setCursor(0, 1);
        if (nCurrentImpluse == 3)
        {
            lcd.print("  Bypass");
        }
        else
        {
            lcd.print("  Slot ");
            lcd.print(nCurrentImpluse + 1);
        }
        
        if (bCompressorOn)
        {
            lcd.print("      On");
        }
        else
        {
            lcd.print("     Off");
        }

        lcd.setCursor(0, 2);
        lcd.print("Mute             VMT");
        lcd.setCursor(0, 3);
        lcd.print("     Clean   B3K     ");
}

// Pointless, flashy light display, only exists for the purpose of showing off 
void StartupSequence()
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Darkglass Microtubes");
    lcd.setCursor(0, 1);
    lcd.print("      900 V2!");
    lcd.setCursor(0, 2);
    lcd.print("Custom Footswitch");
}

// the loop function runs over and over again until power down or reset
void loop() 
{
    HandleFootSwitch5();
    HandleFootSwitch6();

    for (auto i : RGBLEDs) i.UpdateLED();
    
    midi.SendMessage(CC, nCurrentMIDIChannel, 0, nCurrentPCValue);
    delay(10);
    midi.SendMessage(PROGRAM_CHANGE, nCurrentMIDIChannel, nCurrentPCValue);
}

void HandleFootSwitch1()
{
    nLastPressedSwitch = 0;

    UpdateLEDStates();
    GetMIDIPCValue();
    delay(HardwareDefinitions::HardwareTiming::DebounceTime);
}

void HandleFootSwitch2()
{
    nLastPressedSwitch = 1;

    UpdateLEDStates();
    GetMIDIPCValue();
    delay(HardwareDefinitions::HardwareTiming::DebounceTime);
}

void HandleFootSwitch3()
{   
    nLastPressedSwitch = 2;

    UpdateLEDStates();
    GetMIDIPCValue();
    delay(HardwareDefinitions::HardwareTiming::DebounceTime);
}

void HandleFootSwitch4()
{   
    nLastPressedSwitch = 3;
    UpdateLEDStates();
    GetMIDIPCValue();
    delay(HardwareDefinitions::HardwareTiming::DebounceTime);
}

// Tap to scroll presets left, hold for 1.5 seconds to switch to CC mode 
void HandleFootSwitch5()
{
    if ((digitalRead(HardwareDefinitions::Footswitches::Footswitch5) == HIGH) && (bHoldingSwitch5 == false))
    {
        // Move to the next impulse slot, 
        nCurrentImpluse++;
        if (nCurrentImpluse >= 4) nCurrentImpluse = 0;
        bHoldingSwitch5 = true;
        // Or wrap around back to slot one 
        UpdateDisplay();
        GetMIDIPCValue();
        UpdateLEDStates();
        
        delay(HardwareDefinitions::HardwareTiming::DebounceTime);
    }
    else
    {
        bHoldingSwitch5 = false;
    }
}

void HandleFootSwitch6()
{
    if (digitalRead(HardwareDefinitions::Footswitches::Footswitch6) == HIGH)
    {
        bCompressorOn = !bCompressorOn;
        UpdateDisplay();
        GetMIDIPCValue();
        UpdateLEDStates();
    }
    delay(HardwareDefinitions::HardwareTiming::DebounceTime);
}

void UpdateLEDStates()
{
    ZeroLEDs();
    switch (nCurrentImpluse)
    {
    case 0:
        RGBLEDs[nLastPressedSwitch].SetRGBValues(nLEDBrightness, 0, 0);
        break;
    case 1:
        RGBLEDs[nLastPressedSwitch].SetRGBValues(0, nLEDBrightness, 0);
        break;
    case 2:
        RGBLEDs[nLastPressedSwitch].SetRGBValues(0, 0, nLEDBrightness);
        break;
    case 3:
        RGBLEDs[nLastPressedSwitch].SetRGBValues(nLEDBrightness, nLEDBrightness, nLEDBrightness);
        break;
    default:
        break;
    }
}

uint8_t GetMIDIPCValue()
{
    nCurrentPCValue = 0;
    // Search MIDI codes 1-24
    if (!bCompressorOn) nCurrentPCValue += 24;

    // Choose correct impulse response
    nCurrentPCValue += (6 * nCurrentImpluse);
    
    // Choose current channel
    switch (nLastPressedSwitch)
    {
        // Mute
    case 0:
        break;
        // Clean
    case 1:
        nCurrentPCValue += 1;
        break;
    case 2:
        nCurrentPCValue += 3;
        break;
    case 3:
        nCurrentPCValue += 5;
        break;
    default:
        break;
    }
}