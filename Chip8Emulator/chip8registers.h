#ifndef CHIP_8_REGISTERS_H
#define CHIP_8_REGISTERS_H

#include <array>
#include "config.h"
#include <algorithm>

namespace CHIP_8
{
	// TODO: Convert to class with safe getters and setters
	struct Registers
	{
		// Our general purpose registers => Goes from V0 to VF
		std::array<uint8_t, CHIP8_REGISTER_COUNT> V{};

		// This register holds a memory address
		uint16_t I{};

		// Sound timer
		uint8_t SoundTimer{};

		// Delay timer
		uint8_t DelayTimer{};

		// Program counter
		uint16_t PC{};

		// Stack pointer
		uint8_t SP{};
	};
}

#endif