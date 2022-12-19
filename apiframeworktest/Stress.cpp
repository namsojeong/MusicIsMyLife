#include "pch.h"
#include "Stress.h"
#include "SelectGDI.h"
#include "Core.h"


void Stress::AddStress(const int stress)
{
	curStress += stress;
}

void Stress::SetBackgroundColor(const HDC hdc, const BRUSH_TYPE brush)
{
	SelectGDI b(hdc, brush);
}

void Stress::SetPenColor(const HDC hdc, const PEN_TYPE pen)
{
	SelectGDI p(hdc, pen);
}

void Stress::Update()
{
}

void Stress::Render(HDC hdc)
{
	rect.left = GetPos().x;
	rect.bottom = GetPos().y;
	rect.right = rect.left - offsetX;
	rect.top = rect.bottom - offsetY;

	SelectGDI pb(hdc, PEN_TYPE::BLACK);
	Core::GetInst()->SetBrushColor(&hdc, RGB(255, 255, 255));
	SelectGDI bb(hdc, BRUSH_TYPE::COLOR);
	int top2 = rect.top;
	Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);

	SelectGDI pg(hdc, PEN_TYPE::RED);
	Core::GetInst()->SetBrushColor(&hdc, RGB(255, 0, 0));
	SelectGDI bg(hdc, BRUSH_TYPE::COLOR);
	int top = rect.bottom - curStress * (offsetY / maxStress);
	Rectangle(hdc, rect.left, top, rect.right, rect.bottom);

	Component_Render(hdc);
}

Stress::Stress(Vec2 pos)
	:curStress(0)
	, maxStress(100)
{
	SetPos(pos);
}

Stress::Stress(const int maxStress, Vec2 pos)
	:curStress(0)
	, maxStress(maxStress)
{
	SetPos(pos);
}

Stress::~Stress()
{
}
