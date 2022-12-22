#pragma once
#include "Button.h"

class RestartButton :
    public Button
{
private:
    Image* m_rImage;
private:
    wstring restartOverPath = L"Image\\RestartButton_Over.bmp";
    wstring restartBasicPath = L"Image\\RestartButton.bmp";
private:
    void ButtonEvent() override;
    void SetImage(BUTTON_STATE state) final;
public:
    RestartButton(Vec2 pos);
private:
    RestartButton();
    ~RestartButton();
};