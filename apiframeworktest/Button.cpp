#include "pch.h"
#include "Button.h"
#include "EventMgr.h"
#include "ResMgr.h"
#include "KeyMgr.h"
#include "Image.h"
#include "Core.h"

void Button::Click()
{
	ButtonEvent();
}

bool Button::IsOnButton()
{
	POINT mousePos;
	GetCursorPos(&mousePos);
	ScreenToClient(Core::GetInst()->GetWndHandle(), &mousePos);
	return PtInRect(&m_rect, mousePos);
}

void Button::SetRect(Vec2 pos, Vec2 scale)
{
	m_rect.left = pos.x - scale.x / 2;
	m_rect.right = pos.x + scale.x / 2;
	m_rect.top = pos.y - scale.y / 2;
	m_rect.bottom = pos.y + scale.y / 2;
}

void Button::SetImage(BUTTON_STATE state)
{
}


void Button::ButtonEvent()
{
}

void Button::Update()
{
	SetImage(BUTTON_STATE::NONE);
	if (IsOnButton())
	{
		SetImage(BUTTON_STATE::OVER);
		if (KEY_TAP(KEY::CLICK))
		{
			Click();
		}
	}
	
}

void Button::Render(HDC hdc)
{
	int Width = (int)m_pImage->GetWidth();
	int Height = (int)m_pImage->GetHeight();
	Vec2 vPos = GetPos();
	TransparentBlt(hdc
		, (int)(vPos.x - (float)(Width / 2))
		, (int)(vPos.y - (float)(Height / 2))
		, Width, Height
		, m_pImage->GetDC()
		, 0, 0, Width, Height
		, RGB(255, 0, 255));
	
	Component_Render(hdc);
}

Button::Button()
{
}

Button::~Button()
{
}
