#pragma once

#include "State.h"
#include <queue>
#include "Platform.h"


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
    //::SoundBuffer soundBuffer;
    sf::Music mainMusic;
    
    std::vector<Platform*> platforms;
    std::queue<sf::FloatRect> queueCollision;

    //�������
    void initKeybinds();
    void initTextures();
    void initPlayers();
    void initMusic();
    void initPlatforms();
    void hp_upd();


public:
    GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~GameState();

    void updateCollision();

    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = NULL);
    void renderPlatforms(sf::RenderTarget* target = NULL);
};

