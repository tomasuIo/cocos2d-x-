#ifndef _MONSTERMANAGER_H_
#define _MONSTERMANAGER_H_
#include "cocos2d.h"
#include "Hero.h"
#include "help_scene.h"
using namespace cocos2d;

class  monsterMG : public Sprite
{
 public:
	monsterMG();
	CREATE_FUNC(monsterMG);
	Hero* HERO = Hero::create();
	virtual bool init();
    virtual void update( float dt);
	void bindHero(Hero* hero);
	bool is_fight();
	Point monsterPosition;
	Label* monsterlabel[4];
    char* monstername1 = nullptr;
	char* monstername2 = nullptr;
	char* monstername3 = nullptr;
	char* monstername4 = nullptr;
	char* monstername5 = nullptr;
	int CallbackFucSelector;
	int hero_money_change;
	int hero_hp_change;
	int hero_atk_change;
	int hero_def_change;
	int monstersize;
	Sprite* monster;
	int monster_HP;
	int monster_ATK;
	int monster_DEF;

	Sprite* monster_sprite;

public:
	~monsterMG() {
		delete[] monstername1;
		delete[] monstername2;
	}
};





#endif // !_MONSTERMANAGER_H_
