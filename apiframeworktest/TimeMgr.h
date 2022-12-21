#pragma once
class TimeMgr
{
public:
	SINGLE(TimeMgr);
private:
	LARGE_INTEGER m_llCurCount;
	LARGE_INTEGER m_llPrevCount;
	LARGE_INTEGER m_llFrequency;
	
	double		  m_dDT; // ������ ������ �ð� ��
	double		  m_dAcc; // 1�� üũ�� ���� ���� �ð�
	UINT	      m_iCallCount; // �Լ� ȣ�� Ƚ�� üũ
	UINT		  m_iFPS;		// �ʴ� ȣ�� Ƚ��


	double		  m_delayAcc = 0; // ������ �� üũ�� ���� ���� �ð�

	double		  m_delayHamgingAcc = 0;
	double		  m_delayPlayerAcc = 0;
	double		  m_delayAttackTextAcc = 0;

	double		  m_beforeAttackHamgingAcc = 0;
	double		  m_afterAttackHamgingAcc = 0;
	// FPS 
	// 1 �����Ӵ� �ð�(delta time)
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

