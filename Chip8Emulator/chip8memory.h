#ifndef CHIP8_MEMORY_H
#define CHIP8_MEMORY_H

#include <array>
#include "config.h"

namespace CHIP8 {
	class Memory
	{
	public:
		Memory();
		~Memory();

		void Set(int32_t index, uint8_t value);
		std::array<uint8_t, CHIP8_MEMORY_SIZE>& GetMemoryUnsafe() { return m_Memory; };
		uint8_t Get(int32_t index);

	private:
		std::array<uint8_t, CHIP8_MEMORY_SIZE> m_Memory{};

		// Checker function
		static bool CheckIfInBounds(int32_t);
	};
}

#endif

