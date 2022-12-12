#include "pch.h"
#include "TimeMgr.h"
#include "Core.h"
#include "EventMgr.h"
#include "SceneMgr.h"
TimeMgr::TimeMgr()
	:m_llCurCount{}
	, m_llFrequency{}
	, m_llPrevCount{}
	, m_dDT(0.)
	, m_iCallCount(0)
	, m_delayCallCount(0)
	, m_delayAcc(0)
{
}

TimeMgr::~TimeMgr()
{
}

void TimeMgr::Init() 
{
	// ���� ī��Ʈ
	QueryPerformanceCounter(&m_llPrevCount);

	// �ʴ� ī��Ʈ Ƚ��(1000��)
	QueryPerformanceFrequency(&m_llFrequency);
}

void TimeMgr::Update()
{
	QueryPerformanceCounter(&m_llCurCount);
	// ���� �������� ī���ð�, ���� ������ ī���� ���� ���̸� ���Ѵ�.
	//���� �����Ӱ� ���� ī��Ʈ ���� �̿��ؼ� ��ŸŸ�� ���ϱ�
	m_dDT = (double)(m_llCurCount.QuadPart - m_llPrevCount.QuadPart) / (double)m_llFrequency.QuadPart;

	// ���� ī��Ʈ ���� ���簪���� ����(�������� ����� ���ؼ�)
	m_llPrevCount = m_llCurCount; //ī��Ʈ �� ����

	//= 1. / m_dDT;
#ifdef _DEBUG
	if (m_dDT > (1. / 60.))
		m_dDT = (1. / 60.);
#endif
}
void TimeMgr::Render()
{
	++m_iCallCount; //ȣ��Ƚ�� ����

	m_dAcc += m_dDT; //DT(��ŸŸ��) ����
	if (m_dAcc >= 1.) //1�ʰ� �������� fps ���
	{
		m_iFPS = m_iCallCount;
		m_dAcc = 0.;
		m_iCallCount = 0;
		static wchar_t szBuffer[255] = {};
		/*swprintf_s(szBuffer, L"FPS : %d,  DT: %lf", m_iFPS, m_dDT);*/
		swprintf_s(szBuffer, L"MOUSE POS : %d", EventMgr::GetInst()->GetPoint()->x);
		SetWindowText(Core::GetInst()->GetWndHandle(), szBuffer);
	}
}

bool TimeMgr::IsOverDelay(double delay)
{
	m_delayAcc += m_dDT;
	if (m_delayAcc >= delay)
	{
		SceneMgr::GetInst()->SetIsAttack(false);
		m_delayAcc = 0.;
		return true;
	}
	return false;
}
