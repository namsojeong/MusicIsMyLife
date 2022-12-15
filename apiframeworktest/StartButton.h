#pragma once
#include "Button.h"

class StartButton :
    public Button
{
private:
    Image* m_sImage;
private:
    wstring startOverPath = L"Image\\StartButton_Over.bmp";
    wstring startBasicPath = L"Image\\StartButton.bmp";
private:
    void ButtonEvent() override;
    void SetImage(BUTTON_STATE state) final;
public:
    StartButton(Vec2 pos);
private:
    StartButton();
    ~StartButton();
};