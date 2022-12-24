#include "pch.h"
#include "Bullet.h"
#include "TimeMgr.h"
#include "Image.h"
#include "PathMgr.h"
#include "ResMgr.h"
#include "GameMgr.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Collider.h"
#include "BulletEffect.h"
#include "SoundMgr.h"

Bullet::Bullet(CARD_TYPE card, Vec2 endPos, Vec2 startPos, Vec2 scale, float damage, float stress)
{
	SoundMgr::GetInst()->LoadSound(L"bullet", false, L"Sound\\gun.wav");
	SoundMgr::GetInst()->Play(L"bullet");
	card_type = card;
	vEndPos = endPos;
	SetPos(startPos);
	vStartPos = GetPos();
	m_pImage = ResMgr::GetInst()->ImgLoad(L"heart", L"Image\\heart.bmp");
	CreateCollider();
	SetScale(scale);
	GetCollider()->SetScale(scale);
	dir = (endPos - startPos).Normalize();
	CreateEffect();
	m_damage = damage;
	m_stress = stress;
}
Bullet::~Bullet()
{

}



void Bullet::Update()
{
	Vec2 curPos = GetPos();

	if (TimeMgr::GetInst()->IsOverTime())
	{
		CreateEffect();
	}
	Vec2 pos = curPos + dir * 5.f;
	SetPos(pos);
}

void Bullet::Render(HDC _dc)
{
	if (this != nullptr)
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
}
void Bullet::CreateEffect()
{
	Vec2 vEffectPos = GetPos();
	BulletEffect* pBullet = new BulletEffect(vEffectPos);

	SceneMgr::GetInst()->GetCurScene()->AddObject(pBullet, GROUP_TYPE::BULLET_EFFECT);
}

void Bullet::EnterCollision(Collider* _pOther)
{
	Object* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"HAMGING")
	{
		GameMgr::GetInst()->AttackHamging(card_type, m_damage, m_stress);
		DeleteObject(this);
	}
}