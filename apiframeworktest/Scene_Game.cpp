#include "pch.h"
#include "Scene_Game.h"
#include "Object.h"
#include "Player.h"
#include "Monster.h"
#include "Core.h"
#include "Image.h"
#include "PathMgr.h"
#include "CollisionMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "SoundMgr.h"
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
	player = new Player;
	player->SetPos(Vec2(vResolution.x / 2, vResolution.y / 2));
	player->SetScale(Vec2(100.f, 100.f));
	AddObject(player, GROUP_TYPE::PLAYER);

	//// 몬스터 배치
	//int iMonster = 16;
	//float fMoveDist = 25.f;
	//float fObjScale = 50.f;
	//float fTerm = (vResolution.x - ((fMoveDist + fObjScale / 2.f) * 2)) / (float)(iMonster - 1);
	//Monster* pMonsterObj = nullptr;
	//for (int i = 0; i < iMonster; i++)
	//{
	//	pMonsterObj = new Monster;
	//	pMonsterObj->SetName(L"Monster");
	//	pMonsterObj->SetPos(Vec2((fMoveDist + fObjScale / 2.f) + (float)i * fTerm, 50.f));
	//	pMonsterObj->SetScale(Vec2(fObjScale, fObjScale));
	//	pMonsterObj->SetCenterPos(pMonsterObj->GetPos());
	//	pMonsterObj->SetMoveDistance(fMoveDist);
	//	AddObject(pMonsterObj, GROUP_TYPE::MONSTER);
	//}
#pragma region 카드배치
	Card* pCardObj = nullptr;

	for (int i = 0; i < GetCardAmount(); i++)
	{
		pCardObj = new Card;
		pCardObj->SetName(L"Card");
		pCardObj->SetPos(Vec2((vResolution.x / (GetCardAmount() + 1)) * (i + 1),
			vResolution.y / 2));
		pCardObj->SetScale(Vec2(200.f, 277.f));
		pCardObj->SetCenterPos(pCardObj->GetPos());
		AddObject(pCardObj, GROUP_TYPE::CARD);
	}
#pragma endregion
	//pObj = new Object;

	//pObj->SetPos(Vec2(640.f, 384.f));
	//pObj->SetScale(Vec2(100.f, 100.f));

	//AddObject(pObj, GROUP_TYPE::DEFAULT);
	// 충돌 지정 
	// Player - Monster 그룹 간의 충돌 체크
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::MONSTER);
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::BULLET_PLAYER, GROUP_TYPE::MONSTER);
	
	Vec2 timePos = Vec2(0, 0);
	wstring timeT = L"Time : " + to_wstring(gameTime);
	Text* timeText = new Text(timePos, 30, timeT);
	AddUI(timeText, UI_TYPE::TEXT);

	Vec2 playerHPTextPos = Vec2(0.0f, vResolution.y/2);
	wstring playerHPTextStr = L"HP : " + to_wstring(player->GetPlayerHP());
	playerHPText = new Text(playerHPTextPos, 30, playerHPTextStr);
	AddUI(playerHPText, UI_TYPE::TEXT);
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
		player->hp->UpdateUiHp(playerHPText);
	}
}