#include "pch.h"
#include "HamgingEffect.h"
#include "ResMgr.h"
#include "Animator.h"
#include "Animation.h"
HamgingEffect::HamgingEffect(Vec2 startPos)
{
	SetPos(startPos);
	m_pImage = ResMgr::GetInst()->ImgLoad(L"hamging_effect", L"Image\\Hamging_Attack_Effect.bmp");
	CreateAnimator();
	GetAnimator()->CreateAnimation(
		L"hamging_effect",
		m_pImage,
		Vec2(0.f, 0.f),
		Vec2(330.f, 370.f),
		Vec2(330.f, 0.f),
		8,
		0.03f);
	pAnim = GetAnimator()->FindAnimation(L"hamging_effect");
	GetAnimator()->Play(L"hamging_effect", false);
}

HamgingEffect::~HamgingEffect()
{
}

void HamgingEffect::Update()
{
	if (pAnim->IsFinish())
		DeleteObject(this);
	GetAnimator()->Update();
}

void HamgingEffect::Render(HDC _dc)
{
	Component_Render(_dc);
}
