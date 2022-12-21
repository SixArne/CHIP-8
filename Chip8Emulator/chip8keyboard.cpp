#include "chip8keyboard.h"

#include <SDL/SDL.h>
#include <stdexcept>

CHIP8::Keyboard::Keyboard()
	: m_KeyMap{
		SDLK_0, SDLK_1, SDLK_2, SDLK_3, SDLK_4, SDLK_5,
		SDLK_6, SDLK_7, SDLK_8, SDLK_9, SDLK_a, SDLK_b,
		SDLK_c, SDLK_d, SDLK_e, SDLK_f,
	}
{	
}

void CHIP8::Keyboard::KeyDown(int virtualKey)
{
	EnsureInBounds(virtualKey);

	m_Keyboard[virtualKey] = true;
}

void CHIP8::Keyboard::KeyUp(int virtualKey)
{
	EnsureInBounds(virtualKey);

	m_Keyboard[virtualKey] = false;
}

bool CHIP8::Keyboard::IsKeyDown(int virtualKey)
{
	EnsureInBounds(virtualKey);

	return m_Keyboard[virtualKey]; 
}

int CHIP8::Keyboard::MapKey(uint8_t emulatorKey)
{
	for (int i = 0; i < CHIP8_TOTAL_KEYS; ++i)
	{
		if (m_KeyMap[i] == emulatorKey)
		{
			return i;
		}
	}

	return -1;
}

void CHIP8::Keyboard::EnsureInBounds(int virtualKey)
{
	if (virtualKey < 0 || virtualKey >= CHIP8_TOTAL_KEYS)
	{
		throw std::runtime_error("Given key not in bounds");
	}
}
