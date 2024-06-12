#include "Platform.h"

//void Platforms::initCollider(float x, float y, float width,
//	float height) {
//	// Ïðèìåð äîáàâëåíèÿ êîëëàéäåðîâ
//	sf::RectangleShape collider1;
//	collider1.setSize(sf::Vector2f(200.f, 50.f));
//	collider1.setFillColor(sf::Color::Cyan);
//	collider1.setPosition(300.f, 400.f);
//
//	sf::RectangleShape collider2;
//	collider2.setSize(sf::Vector2f(200.f, 50.f));
//	collider2.setFillColor(sf::Color::Blue);
//	collider2.setPosition(600.f, 500.f);
//
//	this->colliders.push_back(collider1);
//	this->colliders.push_back(collider2);
//}

Platform::Platform(float x, float y, float width,
	float height, sf::Color idleColor) {

	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(width, height));
	this->idleColor = idleColor;
	this->shape.setFillColor(this->idleColor);
}

void Platform::checkCollision(std::queue<sf::FloatRect>& queue, HeatBox* hitbox) {
	sf::FloatRect hitboxBounds = hitbox->getGlobalBounds();
	//std::ofstream out;          // ïîòîê äëÿ çàïèñè
	//out.open("de_bug/test.txt");      // îòêðûâàåì ôàéë äëÿ çàïèñè
	//if (out.is_open())
	//{
	//	out << hitboxBounds.getPosition().x << " " << hitboxBounds.getPosition().y << " " << hitboxBounds.height << std::endl;
	//}
	//out.close();

	float box_lu_x = hitboxBounds.getPosition().x; //left up
	float box_lu_y = hitboxBounds.getPosition().y - hitboxBounds.height;

	float box_ld_x = hitboxBounds.getPosition().x;
	float box_ld_y = hitboxBounds.getPosition().y;

	float box_ru_x = hitboxBounds.getPosition().x + hitboxBounds.width + hitboxBounds.height;
	float box_ru_y = hitboxBounds.getPosition().y - hitboxBounds.height;

	float box_rd_x = hitboxBounds.getPosition().x + hitboxBounds.width;
	float box_rd_y = hitboxBounds.getPosition().y;


	float platform_lu_x = this->shape.getPosition().x; //left up
	float platform_lu_y = this->shape.getPosition().y - hitboxBounds.height;

	float platform_ld_x = this->shape.getPosition().x;
	float platform_ld_y = this->shape.getPosition().y;

	float platform_ru_x = this->shape.getPosition().x + hitboxBounds.width + hitboxBounds.height;
	float platform_ru_y = this->shape.getPosition().y - hitboxBounds.height;

	float platform_rd_x = this->shape.getPosition().x + hitboxBounds.width;
	float platform_rd_y = this->shape.getPosition().y;


	if ((box_ru_y > platform_lu_y && box_ru_y < platform_ld_y) || (box_rd_y > platform_lu_y && box_rd_y < platform_ld_y)) {
		queue.push(hitboxBounds);
	}

}

//void Platform::update(){
//}

void Platform::render(sf::RenderTarget* target) {
	target->draw(this->shape);
}