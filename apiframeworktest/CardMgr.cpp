#include "pch.h"
#include "CardMgr.h"
#include "Card.h"

void CardMgr::Init()
{
	for (UINT i = 0; i < (UINT)CARD_TYPE::END; i++)
	{
		m_vCard[i] = { 1,1 };
	}
}