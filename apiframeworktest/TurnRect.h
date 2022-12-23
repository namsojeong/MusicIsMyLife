#pragma once
#include"UI.h"

class Image;
class TurnRect :
	public UI
{
private:
	CLONE(TurnRect);
private:
	Image* m_pImage;
private:
	wstring hamgingKey = L"Hamging_turn";
	wstring playerKey = L"Player_turn";
	wstring hamgingPath = L"Image\\Turn_Hamging.bmp";
	wstring playerPath = L"Image\\Turn_Player.bmp";
private:
	const void SetRectTurn();
private:
	void Update() override;
	void Render(HDC hdc) override;
public:
	TurnRect();
	~TurnRect();
};

