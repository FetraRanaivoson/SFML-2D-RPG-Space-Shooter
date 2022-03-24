#ifndef GAME_H
#define GAME_H

#include "GameState.h"

class Game
{
private:
	//Variables
	sf::RenderWindow* window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt;

	//Eg: menu -> options ->go back to menu etc
	std::stack<State*> states;

	//Initialization
	void initWindow();
	void initStates();

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
