#include "pch.h"
#include "Button.h"
#include "EventMgr.h"
#include "ResMgr.h"
#include "KeyMgr.h"
#include "Image.h"
#include "Core.h"

void Button::Click()
{
	ChangeScene(SCENE_TYPE::GAME);
}

bool Button::IsOnButton()
{
	POINT mousePos;
	GetCursorPos(&mousePos);
	ScreenToClient(Core::GetInst()->GetWndHandle(), &mousePos);
	return PtInRect(&m_rect, mousePos);
}

Button::Button(Vec2 pos, Vec2 scale)
{
	SetName(L"Button");

	m_rect.left = pos.x - scale.x / 2;
	m_rect.right = pos.x + scale.x / 2;
	m_rect.top = pos.y - scale.y / 2;
	m_rect.bottom = pos.y + scale.y / 2;

	SetPos(pos);
	SetScale(scale);
}

void Button::Update()
{
	if (KEY_TAP(KEY::CLICK) && IsOnButton())
	{
		Click();
	}
}

void Button::Render(HDC hdc)
{
	Rectangle(hdc, m_rect.left, m_rect.top, m_rect.right, m_rect.bottom);
	
	Component_Render(hdc);
}

Button::Button()
{

}

Button::~Button()
{
}
