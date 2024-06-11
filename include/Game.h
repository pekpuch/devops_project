#pragma once

#include "MainMenuState.h"

class Game {
private:
	//Variables
	sf::RenderWindow *window;
	sf::Event sfEvent;
	std::vector<sf::VideoMode> videoModes;
	sf::ContextSettings windowSettings;
	bool fullscreen;
	
	sf::Clock dtClock;
	//delta-time (сколько времени на один вызов обновления)
	float dt;

	std::stack<State*> states;

	std::map<std::string, int> supportedKeys;

	//Инициализация окна
	void initWindow();
	void initStates();
	void initKeys();
	

public:
	//Конструктор
	Game();
	virtual ~Game();

	//Functions

	void endApplication();

	//обновляет dt со временем, необходимым на обновление и рендеринг одного кадра
	void updateDT();

	//Обновление ивентов
	void updateSFMLEvents();

	//Обновление
	void update();


	//Рендеринг
	void render();


	//Запуск
	void run(); 

};

