#pragma once
#include "Scene.h"
class Scene_Over
	:public Scene
{
private:
    vector<UI*> m_vecUI[(UINT)UI_TYPE::END];
public:
    virtual void Enter() override;
    virtual void Exit() override;
    virtual void Update() override;

public:
    Scene_Over();
    virtual ~Scene_Over();
};

