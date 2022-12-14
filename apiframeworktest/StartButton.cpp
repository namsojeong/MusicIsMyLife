#include "pch.h"
#include "StartButton.h"
#include "ResMgr.h"
#include "Image.h"

void StartButton::ButtonEvent()
{
	ChangeScene(SCENE_TYPE::GAME);
}

StartButton::StartButton(Vec2 pos)
{
	SetImage(BUTTON_STATE::NONE);

	Vec2 scale = Vec2((int)m_pImage->GetWidth(), (int)m_pImage->GetHeight());
	SetPos(pos);
	SetScale(scale);
	SetRect(pos, scale);
}

void StartButton::SetImage(BUTTON_STATE state)
{
	wstring keyWord;
	wstring path;
	switch (state)
	{
	case BUTTON_STATE::NONE:
	{
		keyWord = L"Start_Button";
		path = startBasicPath;
	}
		break;
	case BUTTON_STATE::OVER:
	{
		keyWord = L"Start_Over_Button";
		path = startOverPath;
	}
		break;
	}

	m_pImage = ResMgr::GetInst()->ImgLoad(keyWord, path);
}

StartButton::StartButton()
{

}

StartButton::~StartButton()
{
}

