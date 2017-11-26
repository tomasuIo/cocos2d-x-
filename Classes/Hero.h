#ifndef _HERO_H
#define _HERO_H

#include "cocos2d.h"

using namespace cocos2d;

class Hero : public Sprite
{
public:
	Hero();
	~Hero();

	CREATE_FUNC(Hero);
	virtual bool init();
	cocos2d::Sprite* hero1;
	cocos2d::Sprite* hero2;
	cocos2d::Sprite* hero3;
	cocos2d::Sprite* hero4;
	bool move = true ;
	bool move2 = true;
	int getHP();
	int getDEF();
	int getATK();
	int hero_ykey;
	int hero_rkey;
	int hero_bkey;
	int hero_money = 1000;
	int hero_HP = 5000;
	int hero_ATK = 100;
	int hero_DEF = 100;
	
private:
	Sprite* hero_sprite;
	
};

#endif 
