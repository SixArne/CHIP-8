#define SDL_MAIN_HANDLED
#include "Window.h"
#include "config.h"
#include "chip8.h"
#include <iostream>

int main()
{
	// Make chip-8 device
	std::unique_ptr<CHIP8::Emulator> pDevice = std::make_unique<CHIP8::Emulator>();
	
	pDevice->GetRegisters()->SP = 0;
	pDevice->GetStack()->Push(pDevice.get() , 0xff);
	pDevice->GetStack()->Push(pDevice.get(), 0xaa);

	printf("%x ", pDevice->GetStack()->Pop(pDevice.get()));
	printf("%x ", pDevice->GetStack()->Pop(pDevice.get()));

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
