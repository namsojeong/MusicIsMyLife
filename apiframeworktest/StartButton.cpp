#include "pch.h"
#include "StartButton.h"

void StartButton::ButtonEvent()
{
	ChangeScene(SCENE_TYPE::GAME);
}

StartButton::StartButton(Vec2 pos, Vec2 scale)
{
	SetPos(pos);
	SetScale(scale);
	SetRect(pos, scale);
}

StartButton::StartButton()
{
}

StartButton::~StartButton()
{
}

