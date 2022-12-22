#include "pch.h"
#include "BulletEffect.h"
#include "ResMgr.h"
#include "Image.h"
#include "Vec2.h"
#include "TimeMgr.h"
#include "Animator.h"
#include "Animation.h"

BulletEffect::BulletEffect(Vec2 startPos)
{
	SetPos(startPos);
	SetName(L"BULLET_EFFECT");
	SetScale(Vec2(100, 100));
	m_pImage = ResMgr::GetInst()->ImgLoad(L"heart_effect", L"Image\\heart_effect.bmp");
	CreateAnimator();
	GetAnimator()->CreateAnimation(
		L"BulletEffectAni",
		m_pImage,
		Vec2(0.f, 0.f),
		Vec2(100.f, 100.f),
		Vec2(100.f, 0.f),
		11,
		0.03f);
	GetAnimator()->Play(L"BulletEffectAni", false);
	pAnim = GetAnimator()->FindAnimation(L"BulletEffectAni");
}

BulletEffect::~BulletEffect()
{
}

void BulletEffect::Update()
{
	if (pAnim->IsFinish())
		DeleteObject(this);
	GetAnimator()->Update();
}

void BulletEffect::Render(HDC _dc)
{
	Component_Render(_dc);
}

