#include "chip8.h"

// STL includes
#include <memory>
#include <iostream> 

CHIP8::Emulator::Emulator()
{
	m_Memory = std::make_unique<Memory>();
	m_Registers = std::make_unique<Registers>();
	m_Stack = std::make_unique<Stack>();
	m_Keyboard = std::make_unique<Keyboard>();
	m_Screen = std::make_unique<Screen>();

	// Copy over data
	std::memcpy(
		m_Memory->GetMemoryUnsafe().data(),
		m_DefaultCharacterSet.data(), 
		sizeof(m_DefaultCharacterSet)
	);
}
