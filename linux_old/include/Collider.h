#ifndef COLLIDER_H
#define COLLIDER_H

#include <SFML/Graphics.hpp>

class Collider {
private:
    sf::RectangleShape shape;

public:
    Collider(float x, float y, float width, float height);
    ~Collider();

    // Getters
    const sf::FloatRect getBounds() const;
    void render(sf::RenderTarget& target);
};

#endif // COLLIDER_H
