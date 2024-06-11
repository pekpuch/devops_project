#pragma once

#include "State.h"


class GameState :
    public State
{
private:
    Player* player;
    sf::Text hpText;
    sf::Font font;
    sf::Clock damageTimer;
    double energy = 100;
    bool block = false;
    sf::RectangleShape hpBar;
    sf::RectangleShape hpBarBack;

    //Функции
    void initKeybinds();
    void initTextures();
    void initPlayers();
    //void initColliders();
    void hp_upd();


public:
    GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~GameState();

    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = NULL);
};

