#ifndef CHIP8_SCREEN_H
#define CHIP8_SCREEN_H

// STL includes
#include <array>

// Emulator includes
#include "config.h"
#include "chip8sprite.h"

namespace CHIP8
{
	class Screen
	{
	public:
		void Set(int x, int y);
		bool IsSet(int x, int y);
		bool DrawSprite(int x, int y, Sprite& sprite);

	private:
		std::array<std::array<bool, CHIP8_WIDTH>, CHIP8_HEIGHT> m_Pixels{};

		static void IsInBounds(int x, int y);
	};
}

#endif