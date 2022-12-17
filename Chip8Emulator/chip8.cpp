#include "chip8.h"
#include <memory>
//#include "chip8stack.h"
#include <iostream>

CHIP8::Emulator::Emulator()
{
	m_Memory = std::make_unique<Memory>();
	m_Registers = std::make_unique<Registers>();
	m_Stack = std::make_unique<Stack>();
}
