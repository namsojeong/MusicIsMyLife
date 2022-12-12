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
public:
	POINT* GetPoint() { return &ptMouse; }
	bool IsOn(POINT mousePos, Vec2 pos, Vec2 scale) 
	{
		return (mousePos.x <= pos.x + scale.x &&
			mousePos.x >= pos.x - scale.x &&
			mousePos.y <= pos.y + scale.y &&
			mousePos.y >= pos.y - scale.y);
	}
};

