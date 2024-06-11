#include "HeatBox.h"

HeatBox::HeatBox()
    : max_hp(100),
    current_hp(100),
    // ������������� velocity ���������� ���������
    hitbox(sf::Vector2f(50.f, 50.f)) // ������������� �������� ��������
{
    this->hitbox.setFillColor(sf::Color::Transparent); // ������������� ���������� ���� �������
    this->hitbox.setOutlineThickness(1.f); // ������� ������� ��������
    this->hitbox.setOutlineColor(sf::Color::Transparent); // ���� ������� ��������
}

HeatBox::~HeatBox()
{
}

void HeatBox::setMaxHP(int hp)
{
    this->max_hp = hp;
    this->current_hp = hp; // ��������� ������� ���� �������� �� ������ ���������
}

void HeatBox::getDamage(int damage)
{
    this->current_hp -= damage; // ��������� ������� ���������� ����� �������� �� �������� �����
    if (this->current_hp < 0)
    {
        this->current_hp = 0; // �����������, ��� ������� ���������� ����� �������� �� ����� ������ 0
    }
}

int HeatBox::getMaxHP() const
{
    return this->max_hp;
}

int HeatBox::getCurrentHP() const
{
    return this->current_hp; // ���������� ������� ���������� ����� ��������
}

void HeatBox::setHitboxSize(const sf::Vector2f& size)
{
    this->hitbox.setSize(size); // ������������� ������ ��������
}

void HeatBox::setHitboxPosition(const sf::Vector2f& position)
{
    this->hitbox.setPosition(position); // ������������� ������� ��������
}

sf::FloatRect HeatBox::getGlobalBounds() const
{
    return this->hitbox.getGlobalBounds(); // �������� ���������� ������� ��������
}

void HeatBox::move(const float dir_x, const float dir_y, const float& dt) {
    // �������� ������� ���������� ��������
    sf::Vector2f currentPosition = this->hitbox.getPosition();

    // ��������� ����� ����������, �������� ����������� � ��������
    float dx = dir_x * dt * velocity.x;
    float dy = dir_y * dt * velocity.y;

    // �������� ���������� ��������
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
    target.draw(this->hitbox); // �������� �������
}


