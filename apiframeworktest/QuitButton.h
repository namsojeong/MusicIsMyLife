#pragma once
#include "Button.h"

class QuitButton :
    public Button
{
private:
    Image* m_qImage;
private:
    wstring quitOverPath = L"Image\\QuitButton_Over.bmp";
    wstring quitBasicPath = L"Image\\QuitButton.bmp";
private:
    void ButtonEvent() override;
    void SetImage(BUTTON_STATE state) final;
public:
    QuitButton(Vec2 pos);
private:
    QuitButton();
    ~QuitButton();
};