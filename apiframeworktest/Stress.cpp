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

void Stress::UpdateUiStress(HDC hdc, Vec2 pos)
{
	rect.left = pos.x;
	rect.bottom = pos.y;
	rect.right = rect.left - offsetX;
	rect.top = rect.bottom - offsetY;

	SelectGDI pb(hdc, PEN_TYPE::BLACK);
	SelectGDI bb(hdc, BRUSH_TYPE::HOLLOW);
	Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);

	SelectGDI pg(hdc, PEN_TYPE::GREEN);
	Core::GetInst()->SetBrushColor(&hdc, RGB(255, 0, 0));
	SelectGDI bg(hdc, BRUSH_TYPE::COLOR);
	Rectangle(hdc, rect.left, rect.bottom-curStress, rect.right, rect.bottom);
}

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
