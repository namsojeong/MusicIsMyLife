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
	// image 업로드
	pImg = ResMgr::GetInst()->ImgLoad(L"HamgingAni", L"Image\\Hamging_Attack.bmp");

	// animator 생성 및 animation 사용
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
	// image 업로드
	pImg = ResMgr::GetInst()->ImgLoad(L"HamgingAni", L"Image\\Hamging_Attack.bmp");

	// animator 생성 및 animation 사용
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
}

const void Hamging::Heal(int addHP)
{
	hp->AddHP(addHP);
	if (hp->GetHP() > hp->GetMaxHP())
	{
		hp->SetHP(hp->GetMaxHP());
	}
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
		if (state == HAMGING_STATE::WAIT && GameMgr::GetInst()->GetIsChooseCard())
		{
			// 시간 함수
			if (TimeMgr::GetInst()->IsCanPlayerAttack())// 플레이어 공격시간이 지났다면
			{
				state = HAMGING_STATE::ATTACKING;
				GameMgr::GetInst()->SetHamgingState(state);
			}
		}
	}
	if (HAMGING_ATTACKING)
	{
		GameMgr::GetInst()->AttackPlayer(m_attackPower + m_attackPower * m_stress / 100);
		state = TimeMgr::GetInst()->IsOverDelay(3)?HAMGING_STATE::ATTACKEND:state;
	}
	if (HAMGING_ATTACKEND)
	{
		GameMgr::GetInst()->SetIsChooseCard(false);
		state = HAMGING_STATE::WAIT;
	}
	GetAnimator()->Update();
}

void Hamging::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	int Width = (int)pImg->GetWidth();
	int Height = (int)pImg->GetHeight();
	//마젠타 색상 뺄때 transparent: 투명한
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
