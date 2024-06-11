#include "HeatBox.h"

HeatBox::HeatBox()
    : max_hp(100),
    current_hp(100),
    // Инициализация velocity переданным значением
    hitbox(sf::Vector2f(50.f, 50.f)) // Инициализация размеров хитбокса
{
    this->hitbox.setFillColor(sf::Color::Transparent); // Устанавливаем прозрачный цвет заливки
    this->hitbox.setOutlineThickness(1.f); // Толщина границы хитбокса
    this->hitbox.setOutlineColor(sf::Color::Red); // Цвет границы хитбокса
}

HeatBox::~HeatBox()
{
}

void HeatBox::setMaxHP(int hp)
{
    this->max_hp = hp;
    this->current_hp = hp; // Обновляем текущие очки здоровья до нового максимума
}

void HeatBox::getDamage(int damage)
{
    this->current_hp -= damage; // Уменьшаем текущее количество очков здоровья на величину урона
    if (this->current_hp < 0)
    {
        this->current_hp = 0; // Гарантируем, что текущее количество очков здоровья не будет меньше 0
    }
}

int HeatBox::getMaxHP() const
{
    return this->max_hp;
}

int HeatBox::getCurrentHP() const
{
    return this->current_hp; // Возвращаем текущее количество очков здоровья
}

void HeatBox::setHitboxSize(const sf::Vector2f& size)
{
    this->hitbox.setSize(size); // Устанавливаем размер хитбокса
}

void HeatBox::setHitboxPosition(const sf::Vector2f& position)
{
    this->hitbox.setPosition(position); // Устанавливаем позицию хитбокса
}

sf::FloatRect HeatBox::getGlobalBounds() const
{
    return this->hitbox.getGlobalBounds(); // Получаем глобальные границы хитбокса
}

void HeatBox::move(const float dir_x, const float dir_y, const float& dt) {
    // Получаем текущие координаты хитбокса
    sf::Vector2f currentPosition = this->hitbox.getPosition();

    // Вычисляем новые координаты, учитывая направление и скорость
    float dx = dir_x * dt * velocity.x;
    float dy = dir_y * dt * velocity.y;

    // Изменяем координаты хитбокса
    this->hitbox.setPosition(currentPosition.x + dx, currentPosition.y + dy);
}

void HeatBox::setVelocity(float newvelocity) {
    this->velocity.x = newvelocity;
}

void HeatBox::setVelocityy(float newvelocity) {
    this->velocity.y = newvelocity;
}

void HeatBox::render(sf::RenderTarget& target)
{
    target.draw(this->hitbox); // Рендерим хитбокс
}


