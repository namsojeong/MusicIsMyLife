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
    Text* playerHPText;
    Text* hamgingHPText;
    float gameTime = 0;
public:
    virtual void Enter() override;
    virtual void Exit() override;
    virtual void Update() override;

public:
    Scene_Game();
    virtual ~Scene_Game();
};

