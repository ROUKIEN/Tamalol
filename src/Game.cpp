#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#include "entity.h"
#include "tamagotchi.h"
#include "GameEngine.h"

namespace Game 
{
	sf::Clock * deltaTime;
	sf::Vector2f gravity(0.0f, 0.1f);
}

namespace GameEngine
{
	GameEngine::GameController * gc;
}

namespace WindowManager
{
	sf::RenderWindow * gw;
	WindowManager::ResourceManager * rm;
}

Game::Game::~Game()
{
	std::cout << "Destroyed Game" << std::endl;
}

void Game::Game::init()
{
	GameEngine::gc = new GameEngine::GameController();
	WindowManager::rm = new WindowManager::ResourceManager();

	WindowManager::gw = new sf::RenderWindow(sf::VideoMode(800,600), "Tamalol v0.1.0a");
	deltaTime = new sf::Clock();

	Tamagotchi* p;
	Tamagotchi* p2;

	p = new Tamagotchi();
	p2 = new Tamagotchi();
	
	p->togglePlayable();
	
	GameEngine::gc->addEntity(p);
	GameEngine::gc->addEntity(p2);

	run();
}

void Game::Game::start()
{
	running = true;
}

void Game::Game::pause()
{
	paused = true;
}

void Game::Game::stop()
{
	running = false;
}

/**
 * Main game loop
 */
void Game::Game::run()
{
	std::cout << "Game Launched" << std::endl;
	while(WindowManager::gw->isOpen())
	{
		sf::Color bg_color(87,123,255);
		WindowManager::gw->clear(bg_color);
		checkEvents();
		GameEngine::gc->update();
		GameEngine::gc->draw();
		WindowManager::gw->display();
		
	}
}

/**
 * Manage game events
 */
void Game::Game::checkEvents()
{
	sf::Event e;
	std::vector<Entity*> entities = GameEngine::gc->getEntities();
	while(WindowManager::gw->pollEvent(e))
	{
		if(e.type == sf::Event::Closed)
		{
			WindowManager::gw->close();
		}
		std::vector<Entity*>::iterator it = entities.begin();
		for(it; it != entities.end(); ++it)
		{
			if((*it)->isPlayable())
				(*it)->events(e);
		}
	}
}
