#include "pch.h"
#include "Player.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "Bullet.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Image.h"
#include "PathMgr.h"
#include "ResMgr.h"
#include "Collider.h"
#include "Animator.h"
#include "Animation.h"
#include "Core.h"
#include "Text.h"
#include "Hamging.h"
#include "GameMgr.h"

Player::Player()
{
	hp = new HP(100);

	
	// collider 새성
	CreateCollider();
	GetCollider()->SetScale(Vec2(20.f, 30.f));

	// image 업로드
	Image* pImg = ResMgr::GetInst()->ImgLoad(L"PlayerAni", L"Image\\jiwoo.bmp");

	// animator 생성 및 animation 사용
	CreateAnimator();
	GetAnimator()->CreateAnimation(L"Jiwoofront", pImg, Vec2(0.f, 150.f), Vec2(50.f, 50.f), Vec2(50.f, 0.f), 5, 0.2f);
	GetAnimator()->Play(L"Jiwoofront", true);

	// animation offset 위로 올리기. 
	Animation* pAnim = GetAnimator()->FindAnimation(L"Jiwoofront");
	for(size_t i=0;i<pAnim->GetMaxFrame();i++)
		pAnim->GetFrame(i).vOffset = Vec2(10.f, -50.f);
}
Player::~Player()
{
	//if(nullptr !=m_pImage)
	//	delete m_pImage;
}
void Player::Update() 
{
	if (GameMgr::GetInst()->GetIsPlayerAttack())
	{
		if (GameMgr::GetInst()->PlayerAttackTimer())
			GameMgr::GetInst()->SetIsPlayerAttack(true);
	}
}


void Player::Render(HDC _dc)
{
	Component_Render(_dc);
}
