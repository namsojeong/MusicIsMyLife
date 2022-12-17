#include "pch.h"
#include "Hamging.h"
#include "GameMgr.h"
#include "TimeMgr.h"
#include "ResMgr.h"
#include "Animator.h"
#include "Image.h"
#include "Core.h"
#include "Player.h"

Hamging::Hamging()
{
	hp = new HP(100);
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

void Hamging::Update()
{
	if (HAMGING_WAIT)
	{
		if (state != HAMGING_STATE::WAIT)
			state = HAMGING_STATE::WAIT;
		if (state == HAMGING_STATE::WAIT && GameMgr::GetInst()->GetIsChooseCard())
		{
			// �ð� �Լ�
			if (TimeMgr::GetInst()->IsCanPlayerAttack())// �÷��̾� ���ݽð��� �����ٸ�
			{
				state = HAMGING_STATE::ATTACKING;
			}
		}
	}
	if (HAMGING_ATTACKING)
	{
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
	//����Ÿ ���� ���� transparent: ������
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