#include "pch.h"
#include "QuitButton.h"

void QuitButton::ButtonEvent()
{
	exit(0);
}

QuitButton::QuitButton(Vec2 pos, Vec2 scale)
{
	SetPos(pos);
	SetScale(scale);
	SetRect(pos, scale);
}

QuitButton::QuitButton()
{
}

QuitButton::~QuitButton()
{
}
