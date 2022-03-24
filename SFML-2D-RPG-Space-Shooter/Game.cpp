#include "Game.h"

//Initialization
void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "C++ SFML RPG");

}

//Constructor/Destructor
Game::Game()
{
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

//	Functions
void Game::run()
{
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}

void Game::update()
{
	this->updateSFMLEvents();
}

void Game::updateSFMLEvents()
{
	while (this->window->pollEvent(this->sfEvent))
	{
		if (this->sfEvent.type == sf::Event::Closed)
			this->window->close();
	}
}

void Game::render()
{
	this->window->clear();

	//Render items

	this->window->display();
}


