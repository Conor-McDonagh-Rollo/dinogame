#include "Background.h"
#include <iostream>


Background::Background(int x)
{
	if (!tex.loadFromFile("sheet.png"))
	{
		std::cout << "Unable to load sprite";
	}
	body.setTexture(tex);
	body.setTextureRect(sf::IntRect(0, 53, 712, 68 - 12));
	body.setScale(2.f, 2.f);
	body.setPosition(x, 320);
}

void Background::Update(float speed)
{
	body.move(-1 * speed, 0);
	if (body.getPosition().x <= -712) body.setPosition(712 + 712, 320);
}

void Background::Draw(sf::RenderWindow& t_window)
{
	t_window.draw(body);
}
