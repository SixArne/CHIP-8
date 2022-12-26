#include "chip8memory.h"
#include <stdexcept>

CHIP8::Memory::Memory()
{
}

CHIP8::Memory::~Memory()
{
}

void CHIP8::Memory::Set(int32_t index, uint8_t value)
{
	// Bound check
	CheckIfInBounds(index);
	
	// Set memory
	m_Memory[index] = value;
}

uint8_t* CHIP8::Memory::Get(int32_t index)
{
	// Bound check
	CheckIfInBounds(index);

	// Get memory
	return &m_Memory[index];
}

bool CHIP8::Memory::CheckIfInBounds(int32_t index)
{
	const bool isValid = (index >= 0 && index < CHIP8_MEMORY_SIZE);
	if (!isValid)
	{
		throw std::runtime_error("Array index out of bounds");
	}

	return isValid;
}
