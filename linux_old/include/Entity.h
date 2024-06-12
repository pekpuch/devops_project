#pragma once

#include "MovementComponent.h"
#include "HeatBox.h"
#include "AnimationComponent.h"


class Entity
{
private:
	void initVariables();
protected:
	sf::Sprite sprite;
	MovementComponent* movementComponent;
	AnimationComponent* animationComponent; //��������!!!!!!!!!!!

	sf::Vector2f previousPosition;

public:
	HeatBox* heatbox;
	Entity();
	virtual ~Entity();

	void setTexture(sf::Texture& texture);
	sf::FloatRect getGlobalBounds();
	sf::Vector2f getPrevoius();
	void createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration, HeatBox* heatbox);
	void createAnimationComponent(sf::Texture& texture); //��������!!!!!!!!!!!!!!!!


	virtual void setPosition(const float x, const float y);
	virtual void move(const float x, const float y, const float& dt);
	
	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget* target);

};

