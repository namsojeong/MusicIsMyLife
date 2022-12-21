#pragma once

struct CardStats
{
	int _attackPower;
	int _stressPower;
};
class CardMgr
{
public:
	map<UINT, wstring> cardStr = {
	  {(UINT)CARD_TYPE::A,  L"이번 과제는 이거랑 이거랑,,,\n주저리주저리어쩌구저쩌구"}
	, {(UINT)CARD_TYPE::B, L"엥 왜 벌써 기말?\n 그럴리가 ~"}
	, {(UINT)CARD_TYPE::C, L"ㅎ..ㅎ호호혼밥쯤이야...\n밥 머긍ㄹ 친구도 없는 인생..."}
	, {(UINT)CARD_TYPE::D, L"과제 따위 날 막을 수 없으셈!" }
	,{(UINT)CARD_TYPE::E, L"아니 친구들 말이라도 해주지..궁시렁궁시렁\n아맞다 나 친구없지..." } };
public:
	SINGLE(CardMgr);
private:
	CardStats m_vCard[(UINT)CARD_TYPE::END];
	map<UINT, int> hpStats = { {(UINT)CARD_TYPE::A,  10}, {(UINT)CARD_TYPE::B, 20}, {(UINT)CARD_TYPE::C, 30}, {(UINT)CARD_TYPE::D, 40},{(UINT)CARD_TYPE::E, 50} };
	map<UINT, int> stressStats = { {(UINT)CARD_TYPE::A,  10}, {(UINT)CARD_TYPE::B, 20}, {(UINT)CARD_TYPE::C, 30}, {(UINT)CARD_TYPE::D, 40},{(UINT)CARD_TYPE::E, 50} };
public:
	const CardStats GetCardStat(int idx) { return m_vCard[idx]; }
public:
	void Init();
};

