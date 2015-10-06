#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

#include "GameEngine.h"
#include "EventsManager.h"
#include "entity.h"
#include "tamagotchi.h"

int main()
{
	float lastTime = 0;
	
	Game::Game j;//(WindowManager::GameWindow::getInstance(), GameEngine::GameController::getInstance());
	j.init();
	j.start();
	
	return 0;
}
