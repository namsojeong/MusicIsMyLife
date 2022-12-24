#pragma once
struct tEvent
{
	EVENT_TYPE  eEven;
	DWORD_PTR	lParam;
	DWORD_PTR	wParam;
};
class EventMgr
{
private:
	vector<tEvent> m_vecEvent;
	vector<Object*> m_vecDead;
	POINT ptMouse;
public:
	SINGLE(EventMgr);
private:
	EventMgr();
	~EventMgr();
public:
	void Update();
	void AddEvent(const tEvent& _eve)
	{
		m_vecEvent.push_back(_eve);
	}
private:
	void Excute(const tEvent& _eve);
	void Delete();
public:
	POINT* GetPoint() { return &ptMouse; }
	bool isOn(Vec2 pos, Vec2 scale)
	{
		RECT rt;
		rt.left = pos.x - scale.x / 2;
		rt.right = pos.x + scale.x / 2;
		rt.top = pos.y - scale.y / 2;
		rt.bottom = pos.y + scale.y / 2;

		return PtInRect(&rt, ptMouse);
	}
};

