#ifndef GAME_H
#define GAME_H

#include "State.h"

class Game
{
private:
	//Variables
	sf::RenderWindow* window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt;

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

	void updateDt();
};

#endif
