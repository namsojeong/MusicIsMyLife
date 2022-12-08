#include "pch.h"
#include "HP.h"

HP::HP()
	:curHP(0)
	, maxHP(100)
{
}

HP::HP(const int maxHP)
	:curHP(0)
	, maxHP(maxHP)
{
}

HP::~HP()
{
}
