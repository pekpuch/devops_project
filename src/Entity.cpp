#include "Entity.h"
#include "HeatBox.h"

void Entity::initVariables(){
	
	this->movementComponent = NULL;
}

Entity::Entity() {
	this->initVariables();
	this->heatbox = new HeatBox();
	this->heatbox->setMaxHP(100);
	this->heatbox->setHitboxSize(sf::Vector2f(150.f, 70.f)); // Примерный размер хитбокса
}

Entity::~Entity() {
	delete this->movementComponent;
	delete this->animationComponent;
}

void Entity::setTexture(sf::Texture& texture){
	this->sprite.setTexture(texture);
}

void Entity::createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration, HeatBox* heatbox){
	this->movementComponent = new MovementComponent(this->sprite, maxVelocity, acceleration, deceleration, heatbox);
	this->heatbox->setVelocity(maxVelocity);
	this->heatbox->setVelocityy(maxVelocity);
}

void Entity::createAnimationComponent(sf::Texture& texture) { //ДОБАВИЛА!!!!!!!!!!!!!
	this->animationComponent = new AnimationComponent(this->sprite, texture);
}

sf::FloatRect Entity::getGlobalBounds() {
	return this->sprite.getGlobalBounds();
}

sf::Vector2f Entity::getPrevoius() {
	return this->previousPosition;
}

void Entity::setPosition(const float x, const float y){
	this->sprite.setPosition(x, y);
}

void Entity::move(const float dir_x, const float dir_y, const float& dt) {
	if (this->movementComponent) {
		this->previousPosition = this->heatbox->hitbox.getPosition();
		this->movementComponent->move(dir_x, dir_y, dt); // двигаем спрайт
	}
}

void Entity::update(const float& dt) {
	if (this->movementComponent) {
		this->movementComponent->update(dt);
	}
}

void Entity::render(sf::RenderTarget* target) {
	target->draw(this->heatbox->hitbox);
	target->draw(this->sprite);
}
