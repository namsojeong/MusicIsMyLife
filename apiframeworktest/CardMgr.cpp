#include "pch.h"
#include "CardMgr.h"
#include "Card.h"
#include "Text.h"

void CardMgr::Init()
{
	for (UINT i = (UINT)CARD_TYPE::A; i < (UINT)CARD_TYPE::END; i++)
	{
		m_vCard[i] = { hpStats[i],  stressStats[i] };
	}
} 