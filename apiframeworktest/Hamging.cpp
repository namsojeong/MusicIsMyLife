#include "pch.h"
#include "Hamging.h"
#include "GameMgr.h"
#include "TimeMgr.h"
#include "ResMgr.h"
#include "Animator.h"
#include "Image.h"
#include "Core.h"
#include "Player.h"
#include "CollisionMgr.h"
#include "Collider.h"
#include "Text.h"
#include "Scene.h"

Hamging::Hamging(int setHP, Vec2 scale) :state(HAMGING_STATE::WAIT)
{
	SetScale(scale);
	Vec2 vResolution(Vec2(Core::GetInst()->GetResolution()));

	hp = new HP(100, Vec2(vResolution.x / 2 - 150, 160.0f));
	stress = new Stress(100, Vec2(vResolution.x / 2 - 150, 180.f));

	// image 업로드
	pImg = ResMgr::GetInst()->ImgLoad(L"HamgingAni", L"Image\\Hamging_Attack.bmp");

	// animator 생성 및 animation 사용
	CreateAnimator();
	GetAnimator()->CreateAnimation(
		L"HamgingAni",
		pImg,
		Vec2(0.f, 0.f),
		Vec2(330.f, 370.f),
		Vec2(330.f, 0.f),
		4,
		0.2f);
	Animation* pAnim = GetAnimator()->FindAnimation(L"HamgingAni");
	GetAnimator()->Play(L"HamgingAni", true);
	CreateCollider();
	GetCollider()->SetScale(GetScale());
}

Hamging::Hamging():state(HAMGING_STATE::WAIT)
{
	Vec2 vResolution(Vec2(Core::GetInst()->GetResolution()));

	hp = new HP(100, Vec2(vResolution.x / 2, vResolution.y / 2 + 200));
	stress = new Stress(100, Vec2(vResolution.x / 2 - 150, 100.0f));
	GameMgr::GetInst()->GetHamgingHPText()->SetText(to_wstring(hp->GetHP()));

	// image 업로드
	pImg = ResMgr::GetInst()->ImgLoad(L"HamgingAni", L"Image\\Hamging_Attack.bmp");

	// animator 생성 및 animation 사용
	CreateAnimator();
	GetAnimator()->CreateAnimation(
		L"HamgingAni", 
		pImg, 
		Vec2(0.f, 0.f), 
		Vec2(330.f, 370.f), 
		Vec2(330.f, 0.f),
		4, 
		0.2f);
	Animation* pAnim = GetAnimator()->FindAnimation(L"HamgingAni");
	GetAnimator()->Play(L"HamgingAni", true);
}

const void Hamging::Attack(int damage)
{
	hp->AddHP(-damage);
	if (hp->IsDead())
	{
		Die();
	}
	GameMgr::GetInst()->GetHamgingHPText()->SetText(to_wstring(hp->GetHP()));
	//hp->UpdateUiHp(GameMgr::GetInst()->GetHamgingText());
}

const void Hamging::Heal(int addHP)
{
	hp->AddHP(addHP);
	if (hp->GetHP() > hp->GetMaxHP())
	{
		hp->SetHP(hp->GetMaxHP());
	}
	GameMgr::GetInst()->GetHamgingHPText()->SetText(to_wstring(hp->GetHP()));
	//hp->UpdateUiHp(GameMgr::GetInst()->GetHamgingText());
}

const void Hamging::AttackStress(int damage)
{
	stress->AddStress(damage);
	if (stress->GetStress() >= stress->GetMaxStress())
	{
		stress->SetStress(stress->GetMaxStress());
	}
}

const void Hamging::HealStress(int addHP)
{
	stress->AddStress(-addHP);
	if (stress->GetStress() <= 0)
	{
		stress->SetStress(0);
	}
}

void Hamging::Update()
{
	if (state == HAMGING_STATE::WAIT)
	{
		GameMgr::GetInst()->SetIsHamgingAttack(false);
		if (state != HAMGING_STATE::WAIT)
		{
			state = HAMGING_STATE::WAIT;
			GameMgr::GetInst()->UpdateTurnText(state);
		}
		if (state == HAMGING_STATE::WAIT)
		{
			bool isOverBefore = TimeMgr::GetInst()->IsOverBeforeHamgingAttackDelay(4);
			bool isPlayerAttack = GameMgr::GetInst()->GetIsPlayerAttack();
				GameMgr::GetInst()->UpdateTurnText(state);
			// 시간 함수
			if (isPlayerAttack && isOverBefore)
			{
				state = HAMGING_STATE::ATTACKING;
				GameMgr::GetInst()->SetHamgingState(state);
			}
		}
	}
	else if (HAMGING_ATTACKING)
	{
		bool playerAttack = GameMgr::GetInst()->GetIsPlayerAttack();
		bool hamgingAttack = GameMgr::GetInst()->GetIsHamgingAttack();
		if (!hamgingAttack && playerAttack)
		{
			GameMgr::GetInst()->AttackPlayer(10 + m_attackPower * m_stress / 100);
			GameMgr::GetInst()->SetIsHamgingAttack(true);
		}
		bool isOverAfter = TimeMgr::GetInst()->IsOverAfterHamgingAttackDelay(4);
		if (isOverAfter)
		{
			state = HAMGING_STATE::WAIT;
			GameMgr::GetInst()->SetHamgingState(state);
			GameMgr::GetInst()->SetIsPlayerAttack(false);
		}
	}
	GetAnimator()->Update();
}

void Hamging::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	int Width = (int)pImg->GetWidth();
	int Height = (int)pImg->GetHeight();
	//마젠타 색상 뺄때 transparent: 투명한
	/*TransparentBlt(_dc
		, (int)(vPos.x - (float)(Width / 2))  
		, (int)(vPos.y - (float)(Height / 2))
		,Width, Height
	    , pImg->GetDC()
	    ,0,0, Width, Height
	    , RGB(255,0,255));*/

	hp->Render(_dc);
	stress->Render(_dc);
	stress->Update();

	Component_Render(_dc);
}

void Hamging::Die()
{
	GameMgr::GetInst()->NextRound();
}


Hamging::~Hamging()
{
}

void Hamging::EnterCollision(Collider* _pOther)
{
	Object* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"BULLET_CARD")
	{

	}
}