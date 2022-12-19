#include "pch.h"
#include "Hamging.h"
#include "GameMgr.h"
#include "TimeMgr.h"
#include "ResMgr.h"
#include "Animator.h"
#include "Image.h"
#include "Core.h"
#include "Player.h"

Hamging::Hamging():state(HAMGING_STATE::WAIT)
{
	hp = new HP(100);
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

void Hamging::Update()
{
	if (HAMGING_WAIT)
	{
		if (state != HAMGING_STATE::WAIT)
			state = HAMGING_STATE::WAIT;
		if (state == HAMGING_STATE::WAIT)
		{
			// 시간 함수
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
	//마젠타 색상 뺄때 transparent: 투명한
	TransparentBlt(_dc
		, (int)(vPos.x - (float)(Width / 2))
		, (int)(vPos.y - (float)(Height / 2))
		,Width, Height
	    , pImg->GetDC()
	    ,0,0, Width, Height
	    , RGB(255,0,255));
	Component_Render(_dc);
}


Hamging::~Hamging()
{
}
