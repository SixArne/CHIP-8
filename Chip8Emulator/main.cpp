#define SDL_MAIN_HANDLED
#include "Window.h"
#include "config.h"
#include "chip8.h"
#include <iostream>

int main()
{
	// Make chip-8 device
	std::unique_ptr<CHIP_8::CHIP_8> pDevice = std::make_unique<CHIP_8::CHIP_8>();
	
	// Set memory at location 0 to 55
	pDevice->GetMemory()->Set(0x0fff, 55);
	pDevice->GetRegisters()->V[0xA] = 5;

	/************************************************************************/
	/* Window creation                                                      */
	/************************************************************************/
	std::string windowTitle{ EMULATOR_WINDOW_TITLE };

	std::unique_ptr<Window> pWindow = std::make_unique<Window>(
		windowTitle,
		(uint32_t)CHIP8_WIDTH * EMULATOR_WINDOW_MULTIPLIER,
		(uint32_t)CHIP8_HEIGHT * EMULATOR_WINDOW_MULTIPLIER
	);

	pWindow->Init();

	return 0;
}
