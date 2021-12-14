#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>

class Player
{
private:
	void Animate();

	sf::Sprite body;
	sf::Texture tex;

	sf::Clock timer;

	bool jumping = false;
public:
	Player();
	void Update(sf::Int32 dt);
	void Draw(sf::RenderWindow& t_window);
};

#endif