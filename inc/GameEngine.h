#ifndef DEF_GAME_ENGINE
#define DEF_GAME_ENGINE

class Entity;

namespace GameEngine
{
	class GameController
	{
		private:
			GameController(GameController const&) = delete;
			void operator=(GameController const&) = delete;

			std::vector<Entity *> entities;
			std::vector<sf::Text *> texts;

		public:
			GameController();
			
			bool addEntity(Entity* e);
			bool addText(sf::Text* t);
			bool removeEntity();

			std::vector<Entity*> getEntities();
	
			void draw();
			void update();
	};
	extern GameEngine::GameController * gc;
}

#endif

#ifndef DEF_WINDOW_MANAGER
#define DEF_WINDOW_MANAGER

/**
 * Manage game window
 */
namespace WindowManager
{
	class ResourceManager
	{
		private:
			std::vector<sf::Texture*> textures;

			ResourceManager(ResourceManager const&) = delete;
			void operator=(ResourceManager const&) = delete;

		public:
			ResourceManager() {};

			sf::Texture * loadFile(const std::string & file) 
			{
				sf::Texture * t = new sf::Texture;
				t->loadFromFile(file, sf::IntRect(0,0,64,64));
				textures.push_back(t);

				return t;
			}
	};
	extern sf::RenderWindow * gw;
	extern WindowManager::ResourceManager * rm;
}

#endif

#ifndef DEF_GAME
#define DEF_GAME

namespace Game
{
	class Game
	{
		private:
			bool running;
			bool paused;

		public:
			Game() 
			{
				running = false;
				paused = false;
				std::cout << "Created game" << std::endl;
			};
			~Game();

			void init();
			void start();
			void pause();
			void stop();
			void run();
			void checkEvents();
	};
	extern Game * g;
	extern sf::Clock * deltaTime;
	extern sf::Vector2f gravity;
}

#endif

