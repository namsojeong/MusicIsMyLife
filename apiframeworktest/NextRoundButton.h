#pragma once
#include "Button.h"

class NextroundButton
    : public Button
{
private:
    wstring nextGameOverPath = L"Image\\RestartButton_Over.bmp";
    wstring nextGameBasicPath = L"Image\\RestartButton.bmp";
private:
    void ButtonEvent() override;
    void SetImage(BUTTON_STATE state) final;
public:
    NextroundButton(Vec2 pos);
private:
    NextroundButton();
    ~NextroundButton();
};