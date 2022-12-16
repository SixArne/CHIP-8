#ifndef WINDOW_H
#define WINDOW_H
#include <memory>
#include <string>
#include <SDL/SDL.h>

class Window
{
public:
	Window(std::string& title, uint32_t width, uint32_t height);
	~Window() = default;

	Window(const Window& other) = delete;
	Window(Window&& other) = delete;
	Window& operator=(const Window& other) = delete;
	Window& operator=(const Window&& other) = delete;

	void Init();

private:
	void Draw();
	void Update();

	struct SDL_DELETER
	{
		void operator()(SDL_Window* ptr)	{ if (ptr) SDL_DestroyWindow(ptr); };
		void operator()(SDL_Renderer* ptr)	{ if (ptr) SDL_DestroyRenderer(ptr); };
	};

	std::unique_ptr<SDL_Window, SDL_DELETER> m_pWindow;
	std::unique_ptr<SDL_Renderer, SDL_DELETER> m_pRenderer;

	SDL_Event m_Event{};
	bool m_ApplicationIsRunning{true};
	float m_DeltaTime{};
};

#endif



