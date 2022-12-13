#pragma once
#include "Scene.h"

class Scene_Game
	:public Scene
{
private:
    float gameTime = 0;
public:
    virtual void Enter() override;
    virtual void Exit() override;
    virtual void Update() override;

public:
    Scene_Game();
    virtual ~Scene_Game();
};

