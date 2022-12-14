#ifndef CHIP8_H
#define CHIP8_H

// STL includes
#include <memory>

// Emulator includes
#include "config.h"
#include "chip8memory.h"
#include "chip8registers.h"
#include "chip8stack.h"
#include "chip8keyboard.h"
#include "chip8screen.h"

namespace CHIP8 {
	class Emulator
	{
	public:
		Emulator();

		Memory* GetMemory() { return m_Memory.get(); };
		Registers* GetRegisters() { return m_Registers.get(); };
		Stack* GetStack() { return m_Stack.get(); };
		Keyboard* GetKeyBoard() { return m_Keyboard.get(); };
		Screen* GetScreen() { return m_Screen.get(); };

	private:
		std::unique_ptr<Memory> m_Memory{};
		std::unique_ptr<Registers> m_Registers{};
		std::unique_ptr<Stack> m_Stack{};
		std::unique_ptr<Keyboard> m_Keyboard{};
		std::unique_ptr<Screen> m_Screen{};

		const std::array<uint8_t, 80> m_DefaultCharacterSet{
			0xf0, 0x90, 0x90, 0x90, 0xf0,
			0x20, 0x60, 0x20, 0x20, 0x70,
			0xf0, 0x10, 0xf0, 0x80, 0xf0,
			0xf0, 0x10, 0xf0, 0x10, 0xf0,
			0x90, 0x90, 0xf0, 0x10, 0x10,
			0xf0, 0x80,	0xf0, 0x10, 0xf0,
			0xf0, 0x80,	0xf0, 0x90, 0xf0,
			0xf0, 0x10, 0x20, 0x40, 0x40,
			0xf0, 0x90, 0xf0, 0x90, 0xf0,
			0xf0, 0x90, 0xf0, 0x10, 0xf0,
			0xf0, 0x90, 0xf0, 0x90, 0x90,
			0xe0, 0x90, 0xe0, 0x90, 0xe0,
			0xf0, 0x80, 0x80, 0x80, 0xf0,
			0xe0, 0x90, 0x90, 0x90, 0xe0,
			0xf0, 0x80, 0xf0, 0x80, 0xf0,
			0xf0, 0x80, 0xf0, 0x80, 0x80
		};
	};
}

#endif // CHIP8_8
