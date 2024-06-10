#pragma once

#include "MovementComponent.h"

//Ѕаза дл€ каждого персонажа который создаетс€
class Entity
{
private:
	void initVariables();
protected:
	sf::Texture* texture;
	sf::Sprite* sprite;

	MovementComponent* movementComponent;

public:
	Entity();
	virtual ~Entity();

	void createSprite(sf::Texture* texture);
	void createMovementComponent(const float maxVelocity);


	virtual void setPosition(const float x, const float y);
	virtual void move(const float& dt, const float x, const float y);
	
	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget* target);

};

