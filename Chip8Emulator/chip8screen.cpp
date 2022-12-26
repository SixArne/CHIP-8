#include "chip8screen.h"
#include <stdexcept>

void CHIP8::Screen::Set(int x, int y)
{
	IsInBounds(x, y);

	m_Pixels[y][x] = true;
}

bool CHIP8::Screen::IsSet(int x, int y)
{
	IsInBounds(x, y);

	return m_Pixels[y][x];
}

bool CHIP8::Screen::DrawSprite(int x, int y, Sprite& sprite)
{
	bool pixelCollision{false};

	for (int ly{}; ly < sprite.numBytes; ++ly)
	{
		// Get sprite byte
		uint8_t c = sprite.spriteMemLocation[ly];

		for (int lx{}; lx < 8; ++lx)
		{
			// Check if something to draw
			if ((c & (0b10000000 >> lx)) == 0)
			{
				continue;
			}

			auto& pixelCoordinate = m_Pixels[(ly + y) % CHIP8_HEIGHT][(lx + x) % CHIP8_WIDTH];

			if (pixelCoordinate)
			{
				pixelCollision = true;
			}

			pixelCoordinate ^= true;
		}

	}

	return pixelCollision;
}

void CHIP8::Screen::IsInBounds(int x, int y)
{
	if (x < 0 || x >= CHIP8_WIDTH || y < 0 || y >= CHIP8_HEIGHT)
	{
		throw std::runtime_error("Pixel coordinate out of screen");
	}
}
