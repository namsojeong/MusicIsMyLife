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
public:
	const CardStats GetCardStat(int idx) { return m_vCard[idx]; }

public:
	void Init();
};

