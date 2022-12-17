#pragma once

class Player;
class Hamging;
class GameMgr
{
public:
	SINGLE(GameMgr);
private:
	bool isChooseCard;
	HAMGING_STATE m_hamgingState;
	Hamging* m_hamging;
	Player* m_player;
public:
	GameMgr();
	~GameMgr();
public:
	const void SetObject(Player * p, Hamging * h);
	const int GetIsChooseCard() { return isChooseCard; }
	const void SetIsChooseCard(bool value) { isChooseCard = value; }
	const HAMGING_STATE GetHamgingState() { return m_hamgingState; }
	const void SetHamgingState(HAMGING_STATE value) { m_hamgingState = value; }
	const void AttackHamging(int _attackPow);
	const void AttackPlayer(int _attackPow);
public:
	void Init();
	void Update();
};