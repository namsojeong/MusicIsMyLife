#include "pch.h"
#include "Scene_Game.h"
#include "Object.h"
#include "Player.h"
#include "Hamging.h"
#include "Monster.h"
#include "Core.h"
#include "Image.h"
#include "PathMgr.h"
#include "CollisionMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "SoundMgr.h"
#include "GameMgr.h"
#include "Card.h"
#include "Text.h"

Scene_Game::Scene_Game()
{
}

Scene_Game::~Scene_Game()
{
}

void Scene_Game::Enter()
{
	SoundMgr::GetInst()->LoadSound(L"BGM", true, L"Sound\\pianobgm.wav");
	SoundMgr::GetInst()->Play(L"BGM");

	Vec2 vResolution(Vec2(Core::GetInst()->GetResolution()));

	// Object 추가
	hamging = new Hamging();
	hamging->SetPos(Vec2(vResolution.x / 2, vResolution.y / 4));
	hamging->SetScale(Vec2(330.f, 370.f));
	AddObject(hamging, GROUP_TYPE::HAMGING);

	player = new Player();
	player->SetPos(Vec2(vResolution.x / 2, vResolution.y / 2));
	player->SetScale(Vec2(100.f, 100.f));
	AddObject(player, GROUP_TYPE::PLAYER);

#pragma region 카드배치
	Card* pCardObj = nullptr;

	for (int i = 0; i < GetCardAmount(); i++)
	{
		pCardObj = new Card(1, player);
		pCardObj->SetName(L"Card");
		pCardObj->SetPos(Vec2((1280/ (GetCardAmount() + 1)) * (i + 1),
			800 / 2));
		pCardObj->SetScale(Vec2(200.f, 277.f));
		pCardObj->SetCenterPos(pCardObj->GetPos());
		AddObject(pCardObj, GROUP_TYPE::CARD);
	}
#pragma endregion

	Vec2 timePos = Vec2(0, 0);
	wstring timeT = L"Time : " + to_wstring(gameTime);
	Text* timeText = new Text(timePos, 30, timeT);
	AddUI(timeText, UI_TYPE::TEXT);

	Vec2 playerHPTextPos = Vec2(0.0f, vResolution.y / 2);
	wstring playerHPTextStr = L"HP : " + to_wstring(player->GetPlayerHP());
	playerHPText = new Text(playerHPTextPos, 30, playerHPTextStr);
	AddUI(playerHPText, UI_TYPE::TEXT);
	GameMgr::GetInst()->SetObject(player, hamging);
}

void Scene_Game::Exit()
{
	DeleteAll();
	CollisionMgr::GetInst()->CheckReset();
}

void Scene_Game::Update()
{
	Scene::Update();

	if (KEY_TAP(KEY::SPACE))
	{
		player->hp->AddHP(-10);
		if (player->hp->IsDead())
		{
			ChangeScene(SCENE_TYPE::OVER);
		}
		player->hp->UpdateUiHp(playerHPText);

		hamging->stress->AddStress(10);

	}
}