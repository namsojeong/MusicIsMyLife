#include "pch.h"
#include "QuitButton.h"
#include "Image.h"
#include "ResMgr.h"

void QuitButton::ButtonEvent()
{
	exit(0);
}

QuitButton::QuitButton(Vec2 pos)
{
	SetImage(BUTTON_STATE::NONE);

	Vec2 scale = Vec2((int)m_pImage->GetWidth(), (int)m_pImage->GetHeight());
	SetPos(pos);
	SetScale(scale);
	SetRect(pos, scale);
}

void QuitButton::SetImage(BUTTON_STATE state)
{
	wstring keyWord;
	wstring path;
	switch (state)
	{
	case BUTTON_STATE::NONE:
	{
		keyWord = L"Quit_Button";
		path = quitBasicPath;
	}
		break;
	case BUTTON_STATE::OVER:
	{
		keyWord = L"Quit_Over_Button";
		path = quitOverPath;
	}
		break;
	}

	m_pImage = ResMgr::GetInst()->ImgLoad(keyWord, path);
}


QuitButton::QuitButton()
{
}

QuitButton::~QuitButton()
{
}
