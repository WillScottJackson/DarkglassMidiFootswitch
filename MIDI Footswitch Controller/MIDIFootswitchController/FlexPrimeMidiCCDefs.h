#pragma once
#pragma pack

#include "MidiCC.h"

// Can undefine if we're taking up too much space on the sketch 
#define FEATURE_FOOTSWITCHES
#define FEATURE_LOOPER
#define FEATURE_BLOCKTOGGLES
#define FEATURE_PRACTICETOOL
#define FEATURE_METRONOME

/* MIDI CCs documented https://cdn.inmusicbrands.com/HeadRush/FW/4/Finalized%20User%20Guides/HeadRush%20Flex%20Prime%20-%20User%20Guide%20-%20v4.0.0.pdf */
namespace HeadRushFlexPrimeMidiCC
{

#ifdef FEATURE_FOOTSWITCHES
	namespace Footswitches
	{
		static constexpr MidiCC ExpressionPedal			{ "Expression Pedal",			1 };
		static constexpr MidiCC Footswitch1				{ "Footswitch 1",				49 };
		static constexpr MidiCC Footswitch2				{ "Footswitch 2",				50 };
		static constexpr MidiCC Footswitch3				{ "Footswitch 3",				51 };
		static constexpr MidiCC TapTempo				{ "Tap Tempo",					64 };
	}
#endif

#ifdef FEATURE_LOOPER
	namespace Looper
	{
		static constexpr MidiCC LooperHalfSpeed			{ "Looper 1/2 Speed",			65 };
		static constexpr MidiCC LooperDoubleSpeed		{ "Looper 2X Speed",			66 };
		static constexpr MidiCC LooperHalfLength		{ "Looper 1/2 Loop",			67 };
		static constexpr MidiCC LooperDobuleLength		{ "Looper 2X Loop",				68 };
		static constexpr MidiCC LooperStartStop			{ "Looper Start/Stop",			69 };
		static constexpr MidiCC LooperRecord			{ "Looper Record",				70 };
		static constexpr MidiCC LooperInsert			{ "Looper Insert",				71 };
		static constexpr MidiCC LooperPeel				{ "Looper Peel",				72 };
		static constexpr MidiCC LooperMute				{ "Looper Mute",				73 };
		static constexpr MidiCC LooperReverse			{ "Looper Reverse",				74 };
	}
#endif

#ifdef FEATURE_BLOCKTOGGLES
	namespace BlockToggles
	{
		static constexpr MidiCC Block1Toggle			{ "Block 1 Toggle ON/OFF",		75 };
		static constexpr MidiCC Block2Toggle			{ "Block 2 Toggle ON/OFF",		76 };
		static constexpr MidiCC Block3Toggle			{ "Block 3 Toggle ON/OFF",		77 };
		static constexpr MidiCC Block4Toggle			{ "Block 4 Toggle ON/OFF",		78 };
		static constexpr MidiCC Block5Toggle			{ "Block 5 Toggle ON/OFF",		79 };
		static constexpr MidiCC Block6Toggle			{ "Block 6 Toggle ON/OFF",		80 };
		static constexpr MidiCC Block7Toggle			{ "Block 7 Toggle ON/OFF",		81 };
		static constexpr MidiCC Block8Toggle			{ "Block 8 Toggle ON/OFF",		82 };
		static constexpr MidiCC Block9Toggle			{ "Block 9 Toggle ON/OFF",		83 };
		static constexpr MidiCC Block10Toggle			{ "Block 10 Toggle ON/OFF",		84 };
		static constexpr MidiCC Block11Toggle			{ "Block 11 Toggle ON/OFF",		85 };
		static constexpr MidiCC Block12Toggle			{ "Block 12 Toggle ON/OFF",		86 };
		static constexpr MidiCC Block13Toggle			{ "Block 13 Toggle ON/OFF",		87 };
		static constexpr MidiCC Block14Toggle			{ "Block 14 Toggle ON/OFF",		88 };
	}
#endif

#ifdef FEATURE_PRACTICETOOL
	namespace PracticeTool
	{
		static constexpr MidiCC PracticeToolOpen		{ "Practice Tool Open",			102 };
		static constexpr MidiCC PracticeToolPlay		{ "Practice Tool Play",			103 };
		static constexpr MidiCC PracticeToolVolumeDown	{ "Practice Tool Volume Down",	104 };
		static constexpr MidiCC PracticeToolVolumeUp	{ "Practice Tool Volume Up",	105 };
		static constexpr MidiCC PracticeToolLoopIn		{ "Practice Tool Loop In",		106 };
		static constexpr MidiCC PracticeToolLoopOut		{ "Practice Tool Loop Out",		107 };
		static constexpr MidiCC PracticeToolSpeedDown	{ "Practice Tool Speed Down",	108 };
		static constexpr MidiCC PracticeToolSpeedUp		{ "Practice Tool Speed Up",		109 };
		static constexpr MidiCC PracticeToolPitchDown	{ "Practice Tool Pitch Down",	110 };
		static constexpr MidiCC PracticeToolPitchUp		{ "Practice Tool Pitch Up",		111 };
		static constexpr MidiCC PracticeToolPrevious	{ "Practice Tool Previous",		112 };
		static constexpr MidiCC PracticeToolNext		{ "Practice Tool Next",			113 };
		static constexpr MidiCC PracticeToolLoopOnOff	{ "Practice Tool Loop On/Off",	114 };
	}
#endif

#ifdef FEATURE_METRONOME
	namespace Metronome
	{
		static constexpr MidiCC MetronomeOn				{ "Metronome On",				115 };
	}
#endif
}