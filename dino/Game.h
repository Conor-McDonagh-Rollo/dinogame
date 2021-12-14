#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Background.h"
#include "Obstacle.h"
#ifndef MS_PER_UPDATE
#define MS_PER_UPDATE 10.0f
#endif

class Game
{
public:
	Game();
	void run(); // run game

private:
	sf::RenderWindow m_window;
	Player garry;

	Background bg1;
	Background bg2;
	Background bg3;

	Obstacle ob1;
	Obstacle ob2;

	sf::Clock gameSpeed;
	float speed = 1.0f;

	void processEvents();
	void render();
	void update(sf::Int32 deltaTime);
};

#endif

