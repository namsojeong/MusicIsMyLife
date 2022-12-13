#pragma once
#include "Button.h"
class StartButton :
    public Button
{
private:
    void ButtonEvent() override;
public:
    StartButton(Vec2 pos, Vec2 scale);
private:
    StartButton();
    ~StartButton();
};

