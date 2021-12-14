#include "Player.h"
#include <iostream>
#include <cstdlib>

void Player::Animate()
{
	if (timer.getElapsedTime().asSeconds() < 0.15f )
		body.setTextureRect(sf::IntRect(677, 0, 44, 50));
	else if (timer.getElapsedTime().asSeconds() < 0.30f)
		body.setTextureRect(sf::IntRect(677 + 44 + 44, 0, 44, 50));
	else if (timer.getElapsedTime().asSeconds() < 0.45f)
		body.setTextureRect(sf::IntRect(677 + 44 + 44 + 44, 0, 44, 50));
	else
		timer.restart();
}

Player::Player()
{
	if (!tex.loadFromFile("sheet.png"))
	{
		std::cout << "Unable to load sprite";
	}
	body.setTexture(tex);
	body.setTextureRect(sf::IntRect(677, 2, 44, 47)); 
	body.setScale(2.f,2.f);
	body.setPosition(10,300);
}

void Player::Update(sf::Int32 dt)
{
	if (!jumping)
	{
		if (body.getPosition().y < 300)
			body.move(0.f, 1.5f);
		else
			body.setPosition(10, 300);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::Space) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			jumping = true;
		}
	}
	else
	{
		body.move(0.f,-2.f);
		if (body.getPosition().y < 100) jumping = false;
	}
	Animate();
}

void Player::Draw(sf::RenderWindow& t_window)
{
	t_window.draw(body);
}
