#include "pch.h"
#include "Card.h"
#include "ResMgr.h"
#include "Animator.h"
#include "Image.h"
#include "SceneMgr.h"
#include "KeyMgr.h"

Card::Card() :
	_attackPower(0),
	_stressPower(0),
	m_pImage(nullptr)
{
	// image ���ε�
	m_pImage = ResMgr::GetInst()->ImgLoad(L"PlayerAni", L"Image\\jiwoo.bmp");
	// animator ���� �� animation ���
	CreateAnimator();
	GetAnimator()->CreateAnimation(L"Jiwoofront", m_pImage, Vec2(0.f, 150.f), Vec2(50.f, 50.f), Vec2(50.f, 0.f), 5, 0.2f);
	GetAnimator()->Play(L"Jiwoofront", true);
}

Card::~Card()
{
}

void Card::Update()
{
	Vec2 vPos = GetPos();
	GetAnimator()->Update();
	if (KEY_TAP(KEY::CLICK))
	{

	}

}

void Card::Render(HDC _dc)
{
	Component_Render(_dc);
}
