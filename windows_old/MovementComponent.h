#pragma once

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

class MovementComponent
{
private:
	sf::Sprite& sprite;

	float maxVelocity;
	sf::Vector2f velocity; //наша скорость
	float acceleration; //ускорение
	float deceleration; //замедление
	bool jumpOpportunity;
	bool jumpActive;
	float windowWidth = 1080.f; // Новая переменная для ширины окна
	float windowHeight = 720.f;
	HeatBox* heatbox;
	bool lastLeft = 0;


public:

	const bool idle() const; //ДОБАВИЛА!!!!!!!! 
	const bool left(); //ДОБАВИЛА!!!!!!!!

	MovementComponent(sf::Sprite& sprite, float maxVelocity, float acceleration, float deceleration, HeatBox* heatbox);
	virtual ~MovementComponent();

	const sf::Vector2f& getVelocity() const;

	void move(const float x, const float y, const float& dt);
	void falling();
	void update(const float& dt);
};

