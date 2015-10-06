#ifndef DEF_ENTITY
#define DEF_ENTITY

class Entity
{
	private:
		int id;
	public:
		virtual void update() = 0;
		virtual void draw() = 0;
		virtual void events(sf::Event& event) = 0;
		virtual bool isPlayable() = 0;
		virtual sf::Vector2f getDirection() = 0;
};

#endif
