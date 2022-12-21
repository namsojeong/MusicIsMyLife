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
	bool isChooseCard;
	HAMGING_STATE m_hamgingState;
	Hamging* m_hamging;
	Player* m_player;//�ְ� ��ȹ�� ������
	Text* m_turnText;
	Text* m_attackText;
	Text* m_playerText;
	Text* m_hamgingText;//�������ϰ� ��ü�ؾ���
public:
	bool isHamgingAttack; // �ܱ��̰� ���� �ߴٸ�
	bool isPlayerAttack; // �÷��̾ ���� �ߴٸ�
	bool isAttackEffect; // �÷��̾ ���� �ߴٸ�
public://����� �����̴� �����ϴ°�?
	GameMgr();
	~GameMgr();
public:
	const void SetObject(Player * p, Hamging * h);
public:
	const HAMGING_STATE GetHamgingState() { return m_hamgingState; }
	const void SetHamgingState(HAMGING_STATE value);
public:
	const void SetPlayerText(Text* playerTxt) { m_playerText = playerTxt; }
	Text* GetPlayerText() { return m_playerText; }
	const void SetHamgingText(Text* hamgingTxt) { m_hamgingText = hamgingTxt; }
	Text* GetHamgingText() { return m_hamgingText; }

	const void UpdateTurnText(HAMGING_STATE state);
	const void SetTurnText(Text* turnTxt) { m_turnText = turnTxt; }
	const void SetAttackText(Text* txt) { m_attackText = txt; }
	Text* GetTurnText() { return m_turnText; }
	Text* GetAttackText() { return m_attackText; }
public:
	const void AttackPlayer(int damage);
	const void AttackHamging(int damage, int stress);
	
	const void AttackTextEffect(CARD_TYPE type);
	const bool AttackEffectDuration(long delayTime);
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