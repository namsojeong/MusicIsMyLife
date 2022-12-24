#include "pch.h"
#include "Scene_Win.h"
#include "Core.h"
#include "KeyMgr.h"
#include "Button.h"
#include "Text.h"
#include "QuitButton.h"
#include "StartButton.h"
#include "NextroundButton.h"
#include "SoundMgr.h"

Scene_Win::Scene_Win()
{
	SetBackground(L"", L"");
}

Scene_Win::~Scene_Win()
{
}

void Scene_Win::Enter()
{
	SoundMgr::GetInst()->Stop(SOUND_CHANNEL::SC_BGM);
	SoundMgr::GetInst()->LoadSound(L"dBGM", true, L"Sound\\defaultBgm.wav");
	SoundMgr::GetInst()->Play(L"dBGM");
	Vec2 vResolution(Vec2(Core::GetInst()->GetResolution()));

	Vec2 titlePos = Vec2(vResolution.x / 2 - 350, vResolution.y / 2 - 200);
	Text* titleText = new Text(titlePos, 65, L"햄깅이가 조금 더 부지런해졌어요!");
	AddUI(titleText, UI_TYPE::TEXT);

	NextroundButton* nextButton = new NextroundButton(Vec2(vResolution.x / 2, vResolution.y / 2));
	AddUI(nextButton, UI_TYPE::BUTTON);
}

void Scene_Win::Exit()
{
	DeleteAll();
}

void Scene_Win::Update()
{
	Scene::Update();
}
