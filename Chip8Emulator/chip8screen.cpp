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

void CHIP8::Screen::IsInBounds(int x, int y)
{
	if (x < 0 || x >= CHIP8_WIDTH || y < 0 || y >= CHIP8_HEIGHT)
	{
		throw std::runtime_error("Pixel coordinate out of screen");
	}
}
