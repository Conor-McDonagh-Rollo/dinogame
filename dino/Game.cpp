#include "Game.h"

Game::Game()
	: m_window{ sf::VideoMode(1000, 400, 32), "Dino Game", sf::Style::Resize | sf::Style::Close }, 
	bg1{0}, bg2{712}, bg3{712 + 712}, ob1{1100}, ob2{1800}
{
	m_window.setVerticalSyncEnabled(true);
}

void Game::run()
{
	sf::Clock clock;
	sf::Int32 lag = 0;
	while (m_window.isOpen())
	{
		//game loop
		sf::Time dt = clock.restart();
		lag += dt.asMilliseconds();

		processEvents();

		while (lag > MS_PER_UPDATE) //at least 60 fps
		{
			update(lag);
			lag -= MS_PER_UPDATE;
		}
		update(lag);

		render();
	}
}

void Game::processEvents()
{
	sf::Event ev;
	while (m_window.pollEvent(ev))
	{
		if (ev.type == sf::Event::Closed)
		{
			m_window.close();
		}
	}
}

void Game::render()
{
	m_window.clear(sf::Color::White);

	bg1.Draw(m_window);
	bg2.Draw(m_window);
	bg3.Draw(m_window);

	ob1.Draw(m_window);
	ob2.Draw(m_window);

	garry.Draw(m_window); // garry is a dinosaur.. he has no friends... like you!

	m_window.display();
}

void Game::update(sf::Int32 deltaTime)
{
	if (gameSpeed.getElapsedTime().asSeconds() > 10)
	{
		speed += 0.05f;
		gameSpeed.restart();
	}

	garry.Update(deltaTime);
	bg1.Update(speed);
	bg2.Update(speed);
	bg3.Update(speed);
	ob1.Update(speed);
	ob2.Update(speed);
}
