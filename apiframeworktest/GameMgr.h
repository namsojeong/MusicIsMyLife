#pragma once

class Player;
class Hamging;
class Text;
class Card;
class GameMgr
{
public:
	SINGLE(GameMgr);
private:
	HAMGING_STATE m_hamgingState;
	Hamging* m_hamging;
	Player* m_player;//최강 기획자 강대희
	Text* m_playerText;
	Text* m_hamgingText;//프젝안하고 롤체해야지
public:
	bool isHamgingAttack; // 햄깅이가 공격 했다면
	bool isPlayerAttack; // 플레이어가 공격 했다면
public://대희는 빡빡이다 인정하는가?
	GameMgr();
	~GameMgr();
public:
	const void SetObject(Player * p, Hamging * h);
public:
	const HAMGING_STATE GetHamgingState() { return m_hamgingState; }
	const void SetHamgingState(HAMGING_STATE value) { m_hamgingState = value; }
public:
	const void SetPlayerText(Text* playerTxt) { m_playerText = playerTxt; }
	const Text* GetPlayerText() { return m_playerText; }
	const void SetHamgingText(Text* hamgingTxt) { m_hamgingText = hamgingTxt; }
	const Text* GetHamgingText() { return m_hamgingText; }
public:
	const void AttackPlayer(int _attackPow);
	const void AttackHamging(int _attackPow);
public:
	const void SetIsPlayerAttack(bool value) { isPlayerAttack = value; }
	const bool GetIsPlayerAttack() { return isPlayerAttack; }
public:
	const void SetIsHamgingAttack(bool value) { isHamgingAttack = value; }
	const bool GetIsHamgingAttack() { return isHamgingAttack; }
public:
	const bool HamgingAttackTimer();//햄깅이가 공격하고 초 세기
	const bool PlayerAttackTimer();//플레이어가 공격하고 초 세기
public:
	void Init();
	void Update();
};