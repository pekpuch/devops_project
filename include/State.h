#pragma once

#include "Player.h"

class State {
private:

protected:
	std::stack<State*>* states;

	sf::RenderWindow* window;
	//все поддерживаемые кнопки
	std::map<std::string, int>* supportedKeys;
	//что-то типа того что они делают в конкретном состоянии
	std::map<std::string, int> keybinds;
	bool quit;

	//Позиции мыши
	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//Ресурсы
	std::map<std::string, sf::Texture> textures;

	//Функции
	virtual void initKeybinds() = 0;

public:
	State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~State(); 

	const bool& getQuit() const;
	void endState();
	virtual void updateMousePosition();
	virtual void updateInput(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = NULL) = 0;
};

