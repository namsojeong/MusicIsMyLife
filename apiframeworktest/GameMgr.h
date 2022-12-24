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
	int round = 1;
	int hamging_power = 1;
	int hamging_hp = 40;
private:
	bool isChooseCard;
	HAMGING_STATE m_hamgingState;
	Hamging* m_hamging;
	Player* m_player;
	Text* m_attackText;
	Text* m_hamgingHPText;
	Text* m_roundText;
public:
	bool isDeleteAll=false;
	bool isHamgingAttack; // �ܱ��̰� ���� �ߴٸ�
	bool isPlayerAttack; // �÷��̾ ���� �ߴٸ�
	bool isAttackEffect; // �÷��̾ ���� �ߴٸ�
public://����� �����̴� �����ϴ°�?
	GameMgr();
	~GameMgr();
public:
	const void SetObject(Player* p, Hamging* h);
public:
	Vec2 GetHamgingPos();
	Vec2 GetHamgingScale();
public:
	const HAMGING_STATE GetHamgingState() { return m_hamgingState; }
	const void SetHamgingState(HAMGING_STATE value);
public:
	const void SetRoundText(Text* txt) { m_roundText = txt; }
	const void SetHamgingHPText(Text* txt) { m_hamgingHPText = txt; }
	const void SetAttackText(Text* txt) { m_attackText = txt; }
	Text* GetRoundText() { return m_roundText; }
	Text* GetAttackText() { return m_attackText; }
	Text* GetHamgingHPText() { return m_hamgingHPText; }
public:
	const void AttackPlayer(int damage);
	const void AttackHamging(CARD_TYPE type, int damage, int stress);

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
	const void NextRound();//�÷��̾ �����ϰ� �� ����
	const int GetRound() { return round; }//�÷��̾ �����ϰ� �� ����
	const int GetHamgingPower() { return hamging_power; }//�÷��̾ �����ϰ� �� ����
	const int GetHamgingHP() { return hamging_hp; }//�÷��̾ �����ϰ� �� ����

public:
	void Init();
	void Update();
};