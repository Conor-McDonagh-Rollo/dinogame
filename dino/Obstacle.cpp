#include "Obstacle.h"
#include <iostream>
#include <cstdlib>

Obstacle::Obstacle(int x)
{
	srand(time(NULL));
	if (!tex.loadFromFile("sheet.png"))
	{
		std::cout << "Unable to load sprite";
	}
	body.setTexture(tex);
	body.setTextureRect(sf::IntRect(228, 2, 17, 35));
	body.setScale(2.f, 2.f);
	body.setPosition(x, 320);
}

void Obstacle::Update(float speed)
{
	body.move(-2 * speed, 0);
	if (body.getPosition().x <= -100)
	{
		int offset = (rand() % 1400) + 800;
		body.setPosition(1000 + offset, 320);
		int rnd = rand() % 3;
		switch (rnd)
		{
		case 0:
			body.setTextureRect(sf::IntRect(228, 2, 17, 35));
			break;
		case 1:
			body.setTextureRect(sf::IntRect(228, 2, 17 + 17, 35));
			break;
		case 2:
			body.setTextureRect(sf::IntRect(228, 2, 17 + 17 + 17, 35));
			break;
		default:
			break;
		}
	}
}

void Obstacle::Draw(sf::RenderWindow& t_window)
{
	t_window.draw(body);
}
