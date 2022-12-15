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
	// Object 추가
	Object* pObj = new Player;
	pObj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));
	pObj->SetScale(Vec2(100.f, 100.f));
	AddObject(pObj, GROUP_TYPE::PLAYER);

	// 몬스터 배치
	/*Vec2 vResolution(Vec2(Core::GetInst()->GetResolution()));
	Vec2 fObjScale = Vec2(330,370);
	Monster* pMonsterObj = nullptr;
	pMonsterObj = new Monster;
	pMonsterObj->SetName(L"Monster");
	pMonsterObj->SetPos(Vec2((fObjScale / 2.f) + (float)i * fTerm, 50.f));
	pMonsterObj->SetScale(Vec2(fObjScale, fObjScale));
	pMonsterObj->SetCenterPos(pMonsterObj->GetPos());
	pMonsterObj->SetMoveDistance(fMoveDist);
	AddObject(pMonsterObj, GROUP_TYPE::MONSTER);*/
#pragma region 카드배치
	Card* pCardObj = nullptr;

	for (int i = 0; i < GetCardAmount(); i++)
	{
		pCardObj = new Card(1);
		pCardObj->SetName(L"Card");
		pCardObj->SetPos(Vec2((1280/ (GetCardAmount() + 1)) * (i + 1),
			800 / 2));
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
	
	Vec2 timeScale = Vec2(100.0f, 100.0f);
	Vec2 timePos = Vec2(0, 0);
	wstring timeT = L"Time : " + to_wstring(gameTime);
	Text* timeText = new Text(timePos, timeScale, timeT);
	timeText->SetFontColor(RGB(0, 0, 0));
	AddUI(timeText, UI_TYPE::TEXT);
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
