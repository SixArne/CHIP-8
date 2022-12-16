#ifndef CHIP8_H
#define CHIP8_H

// STL includes
#include <memory>

// Emulator includes
#include "config.h"
#include "chip8memory.h"
#include "chip8registers.h"


namespace CHIP_8
{
	class CHIP_8 
	{
	public:
		CHIP_8();

		Memory* GetMemory() { return m_Memory.get(); };
		Registers* GetRegisters() { return m_Registers.get(); };

	private:
		std::unique_ptr<Memory> m_Memory{};
		std::unique_ptr<Registers> m_Registers{};
	};
}

#endif // CHIP8_8
