#include "chip8.h"
#include <memory>

CHIP_8::CHIP_8::CHIP_8()
{
	m_Memory = std::make_unique<Memory>(Memory());
	m_Registers = std::make_unique<Registers>(Registers());
}
