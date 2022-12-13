#pragma once
#include "Button.h"
class QuitButton :
    public Button
{
private:
    void ButtonEvent() override;
public:
    QuitButton(Vec2 pos, Vec2 scale);
private:
    QuitButton();
    ~QuitButton();
};

