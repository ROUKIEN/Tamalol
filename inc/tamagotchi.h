#ifndef DEF_TAMAGOTCHI
#define DEF_TAMAGOTCHI

class Tamagotchi : 
	public Entity 
{
	private:
		int health;
		int cleanliness;
		int hunger;
		
		bool alive;
		bool playable;
		
		int hungerFactor;
		int cleanlinessFactor;
		int healthFactor;

		sf::Clock hungerClock;
		sf::Clock cleanlinessClock;
		sf::Clock healthClock;

		bool moving_left;
		bool moving_right;
		bool moving_up;
		bool moving_down;
		
		bool moving;

		double speed_factor;
		double float_factor;

		double grv;

		float max_speed;
		float acceleration;
		float deceleration;

		sf::Vector2f direction;

		sf::Sprite character;

		double timeFactor;

	public:
		Tamagotchi();
		~Tamagotchi();
		
		int getHunger();
		int getCleanliness();
		int getHealth();
		
		sf::Vector2f getDirection();

		void updateMetrics();

		void updateHunger();
		void updateCleanliness();
		void updateHealth();

		bool isAlive();
		void die();

		void feed();
		void heal();
		void clean();
		
		void draw();
		void events(sf::Event& event);
		void update();
		void move(sf::Vector2f direction);
		
		void togglePlayable();
		bool isPlayable();
};

#endif
