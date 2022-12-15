#include "Window.h"
#include <chrono>
#include <functional>

Window::Window(std::string& title, uint32_t width, uint32_t height)
{
	m_pWindow = SDL_CreateWindow(title.c_str(),
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		width,
		height,
		SDL_WINDOW_SHOWN
	);
	
	m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_TEXTUREACCESS_TARGET);
}

Window::~Window()
{
	if (m_pWindow != nullptr)
	{
		SDL_DestroyWindow(m_pWindow);
	}

	if (m_pRenderer != nullptr)
	{
		SDL_DestroyRenderer(m_pRenderer);
	}
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

		SDL_SetWindowTitle(m_pWindow, std::to_string(1.f / m_DeltaTime).c_str());
		SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 0);
		SDL_RenderClear(m_pRenderer);
		SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 0);

		Update();

		/************************************************************************/
		/* Render																*/
		/************************************************************************/
		Draw();
		SDL_RenderPresent(m_pRenderer);

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
	
	// This needs to be here, otherwise memory leak appears
	
}

void Window::Update()
{
	// custom update here
}
