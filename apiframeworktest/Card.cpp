#include "pch.h"
#include "Card.h"
#include "ResMgr.h"
#include "Animator.h"
#include "Image.h"
#include "SceneMgr.h"
#include "KeyMgr.h"
#include "EventMgr.h"
#include "TimeMgr.h"
Card::Card() :
	_attackPower(0),
	_stressPower(0),
	m_pImage(nullptr)
{
	// image 업로드
	m_pImage = ResMgr::GetInst()->ImgLoad(L"card", L"Image\\Cardb.bmp");

	// animator 생성 및 animation 사용
	/*CreateAnimator();
	GetAnimator()->CreateAnimation(L"Jiwoofront", m_pImage, Vec2(0.f, 150.f), Vec2(50.f, 50.f), Vec2(50.f, 0.f), 5, 0.2f);
	GetAnimator()->Play(L"Jiwoofront", true);*/

}

Card::~Card()
{
}

void Card::Update()
{
	Vec2 vPos = GetPos();
	if(GetAnimator() != nullptr)
		GetAnimator()->Update();

	if (bool isHamgingAttack = SceneMgr::GetInst()->IsHamgingAttack())
	{
		POINT* m_point = EventMgr::GetInst()->GetPoint();
		GetCursorPos(m_point);
		if (EventMgr::GetInst()->isOn(GetPos(), GetScale()))
		{
			Vec2 pos = GetPos();
			SetPos(pos + Vec2(0, 100));
		}
	}
	else if (KEY_AWAY(KEY::CLICK))
	{
		POINT* m_point = EventMgr::GetInst()->GetPoint(); 
		if (EventMgr::GetInst()->isOn(GetPos(), GetScale()))
		{
			Vec2 pos = GetPos();
			SetPos(pos + Vec2(0, -100));
			bool isPlayerAttack = SceneMgr::GetInst()->IsAttack();
		}
		if (isHamgingAttack && !isPlayerAttack)// 내가 공격을 안했고, 햄깅이가 공격을 했다면 진행
		{
			if (KEY_TAP(KEY::CLICK))
			{
				POINT* m_point = EventMgr::GetInst()->GetPoint();
				GetCursorPos(m_point);
				if (EventMgr::GetInst()->IsOn(GetPos(), GetScale()))
				{
					Vec2 pos = GetPos();
					SetPos(pos + Vec2(0, -50));
				}
			}
			else if (KEY_AWAY(KEY::CLICK))
			{
				POINT* m_point = EventMgr::GetInst()->GetPoint();
				if (EventMgr::GetInst()->IsOn(GetPos(), GetScale()))
				{
					Vec2 pos = GetPos();
					SetPos(pos + Vec2(0, 50));
					SceneMgr::GetInst()->SetIsAttack(true);
				}
			}
		}
	}
	
}



void Card::Render(HDC _dc)
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
