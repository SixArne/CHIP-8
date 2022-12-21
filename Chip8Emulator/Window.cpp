#include "Window.h"
#include <chrono>
#include <functional>
#include <iostream>
#include "chip8.h"

Window::Window(std::string& title, uint32_t width, uint32_t height)
{
	m_pWindow.reset(SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN));
	m_pRenderer.reset(SDL_CreateRenderer(m_pWindow.get(), -1, SDL_TEXTUREACCESS_TARGET));

	// Emulator instance
	m_pEmulator = std::make_unique<CHIP8::Emulator>();
	m_pEmulator->GetScreen()->Set(0, 0);
}

void Window::Init()
{
	while (m_ApplicationIsRunning)
	{
		const auto clock = std::chrono::high_resolution_clock();
		const auto start = clock.now();

		while (SDL_PollEvent(&m_Event) )
		{
			switch (m_Event.type)
			{
			case SDL_QUIT:
				m_ApplicationIsRunning = false;
				break;
			case SDL_KEYDOWN:
				{
					int vKey = m_pEmulator->GetKeyBoard()->MapKey(m_Event.key.keysym.sym);
					if (vKey != KEY_IS_INVALID)
					{
						m_pEmulator->GetKeyBoard()->KeyDown(vKey);
					}
				}
			
				break;
			case SDL_KEYUP:
				{
					int vKey = m_pEmulator->GetKeyBoard()->MapKey(m_Event.key.keysym.sym);
					if (vKey != KEY_IS_INVALID)
					{
						m_pEmulator->GetKeyBoard()->KeyUp(vKey);
					}
				}

				break;
			}
		}

		SDL_SetWindowTitle(m_pWindow.get(), std::to_string(1.f / m_DeltaTime).c_str());
		SDL_SetRenderDrawColor(m_pRenderer.get(), 0, 0, 0, 0);
		SDL_RenderClear(m_pRenderer.get());
		SDL_SetRenderDrawColor(m_pRenderer.get(), 255, 255, 255, 0);

		/************************************************************************/
		/* Update																*/
		/************************************************************************/
		Update();

		/************************************************************************/
		/* Render																*/
		/************************************************************************/
		Draw();
		SDL_RenderPresent(m_pRenderer.get());

		const auto end = clock.now();
		m_DeltaTime = std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count();
	}

	SDL_Quit();
}

void Window::Draw()
{
	for (int x{}; x < CHIP8_WIDTH; ++x)
	{
		for (int y{}; y < CHIP8_HEIGHT; ++y)
		{
			if (m_pEmulator->GetScreen()->IsSet(x, y))
			{
				SDL_Rect r;
				r.x = x * EMULATOR_WINDOW_MULTIPLIER;
				r.y = y * EMULATOR_WINDOW_MULTIPLIER;
				r.w = EMULATOR_WINDOW_MULTIPLIER;
				r.h = EMULATOR_WINDOW_MULTIPLIER;
				SDL_RenderFillRect(m_pRenderer.get(), &r);
			}
		}
	}
}

void Window::Update()
{
	// Custom update logic
}
