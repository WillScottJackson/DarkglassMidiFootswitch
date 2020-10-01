# Darkglass Microtubes 900 V2 Custom MIDI Footswitch 
# By William Scott-Jackson

## Introduction 
This was a project of mine while on furlough during the COVID 19 pandemic. I wanted to squeeze more utility out of my Darkglass Microtubes 900 V2 bass amplifier head and didn't see many ways to accomplish that. The first was their proprietary **Super Intelligent Footswitch** which is expensive and offers very few functions when compared to what the amp could be capable of. The alternative was to buy a MIDI footswitch and program it to work with the amp and its built in MIDI output. The trouble with most MIDI footswitches is that they are USB powered and I wanted this footswitch to integrate onto my pedalboard without having to include more cables for power and the like. So I saw this as an opportunity to design and build my own footswitch. 

## Design 
The unit was designed to be driven by the **Arduino Mega 2560** development board, due to having numerous hardware interrupt pins available. In order to make this a responsive unit in a studio environment, hardware interrupts were preferable for real time switching of new MIDI messages rather than continuous polling of all the switches. I decided to put and LCD for some feedback, with the option to have the unit programmable at a later date. 
The circuit schematic for the unit is as shown here:
![alt text](https://github.com/WillScottJackson/DarkglassMidiFootswitch/blob/main/MIDI-Switch_schem.png?raw=true)

## Demonstration
A quick and dirty Youtube video of this unit in action has been uploaded [here](https://www.youtube.com/watch?v=9cLe0gX9iao)


