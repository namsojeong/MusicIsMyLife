#pragma once

struct CardStats
{
	int _attackPower;
	int _stressPower;
};
class CardMgr
{
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

