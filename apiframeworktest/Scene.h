#pragma once
class Object;
class UI;
class Image;
class Scene
{
private:
	//	Object a;
		// 오브젝트를 저장 및 관리할 벡터를 그룹 개수만큼 선언
	vector<Object*> m_vecObj[(UINT)GROUP_TYPE::END];
	vector<Object*> m_vecUI[(UINT)UI_TYPE::END];
	wstring         m_strName; // Scene이름
	Image* m_background;
private:
	int iCard = 3;
public:
	const void SetCardAmount(const int& _amount)
	{
		iCard = _amount;
	}
	const int& GetCardAmount() { return iCard; }
public:
	void SetBackground(wstring _strName, wstring _path);
	void SetName(const wstring& _strName) { m_strName = _strName; }
	const wstring& GetName() { return m_strName; }

	virtual void Update();
	virtual void FinalUpdate();
	virtual void Render(HDC _dc);
	virtual void Enter() abstract; // 해당 Scene에 진입시 호출
	virtual void Exit() abstract;  // 해당 Scene을 나올때 호출
public:
	void AddObject(Object* _pObj, GROUP_TYPE _eType)
	{
		m_vecObj[(UINT)_eType].push_back(_pObj);
	}
	void AddUI(Object* _pUI, UI_TYPE _eType)
	{
		m_vecUI[(UINT)_eType].push_back(_pUI);
	}
	const vector<Object*>& GetGroupObject(GROUP_TYPE _eType)
	{
		return m_vecObj[(UINT)_eType];
	}
	const vector<Object*>& GetGroupUI(UI_TYPE _eType)
	{
		return m_vecUI[(UINT)_eType];
	}
	void DeleteGroup(GROUP_TYPE _eTarget);
	void DeleteUIGroup(UI_TYPE _eTarget);
	void DeleteAll();
public:
	Scene();
	virtual ~Scene();
};

