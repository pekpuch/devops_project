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


class HeatBox
{
private:
    int max_hp;
    int current_hp; // Поле для хранения текущего количества очков здоровья
    sf::Vector2f velocity;

public:
    sf::RectangleShape hitbox; 

    HeatBox();
    virtual ~HeatBox();

    void setMaxHP(int hp);
    void getDamage(int damage);

    int getMaxHP() const;
    int getCurrentHP() const; // Метод для получения текущих очков здоровья

    void setHitboxSize(const sf::Vector2f& size); // Устанавливаем размер хитбокса
    void setHitboxPosition(const sf::Vector2f& position); // Устанавливаем позицию хитбокса
    sf::FloatRect getGlobalBounds() const; // Получаем глобальные границы хитбокса
    void move(const float dir_x, const float dir_y, const float& dt);
    void setVelocity(float newvelocity);
    void setVelocityy(float newvelocity);

    void render(sf::RenderTarget& target); // Рендерим хитбокс
};
