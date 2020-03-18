#include "Game.h"
#include "TextureManager.h"
#include"Map.h"
#include"Components.h"





Map* map;

SDL_Renderer* Game::renderer = nullptr;

Manager manager;
auto& player(manager.addEntity());


Game::Game(){}
Game::~Game() {}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	int flags = 0;
	if (fullscreen) { flags = SDL_WINDOW_FULLSCREEN; }

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems initialized" << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (window)
		{
			std::cout << "Window created" << std::endl;

			renderer = SDL_CreateRenderer(window, -1, 0);
			if (renderer)
			{
				SDL_SetRenderDrawColor(renderer,255, 255, 255, 255);
				std::cout << "Renderer created" << std::endl;
				isRunning = true;
			}
			else { isRunning = false; }
			
		}

	}

	
	map = new Map();

	player.addComponent<PositionComponent>(100,500);
	player.addComponent<SpriteComponent>("assets/ssj.png");


	


}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	   case SDL_QUIT:
		isRunning = false;
		break;
	   
	default:
		break;
	}

}

void Game::update()
{
	
	count++;
//std::cout << count << std::endl;
manager.refresh();
manager.update();

}

void Game::render() {
	SDL_RenderClear(renderer);
	// this is where we  add stuff to render-whats rendered first will be below in the window, so map is above player
	map->DrawMap();
	manager.draw();
	SDL_RenderPresent(renderer);

}
void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned" << std::endl;
}