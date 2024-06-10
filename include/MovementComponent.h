#pragma once

#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class MovementComponent
{
private:
	float maxVelocity;
	sf::Vector2f velocity; //���� ��������
	sf::Vector2f accleration; //���������
	sf::Vector2f deceleration; //����������


public:
	MovementComponent(float maxVelocity);
	virtual ~MovementComponent();

	const sf::Vector2f& getVelocity() const;

	void move(const float x, const float y);
	void update(const float& dt);
};

