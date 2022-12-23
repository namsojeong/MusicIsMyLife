#pragma once
#include "Scene.h"

class Player;
class Hamging;
class Text;
class TurnRect;
class Scene_Game
    :public Scene
{
private:
    Player* player;
    Hamging* hamging;

    TurnRect* turnUI;
private:
    Text* roundText;
    Text* playerText;
    Text* hamgingHPText;
    Text* attackEffectText;
private:
    bool isAttackEffect = false;
private:
    float attackTextDelay = 0;
public:
    virtual void Enter() override;
    virtual void Exit() override;
    virtual void Update() override;
public:
    Scene_Game();
    virtual ~Scene_Game();
};

