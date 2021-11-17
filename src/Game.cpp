#include "../include/Game.h"

Game::Game() :
	m_gameIsRunning{ false }
{
	SDL_Init(SDL_INIT_VIDEO);

	m_window = SDL_CreateWindow("SFML to SDL",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		SDL_WINDOW_SHOWN);
	m_renderer = SDL_CreateRenderer(m_window,
		-1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);


	m_compList.push_back(new HealthComponent(100));  //0
	m_compList.push_back(new HealthComponent(150));
	m_compList.push_back(new HealthComponent(50));

	m_compList.push_back(new PositionComponent(10.0f, 10.0f)); //3
    m_compList.push_back(new PositionComponent(90.0f, 90.0f));
    m_compList.push_back(new PositionComponent(50.0f, 10.0f));
	m_compList.push_back(new PositionComponent(10.0f, 50.0));

    m_compList.push_back(new InputComponent(e)); //7

	m_player.addComponent(m_compList.at(0));
    m_player.addComponent(m_compList.at(3));
    m_player.addComponent(m_compList.at(7));

    m_villan.addComponent(m_compList.at(1));
    m_villan.addComponent(m_compList.at(4));

    m_cortana.addComponent(m_compList.at(2));
    m_cortana.addComponent(m_compList.at(5));

    m_dinkyDi.addComponent(m_compList.at(6));

	m_healthSystem.addEntity(m_player);
	m_healthSystem.addEntity(m_villan);
	m_healthSystem.addEntity(m_cortana);

	m_controlSystem.addEntity(m_player);

	m_aiSystem.addEntity(m_cortana);
	m_aiSystem.addEntity(m_villan);
	m_aiSystem.addEntity(m_dinkyDi);

	m_renderSystem.addEntity(m_player);
	m_renderSystem.addEntity(m_cortana);
	m_renderSystem.addEntity(m_villan);
	m_renderSystem.addEntity(m_dinkyDi);
}

Game::~Game()
{
	cleanUp();
}

void Game::run()
{

	m_gameIsRunning = true;
	

	while (m_gameIsRunning)
	{
		processEvents(e);
		update();
		render();
	}

	cleanUp();
}

void Game::processEvents(SDL_Event t_e)
{
	// simple event loop
	while (SDL_PollEvent(&t_e) != 0)
	{
		if (t_e.type == SDL_QUIT)
		{
			m_gameIsRunning = false;
		}

		// checks if the escape key is pressed down
		if (t_e.type == SDL_KEYDOWN && t_e.key.keysym.sym == SDLK_ESCAPE)
		{
			m_gameIsRunning = false;
		}
	}
}

void Game::update()
{
	m_healthSystem.update();
	m_controlSystem.update();
	m_aiSystem.update();
	m_healthSystem.update();
}

void Game::render()
{
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    m_renderSystem.render(m_renderer);

    SDL_RenderPresent(m_renderer);
}

void Game::cleanUp()
{
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	m_window = nullptr;
	m_renderer = nullptr;

	IMG_Quit();
	SDL_Quit();
}