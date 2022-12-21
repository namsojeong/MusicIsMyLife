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
	maxHeight = endPos.y;
	CreateCollider();
	SetScale(scale);
	GetCollider()->SetScale(scale);
	Init();
}
Bullet::~Bullet()
{
	
}


void Bullet::Init()
{
	endHeight =-(vEndPos.y - vStartPos.y);
	height = -(maxHeight - vStartPos.y);
	gravity = 2 * height / powf(maxTime,2);
	int g = (int)gravity;
	int h = (int)height;
	speed_y = sqrt(2 * g * h);
	float a = gravity;
	float b = -2 * speed_y;
	float c = 2 * endHeight;
	speed_x = -(vStartPos.x - vEndPos.x) / endTime;
}

void Bullet::Update()
{
	Vec2 curPos = GetPos();
	if (curPos == vEndPos)
	{
		delete this;
	}
	float t = TimeMgr::GetInst()->GetfDT();
	time = t;
	float _x = vStartPos.x + speed_x * time* time;
	float _y = vStartPos.y + (speed_y * time) - (0.5f * gravity * time * time);
	float x = _x * powf(time,1.5f);
	float y = -_y * powf(time, 1.5f);
	if (speed_x < 0)
		x *= -1;
	Vec2 pos = curPos + Vec2(x, y);
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