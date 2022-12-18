#pragma once

class Player;
class Hamging;
class Text;
class GameMgr
{
public:
	SINGLE(GameMgr);
private:
	HAMGING_STATE m_hamgingState;
	Hamging* m_hamging;
	Player* m_player;
	Text* m_playerText;
	Text* m_hamgingText;
public:
	bool isHamgingAttack; // �ܱ��̰� ���� �ߴٸ�
	bool isPlayerAttack; // �÷��̾ ���� �ߴٸ�
public:
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
	const bool HamgingAttackTimer();//�ܱ��̰� �����ϰ� �� ����
	const bool PlayerAttackTimer();//�÷��̾ �����ϰ� �� ����
public:
	void Init();
	void Update();
};