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
	bool IsOn(Vec2 pos, Vec2 scale) 
	{
		POINT* m_point = EventMgr::GetInst()->GetPoint();
		return ((m_point->x <= pos.x + scale.x && m_point->x >= pos.x - scale.x)
			&& (m_point->y <= pos.y + scale.y && m_point->y >= pos.y - scale.y));
			
	}
};

