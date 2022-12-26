#ifndef CHIP8_SPRITE_H
#define CHIP8_SPRITE_H

#include "stdint.h"

namespace CHIP8
{
	struct Sprite
	{
		Sprite(uint8_t* spriteMemLocation, uint8_t numBytes)
			:spriteMemLocation{ spriteMemLocation }, numBytes{ numBytes } {}

		uint8_t* spriteMemLocation{};
		uint8_t numBytes{};
	};
}

#endif