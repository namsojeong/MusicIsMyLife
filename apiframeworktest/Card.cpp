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
#include "Bullet.h"
#include "Scene.h"
#include "SoundMgr.h"

Card::Card(int type, Player* p) :
	_attackPower(0),
	_stressPower(0),
	m_pImage(nullptr)
{
	SoundMgr::GetInst()->LoadSound(L"CARD", false, L"Sound\\card.wav");
	m_type = type;
	m_player = p;
	// image ���ε�

	SetCardType(m_type);
}

Card::~Card()
{
}

void Card::Update()
{
	Vec2 vPos = GetPos();
	m_vPos = vPos;
	HAMGING_STATE hamging_state = GameMgr::GetInst()->GetHamgingState();
	bool isPlayerAttack = GameMgr::GetInst()->GetIsPlayerAttack();
	if (!isPlayerAttack && hamging_state == HAMGING_STATE::WAIT)
	{
		Attack();
	}
	if (KEY_AWAY(KEY::CLICK))
	{
		POINT* m_point = EventMgr::GetInst()->GetPoint();
		if (EventMgr::GetInst()->isOn(GetPos() + GetScale() / 2, GetScale())&& isUsed)
		{
			SoundMgr::GetInst()->Play(L"CARD");
			SetPos(vPos + Vec2(0, 50));
			isUsed = false;
		}
	}
	if (isPlayerAttack)
		DownCard();
	else
		UpCard();
	if (m_vPos.y >= 800)
	{
		srand((unsigned int)time(NULL));
		int a = rand() % 5 + 1;
		m_type = (m_type + a)%5+1;
		SetCardType(m_type);
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
			GameMgr::GetInst()->AttackTextEffect(cardType);
			CreateBullet();
			isUsed = true;
		}
	}
	
}

void Card::UpCard()
{
	if (m_vPos.y > 800)
		SetPos(GetPos() - Vec2(0, 20));
	else if (m_vPos.y > 700)
		SetPos(GetPos() - Vec2(0, 16));
	else if(m_vPos.y > 600)
		SetPos(GetPos() - Vec2(0, 12));
}

void Card::DownCard()
{
	if(m_vPos.y < 600)
		SetPos(GetPos() + Vec2(0, 12));
	else if (m_vPos.y < 700)
		SetPos(GetPos() + Vec2(0, 8));
	else if (m_vPos.y < 820)
		SetPos(GetPos() + Vec2(0, 4));
}

void Card::SetCardType(int type)
{
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
void Card::CreateBullet()
{
	Vec2 vBulletPos = GetPos();
	Vec2 targetPos = GameMgr::GetInst()->GetHamgingPos() 
		+ GameMgr::GetInst()->GetHamgingScale() / 2;
	Bullet* pBullet = new Bullet(cardType, targetPos - GetScale(), vBulletPos, Vec2(100, 100), _attackPower,_stressPower);
	pBullet->SetName(L"BULLET_CARD");
	//CreateObject(pBullet, GROUP_TYPE::BULLET_CARD);

	SceneMgr::GetInst()->GetCurScene()->AddObject(pBullet, GROUP_TYPE::BULLET_CARD);
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



