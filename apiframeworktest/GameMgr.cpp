#include "pch.h"
#include "GameMgr.h"
#include "Hamging.h"
#include "Player.h"
#include "TimeMgr.h"
#include "Scene_Game.h"
#include "Text.h"
#include "CardMgr.h"
#include "PathMgr.h"
#include "Core.h"

GameMgr::GameMgr() :m_hamgingState(HAMGING_STATE::WAIT)
{
}

GameMgr::~GameMgr()
{
	RemoveFontResource(L"Katuri.ttf");
}

const void GameMgr::AttackPlayer(int damage)
{
	m_player->Attack(damage);

}

const void GameMgr::AttackHamging(CARD_TYPE type, int damage, int stress)
{
	m_hamging->SetHamgingSkin(type);
	m_hamging->AttackStress(stress);
	if (damage < 0)
	{
		m_player->Heal(-damage);
	}
	else
	{
		m_hamging->Attack(damage);
	}
}

void GameMgr::Init()
{
	wstring strFilePath = PathMgr::GetInst()->GetRsrcPath();
	strFilePath += L"Katuri.ttf";
	LPCWSTR path = strFilePath.c_str();
	AddFontResource(path);
}

void GameMgr::Update()
{
	if (isAttackEffect)
	{
		if (AttackEffectDuration(2))
		{
			m_hamging->SetHamgingSkin(CARD_TYPE::END);
			m_attackText->SetText(CardMgr::GetInst()->cardStr[(UINT)CARD_TYPE::END]);
			isAttackEffect = false;
		}
	}
}

const void GameMgr::SetObject(Player* p, Hamging* h)
{
	m_player = p;
	m_hamging = h;
}

const void GameMgr::SetHamgingState(HAMGING_STATE value)
{
	m_hamgingState = value;
}

const bool GameMgr::HamgingAttackTimer()
{
	return TimeMgr::GetInst()->IsOverHamgingAttackDelay(3);
}

const bool GameMgr::PlayerAttackTimer()
{
	isPlayerAttack = TimeMgr::GetInst()->IsOverPlayerAttackDelay(4);
	return isPlayerAttack;
}

const void GameMgr::NextRound()
{
	round++;
	hamging_hp *= 1.4;
	hamging_power *= 1.2f;
	ChangeScene(SCENE_TYPE::WIN);
}

const void GameMgr::AttackTextEffect(CARD_TYPE type)
{
	m_attackText->SetText(CardMgr::GetInst()->cardStr[(UINT)type]);
	isAttackEffect = true;
}

const bool GameMgr::AttackEffectDuration(long delayTime)
{
	return TimeMgr::GetInst()->IsOverHamgingAttackDelay(delayTime);
}

Vec2 GameMgr::GetHamgingPos()
{
	return m_hamging->GetPos();
}

Vec2 GameMgr::GetHamgingScale()
{
	return m_hamging->GetScale();
}