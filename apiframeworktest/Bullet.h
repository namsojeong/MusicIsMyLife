#pragma once
class Image;
#include "Object.h"
class Bullet :
    public Object
{
private:
    Vec2 vStartPos;//���� ����
    Vec2 vEndPos;//�� ����
private:
    float speed_x;//x�� �ӵ�
    float speed_y;//y�� �ӵ�
private:
    float gravity;//�߷� ���ӵ�
    float endTime = 2;//�������� ���� �ð�
    float maxHeight;// �ִ� ����
    float height; //�ִ�.y - ����.y
    float endHeight;// ����.y - ����.y
    float time = 0.f;//���� �ð�
    float maxTime = 0.8f;//�ִ���̱��� ���� �ð�
private:
    Image* m_pImage;
public:
    void Init();
    virtual void Update() override;
    virtual void Render(HDC _dc) override;
    virtual void EnterCollision(Collider* _pOther);
    CLONE(Bullet);
public:
    Bullet(Vec2 endPos,Vec2 startPos, Vec2 scale);
    ~Bullet();
};

