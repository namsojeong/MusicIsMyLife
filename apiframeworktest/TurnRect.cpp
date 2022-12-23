#include "pch.h"
#include "TurnRect.h"
#include "ResMgr.h"
#include "Image.h"
#include "GameMgr.h"

const void TurnRect::SetRectTurn()
{
	if (GameMgr::GetInst()->GetHamgingState() == HAMGING_STATE::WAIT)
	{
		m_pImage = ResMgr::GetInst()->ImgLoad(playerKey, playerPath);
	}
	else
	{
		m_pImage = ResMgr::GetInst()->ImgLoad(hamgingKey, hamgingPath);

	}
}

void TurnRect::Update()
{
}

void TurnRect::Render(HDC hdc)
{
	SetRectTurn();
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
}

TurnRect::TurnRect()
{
	m_pImage = ResMgr::GetInst()->ImgLoad(playerKey, playerPath);
	SetPos(Vec2((int)m_pImage->GetWidth() / 2 + 10, (int)m_pImage->GetHeight()));
}

TurnRect::~TurnRect()
{
}
