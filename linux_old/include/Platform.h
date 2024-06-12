#pragma once

#include <queue>
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>
#include "HeatBox.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Platform{
private:
	/*std::vector<sf::RectangleShape> colliders;
	void initCollider(float x, float y, float width,
		float height);*/

	sf::RectangleShape shape;
	sf::Color idleColor;
public:
	Platform(float x, float y, float width,
		float height, sf::Color idleColor);

	void checkCollision(std::queue<sf::FloatRect>& queue, HeatBox* hitbox);

	void render(sf::RenderTarget* target);
};