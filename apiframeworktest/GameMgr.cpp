#include "pch.h"
#include "GameMgr.h"
#include "Hamging.h"
#include "Player.h"
GameMgr::GameMgr() :m_hamgingState(HAMGING_STATE::WAIT)
{
}

GameMgr::~GameMgr()
{
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
const void GameMgr::AttackHamging(int _attackPow)
{
	m_hamging->hp->AddHP(-_attackPow);
}
const void GameMgr::AttackPlayer(int _attackPow)
{
	m_player->hp->AddHP(-_attackPow);
}