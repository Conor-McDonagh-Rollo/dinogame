#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <SFML/Graphics.hpp>

class Background
{
private:

	sf::Sprite body;
	sf::Texture tex;

	bool jumping = false;
public:
	Background(int x);
	void Update(float speed);
	void Draw(sf::RenderWindow& t_window);
};

#endif