#include "pch.h"
#include "Scene_Start.h"
#include "Core.h"
#include "KeyMgr.h"
#include "Button.h"
#include "Text.h"

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
	
	Vec2 titlePos = Vec2(vResolution.x / 2, vResolution.y / 2 - 200);
	Vec2 titleScale = Vec2(100.0f, 100.0f);
	Text* titleText = new Text(titlePos, titleScale, L"Music is myLife");
	AddUI(titleText, UI_TYPE::TEXT);
}

void Scene_Start::Exit()
{
	
}

void Scene_Start::Update()
{  
	Scene::Update();
}
