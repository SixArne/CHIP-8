#ifndef CHIP8_KEYBOARD_H
#define CHIP8_KEYBOARD_H

#define KEY_IS_INVALID -1

// STL includes
#include <array>

// Emulator includes
#include "config.h"

namespace CHIP8
{
	class Keyboard
	{
	public:
		Keyboard();

		// These functions work with virtual keys (0-F keys)
		void KeyDown(int virtualKey);
		void KeyUp(int virtualKey);
		bool IsKeyDown(int virtualKey);

		// TODO: put private later
		int MapKey(uint8_t emulatorKey);

	private:

		std::array<bool, CHIP8_TOTAL_KEYS> m_Keyboard{};
		std::array<int, CHIP8_TOTAL_KEYS> m_KeyMap{};

		static void EnsureInBounds(int virtualKey);
	};
}

#endif




