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
#include "CardMgr.h"
#include "Text.h"
#include "TimeMgr.h"

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
	hamging = new Hamging(100, Vec2(330.f, 370.f));
	hamging->SetName(L"Hamging");
	hamging->SetPos(Vec2(vResolution.x / 2, vResolution.y / 4) );
	AddObject(hamging, GROUP_TYPE::HAMGING);

	player = new Player();
	player->SetPos(Vec2(vResolution.x / 2, vResolution.y / 2));
	player->SetScale(Vec2(100.f, 100.f));
	AddObject(player, GROUP_TYPE::PLAYER);

#pragma region 카드배치
	Card* pCardObj = nullptr;
	srand((unsigned int)time(NULL));
	int a = rand() % 5 + 1;
	int b = rand() % 5 + 1;
	int c = rand() % 5 + 1;
	for (int i = 0; i < GetCardAmount(); i++)
	{
		if(i == 0)
			pCardObj = new Card(a, player);
		if (i == 1)
			pCardObj = new Card(b, player);
		if (i == 2)
			pCardObj = new Card(c, player);
		pCardObj->SetName(L"Card");
		pCardObj->SetPos(Vec2((1280 / (GetCardAmount() + 1)) * (i + 1),
			800 / 2));
		pCardObj->SetScale(Vec2(200.f, 275.f));
		pCardObj->SetCenterPos(pCardObj->GetPos());
		AddObject(pCardObj, GROUP_TYPE::CARD);
	}
#pragma endregion

#pragma region Text

	Vec2 turnPos = Vec2(vResolution.x / 2, 0.f);
	Vec2 attackEffectPos = Vec2(50.0f, 500.f);
	Vec2 playerHPTextPos = Vec2(0.0f, vResolution.y / 2);
	Vec2 hamgingHPTextPos = Vec2(0.0f, vResolution.y / 4);

	wstring turnStr = L"Turn Player";
	wstring attackEffectStr = L"";
	wstring playerHPTextStr = L"HP : " + to_wstring(player->GetPlayerHP());
	wstring hamgingHPTextStr = L"HP : " + to_wstring(hamging->GetHamgingHP());

	turnText = new Text(turnPos, 30, turnStr);
	playerHPText = new Text(playerHPTextPos, 30, playerHPTextStr);
	hamgingHPText = new Text(hamgingHPTextPos, 30, hamgingHPTextStr);
	attackEffectText = new Text(attackEffectPos, 20, attackEffectStr);

	AddUI(turnText, UI_TYPE::TEXT);
	AddUI(playerHPText, UI_TYPE::TEXT);
	AddUI(hamgingHPText, UI_TYPE::TEXT);
	AddUI(attackEffectText, UI_TYPE::TEXT);

	GameMgr::GetInst()->SetAttackText(attackEffectText);
	GameMgr::GetInst()->SetTurnText(turnText);
	GameMgr::GetInst()->SetHamgingText(hamgingHPText);
	GameMgr::GetInst()->SetPlayerText(playerHPText);

	GameMgr::GetInst()->SetObject(player, hamging);
#pragma endregion
}

void Scene_Game::Exit()
{
	DeleteAll();
	CollisionMgr::GetInst()->CheckReset();
}

void Scene_Game::Update()
{
	Scene::Update();
}

