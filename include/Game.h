#pragma once

#include "MainMenuState.h"

class Game {
private:
	sf::RenderWindow *window;
	sf::Event sfEvent;
	std::vector<sf::VideoMode> videoModes;
	sf::ContextSettings windowSettings;
	bool fullscreen;
	
	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;

	std::map<std::string, int> supportedKeys;

	//������������� ����
	void initWindow();
	void initStates();
	void initKeys();
	

public:
	Game();
	virtual ~Game();


	void endApplication();

	void updateDT();

	void updateSFMLEvents();

	void update();


	void render();


	void run(); 

};

