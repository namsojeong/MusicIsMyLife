#pragma once
#include "ResMgr.h"

class Image;

struct CardStats
{
	int _attackPower;
	int _stressPower;
};
class CardMgr
{
public:
	map<UINT, wstring> cardStr = {
	  {(UINT)CARD_TYPE::A,  L"ÀÌ¹ø °úÁ¦´Â ÀÌ°Å¶û ÀÌ°Å¶û,,,\nÁÖÀú¸®ÁÖÀú¸®¾îÂ¼±¸ÀúÂ¼±¸"}
	, {(UINT)CARD_TYPE::B, L"¿¨ ¿Ö ¹ú½á ±â¸»?\n ±×·²¸®°¡ ~"}
	, {(UINT)CARD_TYPE::C, L"¤¾..¤¾È£È£È¥¹äÂëÀÌ¾ß...\n¹ä ¸Ó±à¤© Ä£±¸µµ ¾ø´Â ÀÎ»ý..."}
	, {(UINT)CARD_TYPE::D, L"°úÁ¦ µûÀ§ ³¯ ¸·À» ¼ö ¾øÀ¸¼À!" }
	,{(UINT)CARD_TYPE::E, L"¾Æ´Ï Ä£±¸µé ¸»ÀÌ¶óµµ ÇØÁÖÁö..±Ã½Ã··±Ã½Ã··\n¾Æ¸Â´Ù ³ª Ä£±¸¾øÁö..." } };
public:
	SINGLE(CardMgr);
private:
	Image* A = ResMgr::GetInst()->ImgLoad(L"CardA", L"Image\\Card\\Card_A.bmp");
	Image* B = ResMgr::GetInst()->ImgLoad(L"CardB", L"Image\\Card\\Card_B.bmp");
	Image* C = ResMgr::GetInst()->ImgLoad(L"CardC", L"Image\\Card\\Card_C.bmp");
	Image* D = ResMgr::GetInst()->ImgLoad(L"CardD", L"Image\\Card\\Card_D.bmp");
	Image* E = ResMgr::GetInst()->ImgLoad(L"CardE", L"Image\\Card\\Card_E.bmp");
	map<UINT, Image*> images = {
		{(UINT)CARD_TYPE::A, A},
		{(UINT)CARD_TYPE::B, B},
		{(UINT)CARD_TYPE::C, C},
		{(UINT)CARD_TYPE::D, D},
		{(UINT)CARD_TYPE::E, E}
	};
	CardStats m_vCard[(UINT)CARD_TYPE::END];
	map<UINT, int> hpStats = 
	{ 
		{(UINT)CARD_TYPE::A, 10},
		{(UINT)CARD_TYPE::B, 0},
		{(UINT)CARD_TYPE::C, 10}, 
		{(UINT)CARD_TYPE::D, 5},
		{(UINT)CARD_TYPE::E, 0} 
	};
	map<UINT, int> stressStats = 
	{ 
		{(UINT)CARD_TYPE::A, 5}, 
		{(UINT)CARD_TYPE::B, 5}, 
		{(UINT)CARD_TYPE::C, 0}, 
		{(UINT)CARD_TYPE::D, -10},
		{(UINT)CARD_TYPE::E, 30} 
	};
public:
	const CardStats GetCardStat(int idx) { return m_vCard[idx]; }
	Image* GetCardImage(int idx) { return images[idx]; }
public:
	void Init();
};

