#pragma once
#include "Object.h"
#include "HP.h"

class Image;
class Player :
    public Object
{
private:
    Image* m_pImage;
private:
    void CreateBullet();
public:
    HP* hp;
    int GetPlayerHP(){ return hp->GetHP(); }
public:
    void Update()       override;
    void Render(HDC _dc) override;
private:
    CLONE(Player);
public:
    Player();
    ~Player();
};

