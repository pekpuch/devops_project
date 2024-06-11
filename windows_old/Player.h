#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "heatbox.h"
class Player :
    public Entity
{
private:

    //init func
    void initVariables();
    void initComponents();

public:
    Player(float x, float y, sf::Texture& texture);
    virtual ~Player();
    virtual void update(const float& dt); //��������!!!!!!!!!!!!
    //�������
};

#endif
