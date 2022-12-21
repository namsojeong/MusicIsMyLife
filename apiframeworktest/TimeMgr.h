#pragma once
class TimeMgr
{
public:
	SINGLE(TimeMgr);
private:
	LARGE_INTEGER m_llCurCount;
	LARGE_INTEGER m_llPrevCount;
	LARGE_INTEGER m_llFrequency;
	
	double		  m_dDT; // 프레임 사이의 시간 값
	double		  m_dAcc; // 1초 체크를 위한 누적 시간
	UINT	      m_iCallCount; // 함수 호출 횟수 체크
	UINT		  m_iFPS;		// 초당 호출 횟수


	double		  m_delayAcc = 0; // 딜레이 초 체크를 위한 누적 시간

	double		  m_delayHamgingAcc = 0;
	double		  m_delayPlayerAcc = 0;
	double		  m_delayAttackTextAcc = 0;

	double		  m_beforeAttackHamgingAcc = 0;
	double		  m_afterAttackHamgingAcc = 0;
	// FPS 
	// 1 프레임당 시간(delta time)
private:
	TimeMgr();
	~TimeMgr();
public:
	void Init();
	void Update();
	void Render();
public:
	double GetDT() { return m_dDT; }
	float  GetfDT() { return (float)m_dDT; }
public:
	bool IsOverDelay(double delay);
	bool IsOverPlayerAttackDelay(double delay);
	bool IsOverHamgingAttackDelay(double delay);
	bool IsOverAttackTextDelay(double delay);
	bool IsOverBeforeHamgingAttackDelay(double delay);
	bool IsOverAfterHamgingAttackDelay(double delay);
};

