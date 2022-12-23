#include "pch.h"
#include "HamgingEffect.h"
#include "ResMgr.h"
#include "Image.h"
#include "Vec2.h"
#include "TimeMgr.h"
#include "Animator.h"
#include "Animation.h"

HamgingEffect::HamgingEffect(Vec2 startPos)
{
	SetPos(startPos);
	SetName(L"HAMGING_EFFECT");
	SetScale(Vec2(100, 100));
	m_pImage = ResMgr::GetInst()->ImgLoad(L"hamging_effect", L"Image\\Hamging_Attack_Effect.bmp");
	CreateAnimator();
	GetAnimator()->CreateAnimation(
		L"HamgingEffectAni",
		m_pImage,
		Vec2(0.f, 0.f),
		Vec2(330.f, 370.f),
		Vec2(330.f, 0.f),
		8,
		0.03f);
	GetAnimator()->Play(L"HamgingEffectAni", false);
	pAnim = GetAnimator()->FindAnimation(L"HamgingEffectAni");
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

