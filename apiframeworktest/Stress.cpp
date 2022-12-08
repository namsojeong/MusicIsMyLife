#include "pch.h"
#include "Stress.h"


Stress::Stress()
	:curStress(0)
	, maxStress(100)
{
}

Stress::Stress(const int maxStress)
	:curStress(0)
	, maxStress(maxStress)
{
}

Stress::~Stress()
{
}
