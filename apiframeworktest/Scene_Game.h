#pragma once
#include "Scene.h"

class Player;
class Text;
class Scene_Game
	:public Scene
{
private:
    Player* player;
    Text* playerHPText;
    float gameTime = 0;
public:
    virtual void Enter() override;
    virtual void Exit() override;
    virtual void Update() override;

public:
    Scene_Game();
    virtual ~Scene_Game();
};

