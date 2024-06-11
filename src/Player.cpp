#include "Player.h"

void Player::initVariables() {
}

Player::Player(float x, float y, sf::Texture& texture) {
    this->initVariables();

    this->previousPosition = this->sprite.getPosition();
    this->setPosition(x, y);

    this->createMovementComponent(300.f, 10.f, 5.f, heatbox);
    this->createAnimationComponent(texture);

    this->animationComponent->addAnimation("IDLE_LEFT", 30.f, 0, 0, 0, 0, 200, 130);
    this->animationComponent->addAnimation("WALK_LEFT", 30.f, 0, 1, 1, 1, 200, 130);
    this->animationComponent->addAnimation("IDLE_RIGHT", 30.f, 0, 2, 0, 2, 200, 130);
    this->animationComponent->addAnimation("WALK_RIGHT", 30.f, 0, 3, 1, 3, 200, 130);
}

Player::~Player() {
}


void Player::update(const float& dt) { //ÄÎÁÀÂÈËÀ!!!!!!!!!!!!!!!!!
    this->movementComponent->update(dt);

    if (this->movementComponent->idle()) {
        if (this->movementComponent->left())
            this->animationComponent->play("IDLE_LEFT", dt);
        else
            this->animationComponent->play("IDLE_RIGHT", dt);
    }
    else {
        if (this->movementComponent->left())
            this->animationComponent->play("WALK_LEFT", dt);
        else
            this->animationComponent->play("WALK_RIGHT", dt);
    }
}
