#include "pch.h"
#include "RestartButton.h"
#include "ResMgr.h"
#include "Image.h"

void RestartButton::ButtonEvent()
{
	ChangeScene(SCENE_TYPE::GAME);
}

RestartButton::RestartButton(Vec2 pos)
{
	SetImage(BUTTON_STATE::NONE);

	Vec2 scale = Vec2((int)m_pImage->GetWidth(), (int)m_pImage->GetHeight());
	SetPos(pos);
	SetScale(scale);
	SetRect(pos, scale);
}

void RestartButton::SetImage(BUTTON_STATE state)
{
	wstring keyWord;
	wstring path;
	switch (state)
	{
	case BUTTON_STATE::NONE:
	{
		keyWord = L"Restart_Button";
		path = restartBasicPath;
	}
	break;
	case BUTTON_STATE::OVER:
	{
		keyWord = L"Restart_Over_Button";
		path = restartOverPath;
	}
	break;
	}

	m_pImage = ResMgr::GetInst()->ImgLoad(keyWord, path);
}

RestartButton::RestartButton()
{

}

RestartButton::~RestartButton()
{
}

