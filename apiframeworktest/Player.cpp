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
#include "GameMgr.h"
#include "Core.h"
#include "Text.h"
#include "Hamging.h"
#include "GameMgr.h"

Player::Player()
{
	Vec2 vResolution(Vec2(Core::GetInst()->GetResolution()));
	
	hp = new HP(100, Vec2(50.0f, vResolution.y - 50), Vec2(250, 30));

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
void Player::Attack(int damage)
{
	hp->AddHP(-damage);
	if (hp->IsDead())
	{
		Die();
	}
	//hp->UpdateUiHp(GameMgr::GetInst()->GetPlayerText());
}
void Player::Heal(int addHP)
{
	hp->AddHP(addHP);
	if (hp->GetHP() > hp->GetMaxHP())
	{
		hp->SetHP(hp->GetMaxHP());
	}
	//hp->UpdateUiHp(GameMgr::GetInst()->GetPlayerText());
}
void Player::Update()
{
	
}


void Player::Render(HDC _dc)
{
	hp->Render(_dc);
	hp->Update();

	Component_Render(_dc);
}

void Player::Die()
{
	ChangeScene(SCENE_TYPE::OVER);
}
