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
	sf::Vector2f velocity; //���� ��������
	float acceleration; //���������
	float deceleration; //����������
	bool jumpOpportunity;
	bool jumpActive;
	float windowWidth = 1080.f; // ����� ���������� ��� ������ ����
	float windowHeight = 720.f;
	HeatBox* heatbox;
	bool lastLeft = 0;


public:

	const bool idle() const; //��������!!!!!!!! 
	const bool left(); //��������!!!!!!!!

	MovementComponent(sf::Sprite& sprite, float maxVelocity, float acceleration, float deceleration, HeatBox* heatbox);
	virtual ~MovementComponent();

	const sf::Vector2f& getVelocity() const;

	void move(const float x, const float y, const float& dt);
	void falling();
	void update(const float& dt);
};

