#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "entity.h"
#include "GameEngine.h"

// Sigmoide

GameEngine::GameController::GameController()
{
	std::cout << "Instanciated GameController" << std::endl;
}

bool GameEngine::GameController::addEntity(Entity* e)
{
	entities.push_back(e);
	std::cout << "Added Entity. Allocating ID #" << std::endl;
}

bool GameEngine::GameController::removeEntity()
{
	std::cout << "Removed Entity" << std::endl;
}

bool GameEngine::GameController::addText(sf::Text* t)
{
	texts.push_back(t);
	std::cout << "Added Text. Allocating ID #" << std::endl;
}

std::vector<Entity*> GameEngine::GameController::getEntities()
{
	return entities;
}

void GameEngine::GameController::update()
{
	std::vector<Entity*>::iterator it = entities.begin();
	for(it; it != entities.end(); ++it)
	{
		(*it)->update();
	}
	/*
	std::vector<sf::Text*>::iterator it2 = texts.begin();
	for(it2; it2 != texts.end(); ++it2)
	{
		// (*it)->events();
		(*it2)->setString("Direction.x:" + std::to_string(entities[0]->getDirection().x));
		//WindowManager::GameWindow::getInstance().getWindow()->draw(**it2);
		//(*it2)->draw();
	}
	*/
}

void GameEngine::GameController::draw()
{
	//std::cout << entities.size() << std::endl;
	std::vector<Entity*>::iterator it = entities.begin();
	for(it; it != entities.end(); ++it)
	{
		// (*it)->events();
		(*it)->draw();
	}
	/*
	std::vector<sf::Text*>::iterator it2 = texts.begin();
	for(it2; it2 != texts.end(); ++it2)
	{
		// (*it)->events();
		WindowManager::gw->draw(**it2);
		//(*it2)->draw();
	}
	*/
}
