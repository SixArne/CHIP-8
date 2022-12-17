#include "chip8stack.h"
#include <stdexcept>

#include "chip8.h"

void CHIP8::Stack::StackInBounds(Emulator* emulator)
{
	if (emulator->GetRegisters()->SP >= CHIP8_TOTAL_STACK_DEPTH)
	{
		throw std::runtime_error("Stack pointer higher than maximum stack depth");
	}
}

CHIP8::Stack::Stack()
{
}

void CHIP8::Stack::Push(Emulator* m_Emulator, uint16_t value)
{
    StackInBounds(m_Emulator);

    // Push value on stack
    m_Stack[m_Emulator->GetRegisters()->SP] = value;
    
    // Increment stack pointer
    m_Emulator->GetRegisters()->SP += 1;
}

uint16_t CHIP8::Stack::Pop(Emulator* m_Emulator)
{
    // Decrement stack pointer
    m_Emulator->GetRegisters()->SP -= 1;

    StackInBounds(m_Emulator);

    // Return value from stack
    uint16_t value = m_Stack[m_Emulator->GetRegisters()->SP];
    return value;
}
