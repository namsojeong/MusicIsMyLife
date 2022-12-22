#include "pch.h"
#include "Scene_Over.h"
#include "Core.h"
#include "KeyMgr.h"
#include "Button.h"
#include "Text.h"
#include "QuitButton.h"
#include "StartButton.h"
#include "RestartButton.h"

void Scene_Over::Enter()
{
	Vec2 vResolution(Vec2(Core::GetInst()->GetResolution()));

	Vec2 titlePos = Vec2(vResolution.x / 2 - 270, vResolution.y / 2 - 200);
	Text* titleText = new Text(titlePos, 80, L"SCORE\n" + to_wstring(100));
	AddUI(titleText, UI_TYPE::TEXT);

	/* Vec2 titlePos = Vec2(vResolution.x / 2 - 270, vResolution.y / 2 - 200);
	Text* titleText = new Text(titlePos, 80, L"Music is myLife");
	AddUI(titleText, UI_TYPE::TEXT);*/

	RestartButton* restartButton = new RestartButton(Vec2(vResolution.x / 2, vResolution.y / 2));
	AddUI(restartButton, UI_TYPE::BUTTON);

	QuitButton* quitButton = new QuitButton(Vec2(vResolution.x / 2, vResolution.y / 2 + 150));
	AddUI(quitButton, UI_TYPE::BUTTON);
}

void Scene_Over::Exit()
{
	DeleteAll();
}

void Scene_Over::Update()
{
	Scene::Update();
}

Scene_Over::Scene_Over()
{
}

Scene_Over::~Scene_Over()
{
}
