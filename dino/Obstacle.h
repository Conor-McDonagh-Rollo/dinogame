#ifndef OBSTACLE_H
#define OBSTACLE_H
#include <SFML/Graphics.hpp>

class Obstacle
{
private:

	sf::Sprite body;
	sf::Texture tex;
	
public:
	Obstacle(int x);
	void Update(float speed);
	void Draw(sf::RenderWindow& t_window);
	sf::FloatRect getGlobalBounds() { return body.getGlobalBounds(); }
};

#endif