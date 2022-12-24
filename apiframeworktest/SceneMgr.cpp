#include "pch.h"
#include "SceneMgr.h"
#include "Scene_Start.h"
#include "Scene_Game.h"
#include "Scene_Win.h"
#include "Scene_Over.h"
#include "EventMgr.h"
#include "TimeMgr.h"
SceneMgr::SceneMgr()
	: m_pCurScene(nullptr)
	, m_arrScene{}
{
}

SceneMgr::~SceneMgr()
{
	// 씬 전부 삭제
	for (UINT i = 0; i < (UINT)SCENE_TYPE::END; ++i)
	{
		if (nullptr != m_arrScene[i])
		{
			delete m_arrScene[i];
		}
	}
}

void SceneMgr::ChangeScene(SCENE_TYPE _eNext)
{
	m_pCurScene->Exit();
	m_pCurScene = m_arrScene[(UINT)_eNext];
	m_pCurScene->Enter();
}

void SceneMgr::Init()
{
	// Scene 생성
	m_arrScene[(UINT)SCENE_TYPE::START] = new Scene_Start;
	m_arrScene[(UINT)SCENE_TYPE::START]->SetName(L"Start Scene");
	m_arrScene[(UINT)SCENE_TYPE::GAME] = new Scene_Game;
	m_arrScene[(UINT)SCENE_TYPE::GAME]->SetName(L"Game Scene");
	m_arrScene[(UINT)SCENE_TYPE::WIN] = new Scene_Win;
	m_arrScene[(UINT)SCENE_TYPE::WIN]->SetName(L"Win Scene");
	m_arrScene[(UINT)SCENE_TYPE::OVER] = new Scene_Over;
	m_arrScene[(UINT)SCENE_TYPE::OVER]->SetName(L"Over Scene");


	// 현재 씬 지정
	m_pCurScene = m_arrScene[(UINT)SCENE_TYPE::START];
	m_pCurScene->Enter();
}

void SceneMgr::Update()
{
	m_pCurScene->Update();
	m_pCurScene->FinalUpdate();
}

void SceneMgr::Render(HDC _dc)
{
	m_pCurScene->Render(_dc);
}

const bool SceneMgr::IsHamgingAttack()
{
	if (TimeMgr::GetInst()->IsOverDelay(5))
	{
		SceneMgr::GetInst()->SetIsAttack(false);
		return true;
	}
	return false;
}
