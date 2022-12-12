#include "pch.h"
#include "Scene_Start.h"
#include "Core.h"
#include "KeyMgr.h"
#include "Button.h"

Scene_Start::Scene_Start()
{
}

Scene_Start::~Scene_Start()
{
}

void Scene_Start::Enter()
{
	Vec2 vResolution(Vec2(Core::GetInst()->GetResolution()));
	Button* startButton = new Button(Vec2(vResolution.x/2, vResolution.y/2), Vec2(200.0f, 100.0f));
	AddUI(startButton, UI_TYPE::BUTTON);
}

void Scene_Start::Exit()
{
	
}

void Scene_Start::Update()
{  
	Scene::Update();
}
