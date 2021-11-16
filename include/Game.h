#include <SDL.h>
#include <iostream>
#include <string>
#include <cstdint>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "System.h"

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
	SDL_Event e{};

	ControlSystem m_controlSystem;
	RenderSystem m_renderSystem;
	AISystem m_aiSystem;
	HealthSystem m_healthSystem;

	Entity m_player;
	Entity m_villan;
	Entity m_cortana;
	Entity m_dinkyDi;

	std::vector<Component*> m_compList;
};