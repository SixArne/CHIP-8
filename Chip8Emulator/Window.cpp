#include "Window.h"
#include <chrono>
#include <functional>

Window::Window(std::string& title, uint32_t width, uint32_t height)
{
	m_pWindow.reset(SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN));
	m_pRenderer.reset(SDL_CreateRenderer(m_pWindow.get(), -1, SDL_TEXTUREACCESS_TARGET));
}

void Window::Init()
{
	while (m_ApplicationIsRunning)
	{
		const auto clock = std::chrono::high_resolution_clock();
		const auto start = clock.now();

		while (SDL_PollEvent(&m_Event) )
		{
			if (m_Event.type == SDL_QUIT)
			{
				m_ApplicationIsRunning = false;
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
	/*SDL_Rect r;
	r.x = 0;
	r.y = 0;
	r.w = 40;
	r.h = 40;
	SDL_RenderFillRect(m_pRenderer, &r);*/
}

void Window::Update()
{
	// custom update here
}
