#include "pch.h"
#include "NextroundButton.h"
#include "ResMgr.h"
#include "Image.h"

void NextroundButton::ButtonEvent()
{
	ChangeScene(SCENE_TYPE::GAME);
}

void NextroundButton::SetImage(BUTTON_STATE state)
{
	wstring keyWord;
	wstring path;
	switch (state)
	{
	case BUTTON_STATE::NONE:
	{
		keyWord = L"Next_Button";
		path = nextGameBasicPath;
	}
	break;
	case BUTTON_STATE::OVER:
	{
		keyWord = L"Next_Over_Button";
		path = nextGameOverPath;
	}
	break;
	}

	m_pImage = ResMgr::GetInst()->ImgLoad(keyWord, path);
}

NextroundButton::NextroundButton(Vec2 pos)
{
	SetImage(BUTTON_STATE::NONE);

	Vec2 scale = Vec2((int)m_pImage->GetWidth(), (int)m_pImage->GetHeight());
	SetPos(pos);
	SetScale(scale);
	SetRect(pos, scale);
}

NextroundButton::~NextroundButton()
{
}
