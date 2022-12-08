#pragma once
class Stress
{
private:
	float curStress;
	float maxStress;
public:
	const float GetStress() { return curStress; }
	void SetStress(float stress) { curStress = stress; }
public:
	Stress();
	Stress(const int maxStress);
	~Stress();
};