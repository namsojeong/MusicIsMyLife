#include "pch.h"
#include "GameMgr.h"
#include "Hamging.h"
#include "Player.h"
#include "TimeMgr.h"
GameMgr::GameMgr() :m_hamgingState(HAMGING_STATE::WAIT)
{
}

GameMgr::~GameMgr()
{
}

const void GameMgr::AttackPlayer(int damage)
{
	m_player->Attack(damage);
}

const void GameMgr::AttackHamging(int damage)
{
	m_hamging->Attack(damage);
}

void GameMgr::Init()
{

}

void GameMgr::Update()
{
}

const void GameMgr::SetObject(Player* p, Hamging* h)
{
	m_player = p;
	m_hamging = h;
}


const bool GameMgr::HamgingAttackTimer()
{
	return TimeMgr::GetInst()->IsOverHamgingAttackDelay(3);
}

const bool GameMgr::PlayerAttackTimer()
{
	isPlayerAttack = !TimeMgr::GetInst()->IsOverPlayerAttackDelay(3);
	return isPlayerAttack;
}