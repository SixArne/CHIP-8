#ifndef CHIP8_H
#define CHIP8_H

// STL includes
#include <memory>

// Emulator includes
#include "config.h"
#include "chip8memory.h"
#include "chip8registers.h"
#include "chip8stack.h"

namespace CHIP8 {
	class Emulator
	{
	public:
		Emulator();

		Memory* GetMemory() { return m_Memory.get(); };
		Registers* GetRegisters() { return m_Registers.get(); };
		Stack* GetStack() { return m_Stack.get(); };

	private:
		std::unique_ptr<Memory> m_Memory{};
		std::unique_ptr<Registers> m_Registers{};
		std::unique_ptr<Stack> m_Stack{};
	};
}

#endif // CHIP8_8
