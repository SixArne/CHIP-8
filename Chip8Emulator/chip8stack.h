#ifndef CHIP8_STACK_H
#define CHIP8_STACK_H

// STL includes
#include <array>
#include <memory>

// Emulator includes
#include "config.h"

namespace CHIP8 {
	// Forward declare here
	class Emulator;

	class Stack
	{
	public:
		Stack();

		void Push(Emulator* m_Emulator, uint16_t value);
		uint16_t Pop(Emulator* m_Emulator);

	private:
		std::array<uint16_t, CHIP8_TOTAL_STACK_DEPTH> m_Stack{};
		Emulator* m_Emulator{};

		// Helper function
		static void StackInBounds(Emulator* emulator);
	};
}

#endif
