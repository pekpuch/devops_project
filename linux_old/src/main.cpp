#include "Game.h"
#include "test.cpp"
#include <gtest/gtest.h>

int main(int argc, char **argv) {
    Game game;
    game.run();

    // Инициализируем Google Test
    ::testing::InitGoogleTest(&argc, argv);
    // Запускаем тесты
    int testResult = RUN_ALL_TESTS();
    if (testResult == 0) printf("GOOOOOOOOOOOOOL\n");

    return 0;
}