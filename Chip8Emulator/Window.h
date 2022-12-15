#ifndef WINDOW_H
#define WINDOW_H
#include <memory>
#include <string>
#include <SDL/SDL.h>

class Window
{
public:
	Window(std::string& title, uint32_t width, uint32_t height);
	~Window();

	Window(const Window& other) = delete;
	Window(Window&& other) = delete;
	Window& operator=(const Window& other) = delete;
	Window& operator=(const Window&& other) = delete;

	void Init();

private:
	void Draw();
	void Update();

	SDL_Window* m_pWindow{nullptr};
	SDL_Renderer* m_pRenderer{ nullptr };

	SDL_Event m_Event{};
	bool m_ApplicationIsRunning{true};
	float m_DeltaTime{};
};

#endif



