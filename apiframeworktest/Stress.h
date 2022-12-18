#pragma once
#include "HP.h"

class Stress
{
private:
	RECT rect;
	float offsetX = 100.f;
	float offsetY = 300.f;
	float curStress;
	float maxStress;
public:
	const float GetStress() { return curStress; }
	void SetStress(float stress) { curStress = stress; }
	void AddStress(const int stress);
	void SetBackgroundColor(const HDC hdc, const BRUSH_TYPE brush);
	void SetPenColor(const HDC hdc, const PEN_TYPE pen);
public:
	void UpdateUiStress(HDC hdc, Vec2 pos);
public:
	Stress();
	Stress(const int maxStress);
	~Stress();
};