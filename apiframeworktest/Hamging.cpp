#include "pch.h"
#include "Hamging.h"
#include "GameMgr.h"
#include "TimeMgr.h"
#include "ResMgr.h"
#include "Animator.h"
#include "Image.h"
#include "Core.h"
#include "Player.h"

Hamging::Hamging(int setHP) :state(HAMGING_STATE::WAIT)
{
	hp = new HP(setHP);
	stress = new Stress(100);
	// image ���ε�
	pImg = ResMgr::GetInst()->ImgLoad(L"HamgingAni", L"Image\\Hamging_Attack.bmp");

	// animator ���� �� animation ���
	CreateAnimator();
	GetAnimator()->CreateAnimation(
		L"HamgingAni",
		pImg,
		Vec2(0.f, 0.f),
		Vec2(330.f, 370.f),
		Vec2(330.f, 0.f),
		4,
		0.2f);
	pImg;
	Animation* pAnim = GetAnimator()->FindAnimation(L"HamgingAni");
	GetAnimator()->Play(L"HamgingAni", true);
}

Hamging::Hamging():state(HAMGING_STATE::WAIT)
{
	hp = new HP(100);
	stress = new Stress(100);
	// image ���ε�
	pImg = ResMgr::GetInst()->ImgLoad(L"HamgingAni", L"Image\\Hamging_Attack.bmp");

	// animator ���� �� animation ���
	CreateAnimator();
	GetAnimator()->CreateAnimation(
		L"HamgingAni", 
		pImg, 
		Vec2(0.f, 0.f), 
		Vec2(330.f, 370.f), 
		Vec2(330.f, 0.f),
		4, 
		0.2f);
	pImg;
	Animation* pAnim = GetAnimator()->FindAnimation(L"HamgingAni");
	GetAnimator()->Play(L"HamgingAni", true);
}

const void Hamging::Attack(int damage)
{
	hp->AddHP(-damage);
	if (hp->IsDead())
	{
		Die();
	}
	hp->UpdateUiHp(GameMgr::GetInst()->GetHamgingText());
}

const void Hamging::Heal(int addHP)
{
	hp->AddHP(addHP);
	if (hp->GetHP() > hp->GetMaxHP())
	{
		hp->SetHP(hp->GetMaxHP());
	}
	hp->UpdateUiHp(GameMgr::GetInst()->GetHamgingText());
}

const void Hamging::AttackStress(int damage)
{
	stress->AddStress(damage);
	if (stress->GetStress() <= stress->GetMaxStress())
	{
		stress->SetStress(stress->GetMaxStress());
	}
}

const void Hamging::HealStress(int addHP)
{
	stress->AddStress(-addHP);
	if (stress->GetStress() <= 0)
	{
		stress->SetStress(0);
	}
}

void Hamging::Update()
{
	if (HAMGING_WAIT)
	{
		if (state != HAMGING_STATE::WAIT)
			state = HAMGING_STATE::WAIT;
		if (state == HAMGING_STATE::WAIT)
		{
			// �ð� �Լ�
			if (GameMgr::GetInst()->GetIsPlayerAttack())
			{
				state = HAMGING_STATE::ATTACKING;
				GameMgr::GetInst()->SetHamgingState(state);
			}
		}
	}
	if (HAMGING_ATTACKING)
	{
		if (!GameMgr::GetInst()->GetIsHamgingAttack())
		{
			GameMgr::GetInst()->AttackPlayer(10 + m_attackPower * m_stress / 100);
			GameMgr::GetInst()->SetIsHamgingAttack(true);
			state = TimeMgr::GetInst()->IsOverDelay(2)?HAMGING_STATE::ATTACKEND:state;
		}
	}
	if (HAMGING_ATTACKEND)
	{
		state = HAMGING_STATE::WAIT;
		GameMgr::GetInst()->SetIsHamgingAttack(false);
	}
	GetAnimator()->Update();
}

void Hamging::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	int Width = (int)pImg->GetWidth();
	int Height = (int)pImg->GetHeight();
	//����Ÿ ���� ���� transparent: ������
	TransparentBlt(_dc
		, (int)(vPos.x - (float)(Width / 2))  
		, (int)(vPos.y - (float)(Height / 2))
		,Width, Height
	    , pImg->GetDC()
	    ,0,0, Width, Height
	    , RGB(255,0,255));

	Vec2 resolition = Vec2(Core::GetInst()->GetResolution());
	stress->UpdateUiStress(_dc, Vec2(resolition.x, resolition.y/2));

	Component_Render(_dc);
}

void Hamging::Die()
{
	ChangeScene(SCENE_TYPE::GAME);
}


Hamging::~Hamging()
{
}
