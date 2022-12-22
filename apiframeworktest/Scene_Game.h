#pragma once
#include "Scene.h"

class Player;
class Hamging;
class Text;
class Image;
class Scene_Game
    :public Scene
{
private:
    Player* player;
    Hamging* hamging;
private:
    Text* turnText;
    Text* roundText;
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

