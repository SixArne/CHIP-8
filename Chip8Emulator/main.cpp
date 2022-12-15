#define SDL_MAIN_HANDLED
#include "Window.h"
#include "config.h"

int main()
{
	std::string windowTitle{ EMULATOR_WINDOW_TITLE };

	std::unique_ptr<Window> pWindow = std::make_unique<Window>(
		windowTitle,
		(uint32_t)CHIP8_WIDTH * EMULATOR_WINDOW_MULTIPLIER,
		(uint32_t)CHIP8_HEIGHT * EMULATOR_WINDOW_MULTIPLIER
	);

	pWindow->Init();

	return 0;
}
