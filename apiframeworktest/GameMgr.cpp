#include "pch.h"
#include "GameMgr.h"
#include "Hamging.h"
#include "Player.h"
#include "TimeMgr.h"
#include "Scene_Game.h"
#include "Text.h"
#include "CardMgr.h"
#include "Core.h"

GameMgr::GameMgr() :m_hamgingState(HAMGING_STATE::WAIT)
{
}

GameMgr::~GameMgr()
{
}


const void GameMgr::UpdateTurnText(HAMGING_STATE state)
{
	wstring str = L"TURN ";
	Vec2 res = Core::GetInst()->GetResolution();
	if (state == HAMGING_STATE::ATTACKING)
	{
		str += L"HAMGING";
		m_turnText->SetPos(Vec2(0.0f, res.y / 2));
	}
	else if (state == HAMGING_STATE::END)
	{
		str += L"PLAYER";
		m_turnText->SetPos(Vec2(res.x - 300, res.y / 2));
	}
	m_turnText->SetText(str);
}

const void GameMgr::AttackPlayer(int damage)
{
	m_player->Attack(damage);

}

const void GameMgr::AttackHamging(int damage, int stress)
{
	m_hamging->Attack(damage);
	m_hamging->AttackStress(stress);
}

void GameMgr::Init()
{

}

void GameMgr::Update()
{
	if (isAttackEffect)
	{
		if (AttackEffectDuration(2))
		{
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
	UpdateTurnText(m_hamgingState);
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