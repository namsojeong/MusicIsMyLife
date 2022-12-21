#pragma once
#include "Scene.h"

class Player;
class Hamging;
class Text;
class Scene_Game
	:public Scene
{
private:
    Player* player;
    Hamging* hamging;
private:
    Text* playerHPText;
    Text* hamgingHPText;
    Text* turnText;
    Text* attackEffectText;
    bool isAttackEffect = false;
private:
    float attackTextDelay = 0;
public:
    void AttackTextEffect(Text* text, CARD_TYPE type);
    const bool AttackEffectDuration(long delayTime);
public:
    virtual void Enter() override;
    virtual void Exit() override;
    virtual void Update() override;
public:
    Scene_Game();
    virtual ~Scene_Game();
};

