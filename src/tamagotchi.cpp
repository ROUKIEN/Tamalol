#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "GameEngine.h"
#include "EventsManager.h"
#include "entity.h"
#include "tamagotchi.h"

Tamagotchi::Tamagotchi()
{
	std::cout << "Created Tamagotchi" << std::endl;
	
	hunger = 0;
	cleanliness = 100;
	health = 100;

	hungerFactor = 1;
	alive = true;

	//xpos = 0;
	//ypos = 0;
	
	playable = false;

	timeFactor = 1.0;

	direction = sf::Vector2f(0.0f, 0.0f);

	float_factor = 0.0f;
	speed_factor = 1;
	max_speed = 2.0f;
	acceleration = 0.15f;
	deceleration = 0.89f;

	moving_left = false;
	moving_right = false;
	moving_up = false;
	moving_down = false;

	grv = 0.0f;

	//WindowManager::rm->loadFile("assets/tamalol.png");
	character.setTexture(*WindowManager::rm->loadFile("assets/tamalol.png"));
}

Tamagotchi::~Tamagotchi()
{
	std::cout << "Destroyed Tamagotchi" << std::endl;
}

void Tamagotchi::togglePlayable() 
{
	playable = !playable;
}

bool Tamagotchi::isPlayable()
{
	return playable;
}

int Tamagotchi::getHunger()
{
	return hunger;
}

int Tamagotchi::getCleanliness()
{
	return cleanliness;
}

int Tamagotchi::getHealth()
{
	return health;
}
/**
 * Updates the tamagotchi values
 */
void Tamagotchi::updateMetrics()
{
	//std::cout << "Let's go !" << std::endl;
	updateHunger();
	updateCleanliness();
	updateHealth();

	if(health <= 0)
		die();
}

/**
 * Updates the hunger rate
 */
void Tamagotchi::updateHunger()
{
	sf::Time h_time = hungerClock.getElapsedTime();
	if(timeFactor * h_time.asSeconds() > 3.0)
	{
		if(hunger >= 80)
		{
			health-=5;
		}
		hunger += hungerFactor;
		// std::cout << "New hunger value : "<< hunger << std::endl;
		hungerClock.restart();
	}
}

/**
 * Updates the cleanliness
 */
void Tamagotchi::updateCleanliness()
{
	sf::Time c_time = cleanlinessClock.getElapsedTime();
	if(timeFactor * c_time.asSeconds() > 1.0)
	{
		if(cleanliness <= 0)
		{
			cleanliness = 0;
			health -= 1;
		}
		else cleanliness -= 1;

		//std::cout << "Updated Cleanliness. New value : " << cleanliness << std::endl;
		cleanlinessClock.restart();
	}
}

/*
 * Updates health
 */
void Tamagotchi::updateHealth()
{
	sf::Time h_time = healthClock.getElapsedTime();
	if(timeFactor * h_time.asSeconds() > 1.0)
	{
		//std::cout << "Updated Health. New value : " << health << std::endl;
		healthClock.restart();
	}
}

/**
 * Kills the tamagotchi
 */
void Tamagotchi::die()
{
	alive = false;
}

/**
 * Checks if the tamagotchi is still alive
 */
bool Tamagotchi::isAlive()
{
	return alive;
}

void Tamagotchi::feed()
{
	std::cout << "FEED" << std::endl;
	hunger = 0;
	cleanliness -= 10;
}

void Tamagotchi::heal()
{
	std::cout << "HEAL" << std::endl;
	health = 100;
}

void Tamagotchi::clean()
{
	std::cout << "CLEAN" << std::endl;
	cleanliness = 100;
}

void Tamagotchi::move(sf::Vector2f direction) 
{

}

void Tamagotchi::draw()
{
	// character.draw();
	WindowManager::gw->draw(character);
}

void Tamagotchi::events(sf::Event& event)
{
	// std::cout << "Tamalol Events" << std::endl;

	if(event.type == sf::Event::KeyPressed)
	{
		//std::cout << "Key pressed" << std::endl;
		switch(event.key.code)
		{
			case sf::Keyboard::Left :
				moving = true;
				character.setTextureRect(sf::IntRect(64, 0, -64, 64));
				moving_left = true;
				break;

			case sf::Keyboard::Right :
				moving = true;
				moving_right = true;
				character.setTextureRect(sf::IntRect(0, 0, 64, 64));
				break;

			case sf::Keyboard::Up :
				moving = true;
				moving_up = true;
				break;

			case sf::Keyboard::Down :
				moving = true;
				moving_down = true;
				break;
		}
	}
	else if(event.type == sf::Event::KeyReleased)
	{
		//std::cout << "Key released" << std::endl;
		switch(event.key.code)
		{
			case sf::Keyboard::Left :
				moving_left = false;
				break;

			case sf::Keyboard::Right :
				moving_right = false;
				break;

			case sf::Keyboard::Up :
				moving_up = false;
				break;

			case sf::Keyboard::Down :
				moving_down = false;
				break;
		}
	}
}

sf::Vector2f Tamagotchi::getDirection()
{
	return direction;
}

void Tamagotchi::update()
{

	if(moving_left)
	{
		direction += sf::Vector2f(-(acceleration+deceleration) * speed_factor, 0.0f);
		//std::cout << "Moving left" << std::endl;
	}
	if(moving_right)
	{
		direction += sf::Vector2f((acceleration+deceleration) * speed_factor, 0.0f);
	}
	if(moving_up)
	{
		direction += sf::Vector2f(0.0f, -(acceleration*10+deceleration) * speed_factor);
	}
	if(moving_down)
	{
		//direction += sf::Vector2f(0.0f, (acceleration+deceleration) * speed_factor);
	}

	if(direction.x < -max_speed) 
	{
		direction.x = -max_speed;
	}
	if(direction.x > max_speed)
	{
		direction.x = max_speed;
	}

	if(direction.y < -max_speed)
	{
		direction.y = -max_speed;
	}
	if(direction.y > max_speed)
	{
		direction.y = max_speed;
	}

	//Managing deceleration
	direction *= deceleration;

	sf::Time dtime = Game::deltaTime->getElapsedTime();
	float_factor = 0.02f*sin(5*dtime.asSeconds());

	direction.y += float_factor;
	
	//std::cout << "direction.y" << direction.y << std::endl;

	// Gravity :
	if(character.getPosition().y >= 500)
	{
		grv = 0.0f;
		//direction.y = 0.0f;
	}
	else grv += Game::gravity.y;
	
	direction.y += grv;

	character.move(direction);
	updateMetrics();
}
/*
void Tamagotchi::EventHandler(sf::Event& e) 
{
	switch(e.type)
	{
		case  sf::Event::KeyReleased:
			std::cout << "Yolo" << std::endl;
			break;
	}
}
*/
