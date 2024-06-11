#include "Collider.h"

Collider::Collider(float x, float y, float width, float height) {
    this->shape.setPosition(x, y);
    this->shape.setSize(sf::Vector2f(width, height));
    this->shape.setFillColor(sf::Color::Red);
    this->shape.setOutlineThickness(1.f);
    this->shape.setOutlineColor(sf::Color::Yellow);
}

Collider::~Collider() {}

const sf::FloatRect Collider::getBounds() const {
    return this->shape.getGlobalBounds();
}

void Collider::render(sf::RenderTarget& target) {
    target.draw(this->shape);
}
