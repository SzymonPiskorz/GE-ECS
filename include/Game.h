#include <SDL.h>
#include <iostream>
#include <string>
#include <cstdint>
#include <SDL_image.h>
#include <SDL_ttf.h>

class Game
{
public:

	Game();
	~Game();
	void run();

private:

	void processEvents(SDL_Event t_e);
	void update();
	void render();

	void cleanUp();

	bool m_gameIsRunning;

	const int WINDOW_WIDTH{ 640 };
	const int WINDOW_HEIGHT{ 480 };

	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
};