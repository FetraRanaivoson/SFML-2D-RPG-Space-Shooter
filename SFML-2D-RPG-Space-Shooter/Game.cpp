#include "Game.h"

//Initialization
void Game::initWindow()
{
	/*Creates a SFML window using options from window.ini file*/
	std::ifstream ifs("Config/Window.ini");

	std::string title = "None";
	sf::VideoMode window_bounds(800, 600);
	unsigned int framerate_limit = 120;
	bool vertical_sync_enabled = false;

	if (ifs.is_open()) {
		std::getline(ifs, title);
		ifs >> window_bounds.width >> window_bounds.height;
		ifs >> framerate_limit;
		ifs >> vertical_sync_enabled;
	}
	ifs.close();

	this->window = new sf::RenderWindow(window_bounds, title);
	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

void Game::initStates()
{
	this->states.push(new GameState(this->window));
}

//Constructor/Destructor
Game::Game()
{
	this->initWindow();
	this->initStates();
}

Game::~Game()
{
	delete this->window;
	while (!this->states.empty()) 
	{
		delete this->states.top(); //Remove the data
		this->states.pop(); //Remove the pointer
	}
}

//	Functions
void Game::run()
{
	while (this->window->isOpen())
	{
		this->updateDt();
		this->update();
		this->render();
	}
}

void Game::update()
{
	this->updateSFMLEvents();
	if (!this->states.empty())
		this->states.top()->update(this->dt);
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
	if (!this->states.empty()) {
		//this->states.top()->render();
		this->states.top()->render(this->window);
	}

	this->window->display();
}

void Game::updateDt()
{
	/*Updates the dt variable with the time it takes to update and
	render one frame*/
	this->dt = this->dtClock.restart().asSeconds();

	//system("cls");
	//std::cout << this->dt << "\n";
}  



