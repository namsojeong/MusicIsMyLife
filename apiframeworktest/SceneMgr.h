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
	Scene* m_arrScene[(UINT)SCENE_TYPE::END]; // ��� �� ���
	Scene* m_pCurScene;						  // ���� ��
	bool isAttack = false;					//�÷��̾ ������ �߳�
	bool hamgingIsAttack = false;			//�ܱ��̰� ������ �߳�


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

