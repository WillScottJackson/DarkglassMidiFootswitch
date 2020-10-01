# Darkglass Microtubes 900 V2 Custom MIDI Footswitch 
# By William Scott-Jackson

## Introduction 
This was a project of mine while on furlough during the COVID 19 pandemic. I wanted to squeeze more utility out of my Darkglass Microtubes 900 V2 bass amplifier head and didn't see many ways to accomplish that. The first was their proprietary **Super Intelligent Footswitch** which is expensive and offers very few functions when compared to what the amp could be capable of. The alternative was to buy a MIDI footswitch and program it to work with the amp and its built in MIDI output. The trouble with most MIDI footswitches is that they are USB powered and I wanted this footswitch to integrate onto my pedalboard without having to include more cables for power and the like. So I saw this as an opportunity to design and build my own footswitch. 

## Design 
The unit was designed to be driven by the **Arduino Mega 2560** development board, due to having numerous hardware interrupt pins available. In order to make this a responsive unit in a studio environment, hardware interrupts were preferable for real time switching of new MIDI messages rather than continuous polling of all the switches. I decided to put and LCD for some feedback, with the option to have the unit programmable at a later date. 
The circuit schematic for the unit is as shown here:
![alt text](https://github.com/WillScottJackson/DarkglassMidiFootswitch/blob/main/MIDI-Switch_schem.png?raw=true)

In terms of user interface, I didn't want a generic MIDI footswitch type of interface, instead I wanted something specific to the Microtubes 900 V2, and try to make it intuitive for when I'm using for recording, rehearsing or playing live. I opted to use a mixture of an LCD, RBG LEDs and footswitches to do all of the neccesary interactions. The footswitches and their function were determined by how accessible they would need to be in a typical usage scenario. The switches for clean, B3K, VMT and mute were made to be the easiest to access. The footswitches at the front have indicator LEDs to let me know what the current state of the pedal is. I opted for RGB LEDs so that the colour could be changed for more articulation when communicating to me what the state of the footswitch is. I used the colour of the LEDs to tell me which of the three on board impulse responses is currently loaded. 

## Construction 
The unit was built into a generic enclosure you can get from most electronics stockists, but it was reinforced with a fibre glass panel, with the holes for the switches, LCD and mounting holes machined out. 

When handling power distrubution, I wanted to use my existing power brick, which would output 9 volts from a centre negative power supply, but the Arduino is centre positive. So the power and ground had to be swapped on the way into the Arduino power. The Arduino board regulates down to 5 volts from input voltages up to 12 volts, so additional circuitry was not neccessary. 
Here are some images of the unit after construction: 
![alt text](https://github.com/WillScottJackson/DarkglassMidiFootswitch/blob/main/Photos/20201001_225513.jpg?raw=true)
![alt text](https://github.com/WillScottJackson/DarkglassMidiFootswitch/blob/main/Photos/20201001_225522.jpg?raw=true)
![alt text](https://github.com/WillScottJackson/DarkglassMidiFootswitch/blob/main/Photos/20201001_225620.jpg?raw=true)
![alt text](https://github.com/WillScottJackson/DarkglassMidiFootswitch/blob/main/Photos/20201001_225626.jpg?raw=true)
![alt text](https://github.com/WillScottJackson/DarkglassMidiFootswitch/blob/main/Photos/20201001_225635.jpg?raw=true)
![alt text](https://github.com/WillScottJackson/DarkglassMidiFootswitch/blob/main/Photos/20201001_225656.jpg?raw=true)
![alt text](https://github.com/WillScottJackson/DarkglassMidiFootswitch/blob/main/Photos/20201001_225702.jpg?raw=true)

## Demonstration
A quick and dirty Youtube video of this unit in action has been uploaded [here](https://www.youtube.com/watch?v=9cLe0gX9iao)

And finally, here is the unit in its natural environment, with the rest of my gear: 
![alt text](https://github.com/WillScottJackson/DarkglassMidiFootswitch/blob/main/Photos/20200930_155720.jpg?raw=true)
