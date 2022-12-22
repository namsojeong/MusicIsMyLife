#include "pch.h"
#include "Bullet.h"
#include "TimeMgr.h"
#include "Image.h"
#include "PathMgr.h"
#include "ResMgr.h"
#include "Collider.h"
Bullet::Bullet(Vec2 endPos, Vec2 startPos, Vec2 scale)
{
	vEndPos = endPos;
	SetPos(startPos);
	vStartPos = GetPos();
	m_pImage = ResMgr::GetInst()->ImgLoad(L"heart", L"Image\\heart.bmp");
	CreateCollider();
	SetScale(scale);
	GetCollider()->SetScale(scale);
	dir = (endPos - startPos).Normalize();
}
Bullet::~Bullet()
{
	
}



void Bullet::Update()
{
	Vec2 curPos = GetPos();
	
	Vec2 pos = curPos + dir;
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

void Bullet::EnterCollision(Collider* _pOther)
{
	Object* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"HAMGING")
	{

		DeleteObject(this);
	}
}