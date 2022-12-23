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
	SetBackground(L"Background_Game", L"Image//background_1.bmp");
}

Scene_Game::~Scene_Game()
{
}

void Scene_Game::Enter()
{
	SoundMgr::GetInst()->Stop(SOUND_CHANNEL::SC_BGM);
	SoundMgr::GetInst()->LoadSound(L"BGM", true, L"Sound\\gameBgm.wav");
	SoundMgr::GetInst()->Play(L"BGM");

	Vec2 vResolution(Vec2(Core::GetInst()->GetResolution()));

	// Object 추가
	hamging = new Hamging(100, Vec2(330.f, 370.f));
	hamging->SetName(L"HAMGING");
	hamging->SetPos(Vec2(vResolution.x / 2, vResolution.y / 4+200));
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
		if (i == 0)
			pCardObj = new Card(a, player);
		if (i == 1)
			pCardObj = new Card(b, player);
		if (i == 2)
			pCardObj = new Card(c, player);
		pCardObj->SetName(L"Card");
		pCardObj->SetPos(Vec2((900 / (GetCardAmount() + 1)) * (i + 1),
			1200 / 2) + Vec2(400,0));
		pCardObj->SetScale(Vec2(200.f, 275.f));
		pCardObj->SetCenterPos(pCardObj->GetPos());
		AddObject(pCardObj, GROUP_TYPE::CARD);
	}
#pragma endregion

#pragma region Text

	Vec2 turnPos = Vec2(20.0f, vResolution.y / 2);
	Vec2 roundPos = Vec2(vResolution.x/2-40, 50.0f);
	Vec2 playerPos = Vec2(50.0f, vResolution.y/2 + 280);
	Vec2 hamgingHPPos = Vec2(vResolution.x / 2 - 145, 135.0f);
	Vec2 attackEffectPos = Vec2(800.0f, 300.f);

	wstring turnStr = L"Turn Player";
	wstring roundStr = L"ROUND " + to_wstring(ROUND);
	wstring playerStr = L"PLAYER";
	wstring hamgingHPStr = to_wstring(hamging->hp->GetHP());
	wstring attackEffectStr = L"";

	turnText = new Text(turnPos, 30, turnStr);
	roundText = new Text(roundPos, 30, roundStr);
	playerText = new Text(playerPos, 25, playerStr);
	hamgingHPText = new Text(hamgingHPPos, 25, hamgingHPStr);
	attackEffectText = new Text(attackEffectPos, 20, attackEffectStr);

	AddUI(turnText, UI_TYPE::TEXT);
	AddUI(roundText, UI_TYPE::TEXT);
	AddUI(playerText, UI_TYPE::TEXT);
	AddUI(hamgingHPText, UI_TYPE::TEXT);
	AddUI(attackEffectText, UI_TYPE::TEXT);

	GameMgr::GetInst()->SetAttackText(attackEffectText);
	GameMgr::GetInst()->SetTurnText(turnText);
	GameMgr::GetInst()->SetRoundText(roundText);
	GameMgr::GetInst()->SetHamgingHPText(hamgingHPText);

	GameMgr::GetInst()->SetObject(player, hamging);
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::BULLET_CARD, GROUP_TYPE::HAMGING);
#pragma endregion
}

void Scene_Game::Exit()
{
	CollisionMgr::GetInst()->CheckReset();
	DeleteAll();
}

void Scene_Game::Update()
{
	Scene::Update();
	if (KEY_TAP(KEY::ENTER))
	{
		GameMgr::GetInst()->NextRound();
	}

}
