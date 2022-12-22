#pragma once
class Scene;
class SceneMgr
{
public:
	SINGLE(SceneMgr);
private:
	SceneMgr();
	~SceneMgr();
private:
	Scene* m_arrScene[(UINT)SCENE_TYPE::END]; // 모든 씬 목록
	Scene* m_pCurScene;						  // 현재 씬
	bool isAttack = false;					//플레이어가 공격을 했나
	bool hamgingIsAttack = false;			//햄깅이가 공격을 했나


public:
	Scene* GetCurScene() { return m_pCurScene; }
private:
	void ChangeScene(SCENE_TYPE _eNext);
	friend class EventMgr;
public:
	void	 Init();
	void	 Update();
	void	 Render(HDC _dc);
public:
	const bool IsAttack() { return isAttack; }
	void SetIsAttack(const bool val) { isAttack = val; }
	const bool IsHamgingAttack();
};

