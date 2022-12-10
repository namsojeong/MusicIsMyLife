#pragma once
#include "Scene.h"

class Scene_Game
	:public Scene
{
public:
    virtual void Enter() override;
    virtual void Exit() override;
    virtual void Update() override;

public:
    Scene_Game();
    virtual ~Scene_Game();
};

