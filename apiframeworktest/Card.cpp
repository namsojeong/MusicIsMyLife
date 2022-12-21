#include "pch.h"
#include "Card.h"
#include "ResMgr.h"
#include "Animator.h"
#include "Image.h"
#include "SceneMgr.h"
#include "KeyMgr.h"
#include "EventMgr.h"
#include "TimeMgr.h"
#include "CardMgr.h"
#include "GameMgr.h"
#include "Player.h"
Card::Card(int type, Player* p) :
	_attackPower(0),
	_stressPower(0),
	m_pImage(nullptr)
{
	m_player = p;
	// image ���ε�

	m_pImage = CardMgr::GetInst()->GetCardImage(type);
	for (UINT i = 0; i < (UINT)CARD_TYPE::END; i++)
	{
		if (type == i)
		{
			cardType = (CARD_TYPE)type;
			_attackPower = CardMgr::GetInst()->GetCardStat(i)._attackPower;
			_stressPower = CardMgr::GetInst()->GetCardStat(i)._stressPower;
		}
	}
}

Card::~Card()
{
}

void Card::Update()
{
	Vec2 vPos = GetPos();
	if (!GameMgr::GetInst()->GetIsPlayerAttack())
	{
		Attack();
	}
	if (KEY_AWAY(KEY::CLICK))
	{
		POINT* m_point = EventMgr::GetInst()->GetPoint();
		if (EventMgr::GetInst()->isOn(GetPos() + GetScale() / 2, GetScale())&& isUsed)
		{
			SetPos(vPos + Vec2(0, 50));
			isUsed = false;
		}
	}
}

void Card::Attack()
{
	Vec2 vPos = GetPos();
	if (KEY_TAP(KEY::CLICK))
	{
		POINT* m_point = EventMgr::GetInst()->GetPoint();
		GetCursorPos(m_point);
		if (EventMgr::GetInst()->isOn(GetPos()+GetScale()/2, GetScale()))
		{
			SetPos(vPos + Vec2(0, -50));
			GameMgr::GetInst()->SetIsPlayerAttack(true);
			GameMgr::GetInst()->AttackHamging(_attackPower, _stressPower);
			GameMgr::GetInst()->AttackTextEffect(cardType);
			isUsed = true;
		}
	}
	
}

void Card::Render(HDC _dc)
{
	int Width = (int)m_pImage->GetWidth();
	int Height = (int)m_pImage->GetHeight();
	Vec2 vPos = GetPos();
	TransparentBlt(_dc
		, (int)(vPos.x - (float)(Width / 2))
		, (int)(vPos.y - (float)(Height / 2))
		, Width, Height
		, m_pImage->GetDC()
		, 0, 0, Width, Height
		, RGB(255, 0, 255));
	Component_Render(_dc);
}
