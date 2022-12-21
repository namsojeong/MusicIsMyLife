#pragma once
#include "HP.h"
#include "UI.h"

class Stress:
	public UI
{
private:
	RECT rect;
	float offsetX = 100.f;
	float offsetY = 300.f;
	float curStress = 0;
	float maxStress;
public:
	const float GetStress() { return curStress; }
	const float GetMaxStress() { return maxStress; }
	void SetStress(float stress) { curStress = stress; }
	void AddStress(const int stress);
	void SetBackgroundColor(const HDC hdc, const BRUSH_TYPE brush);
	void SetPenColor(const HDC hdc, const PEN_TYPE pen);
public:
	void Update() override;
	void Render(HDC hdc) override;
public:
	CLONE(Stress);
public:
	Stress(Vec2 pos);
	Stress(const int maxStress, Vec2 pos);
	~Stress();
};