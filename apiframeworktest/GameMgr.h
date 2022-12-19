#pragma once

class Player;
class Hamging;
class GameMgr
{
public:
	SINGLE(GameMgr);
private:
	static int round;
	bool isChooseCard;
	HAMGING_STATE m_hamgingState;
	Hamging* m_hamging;
	Player* m_player;
public:
	GameMgr();
	~GameMgr();
public:
	const int GetRound() { return round; }
	const void SetObject(Player * p, Hamging * h);
	const int GetIsChooseCard() { return isChooseCard; }
	const void SetIsChooseCard(bool value) { isChooseCard = value; }
	const HAMGING_STATE GetHamgingState() { return m_hamgingState; }
	const void SetHamgingState(HAMGING_STATE value) { m_hamgingState = value; }
	const void AttackPlayer(int damage);
	const void AttackHamging(int damage);
public:
	void Init();
	void Update();
};