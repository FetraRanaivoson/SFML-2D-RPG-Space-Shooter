#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"


class Game
{
private:
	//Variables
	sf::RenderWindow* window;
	sf::Event sfEvent;

	//Initialization
	void initWindow();

public:
	//Constructor/Destructor
	Game();
	virtual ~Game();

	//Functions
	void run();
	void update();
	void render();
	void updateSFMLEvents();
};

#endif
