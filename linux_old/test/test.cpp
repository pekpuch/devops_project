#include <gtest/gtest.h>
#include "AnimationComponent.h"
#include "Button.h"
#include "Collider.h"
#include "Entity.h"
#include "Game.h"
#include "GameState.h"
#include "HeatBox.h"
#include "MainMenuState.h"
#include "MovementComponent.h"
#include "Platform.h"
#include "Player.h"
#include "State.h"

// Тесты для AnimationComponent
TEST(AnimationComponentTest, Constructor) {
    sf::Texture texture;
    sf::Sprite sprite;
    AnimationComponent animComp(sprite, texture);

    // Проверяем, что объект создан
    ASSERT_TRUE(&animComp != nullptr);
}

// Тесты для button

//Тест на создание 
TEST(ButtonTest, Constructor) {
    sf::Font font;
    sf::Color idleColor = sf::Color::Red;
    sf::Color hoverColor = sf::Color::Green;
    sf::Color activeColor = sf::Color::Blue;
    Button button(0.f, 0.f, 100.f, 50.f, &font, "Test Button", idleColor, hoverColor, activeColor);

    // Проверяем, что кнопка создана
    ASSERT_TRUE(&button != nullptr);
}

// Тест проверки нажатия кнопки
TEST(ButtonTest, IsPressed) {
    sf::Font font;
    sf::Color idleColor = sf::Color::Red;
    sf::Color hoverColor = sf::Color::Green;
    sf::Color activeColor = sf::Color::Blue;
    Button button(0.f, 0.f, 100.f, 50.f, &font, "Test Button", idleColor, hoverColor, activeColor);

    // Проверяем, что кнопка не нажата в начале
    ASSERT_FALSE(button.isPressed());

    // Нажимаем кнопку и проверяем, что она нажата
    button.update(sf::Vector2f(10.f, 10.f)); // Передаем координаты мыши для имитации наведения
    button.update(sf::Vector2f(10.f, 10.f)); // Передаем координаты мыши для имитации нажатия
    ASSERT_TRUE(button.isPressed());
}

// Тесты для game

// Тест проверки конструктора и деструктора
TEST(GameTest_ConstructorDestructor, TestBody) {
    Game game;

    // Проверяем, что объект создан
    ASSERT_TRUE(&game != nullptr);
}

// Тесты для movementcomponent

// Тест проверки метода idle
TEST(MovementComponentTest_Idle, TestBody) {
    sf::Sprite sprite;
    HeatBox heatbox;
    MovementComponent movementComponent(sprite, 100.f, 10.f, 5.f, &heatbox);

    // Проверяем, что при начальных значениях velocity метод idle возвращает true
    ASSERT_TRUE(movementComponent.idle());

    // Изменяем velocity и проверяем, что теперь idle возвращает false
    movementComponent.move(1.f, 0.f, 0.1f);
    ASSERT_FALSE(movementComponent.idle());
}


// Тест проверки метода getVelocity
TEST(MovementComponentTest_GetVelocity, TestBody) {
    sf::Sprite sprite;
    HeatBox heatbox;
    MovementComponent movementComponent(sprite, 100.f, 10.f, 5.f, &heatbox);

    // Получаем начальную velocity и проверяем, что она равна (0, 0)
    sf::Vector2f initialVelocity = movementComponent.getVelocity();
    ASSERT_EQ(initialVelocity.x, 0.f);
    ASSERT_EQ(initialVelocity.y, 0.f);

    // Изменяем velocity и проверяем, что метод getVelocity возвращает актуальное значение
    movementComponent.move(1.f, -1.f, 0.1f);
    sf::Vector2f updatedVelocity = movementComponent.getVelocity();
    ASSERT_GT(updatedVelocity.x, 0.f);
    ASSERT_LT(updatedVelocity.y, 0.f);
}

// тесты для heatbox

// Тест для конструктора и геттеров getMaxHP и getCurrentHP
TEST(HeatBoxTest, ConstructorAndGetters) {
    HeatBox heatbox;
    ASSERT_EQ(heatbox.getMaxHP(), 100); // Проверяем значение максимального HP по умолчанию
    ASSERT_EQ(heatbox.getCurrentHP(), 100); // Проверяем значение текущего HP по умолчанию
}

