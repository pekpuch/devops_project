#include "MovementComponent.h"
#include "HeatBox.h"

MovementComponent::MovementComponent(sf::Sprite& sprite, float maxVelocity,
	float acceleration, float deceleration, HeatBox* heatbox)
	: sprite(sprite), maxVelocity(maxVelocity), acceleration(acceleration), deceleration(deceleration), jumpOpportunity(true), jumpActive(false), heatbox(heatbox)
{

}

MovementComponent::~MovementComponent(){

}

const bool MovementComponent::idle() const { //ÄÎÁÀÂÈËÀ!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	if (this->velocity.x == 0.f && this->velocity.y == 0.f) //åñëè ñêîðîñòü 0, òî îíà ñòîèò âñå íîðì
		return true;
	return false;
}


const bool MovementComponent::left() { //ÄÎÁÀÂÈËÀ!!!!!!!!!!!!!!!!!!!!!!!!!
	if (this->velocity.x == 0.f)
		if (this->lastLeft == 1)
			return true;
	if (this->velocity.x < 0.f) { //ÅÑËÈ ÑÊÎÐÎÑÒÜ ÎÒÐÈÖÀÒÅËÜÍÀß, ò.å. ÂËÅÂÎ
		this->lastLeft = 1;
		return true;
	}
	else
		this->lastLeft = 0;
	return false;
}

const sf::Vector2f& MovementComponent::getVelocity() const{
	return this->velocity;
}



void MovementComponent::move(const float dir_x, const float dir_y, const float& dt){
	//óñêîðåíèå
	this->velocity.x += this->acceleration * dir_x;

	if (this->jumpActive == 0 && (this->jumpOpportunity == 1 && dir_y == -1)) {
		this->jumpActive = 1;
		this->jumpOpportunity = 0;
	}
	else {
		this->jumpActive = 0;
		this->jumpOpportunity = 1;
	}

	if (this->jumpActive == 1 && dir_y == -1) {
		this->velocity.y -= (this->acceleration);
	}
}

void MovementComponent::falling(){
	if (this->jumpOpportunity == 1) {
		this->velocity.y += this->acceleration;
	}
}


void MovementComponent::update(const float& dt){
	//
	if (this->velocity.x > 0.f) {
		if (this->velocity.x > this->maxVelocity)
			this->velocity.x = this->maxVelocity;

		this->velocity.x -= this->deceleration;
		if (this->velocity.x < 0.f) {
			this->velocity.x = 0.f;
		}
	}
	else if (this->velocity.x < 0.f) {
		if (this->velocity.x < 0 - this->maxVelocity)
			this->velocity.x = 0 - this->maxVelocity;

		this->velocity.x += this->deceleration;
		if (this->velocity.x > 0.f) {
			this->velocity.x = 0.f;
		}
	}	

	if (this->velocity.y > 0.f) {
		if (this->velocity.y > this->maxVelocity)
			this->velocity.y = this->maxVelocity;

		this->velocity.y -= this->deceleration;
		if (this->velocity.y < 0.f) {
			this->velocity.y = 0.f;
		}

	}
	else if (this->velocity.y < 0.f) {
		if (this->velocity.y < 0 - (2 * this->maxVelocity)) {
			this->velocity.y = 0.f;
			this->jumpActive = 0.f;
		}
	}

	this->falling();

	//ôèíàëüíîå äâèæåíèå 
	this->sprite.move(this->velocity * dt);

	sf::FloatRect bounds = this->sprite.getGlobalBounds();
	if (bounds.left < 200.f) {
		this->sprite.setPosition(200.f, this->sprite.getPosition().y);
		this->velocity.x = 0.f;
	}
	else if (bounds.left + bounds.width > windowWidth) {
		this->sprite.setPosition(windowWidth - bounds.width, this->sprite.getPosition().y);
		this->velocity.x = 0.f;
	}

	if (bounds.top < 0.f) {
		this->sprite.setPosition(this->sprite.getPosition().x, 0.f);
		this->velocity.y = 0.f;
	}
	else if (bounds.top + bounds.height > windowHeight) {
		this->sprite.setPosition(this->sprite.getPosition().x, windowHeight - bounds.height);
		this->velocity.y = 0.f;
	}
	this->heatbox->setVelocity(this->velocity.x);
	this->heatbox->setVelocityy(this->velocity.y);
	this->heatbox->hitbox.setPosition(sprite.getPosition().x, sprite.getPosition().y);
}
