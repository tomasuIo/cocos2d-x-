#include "Hero.h"

Hero::Hero()
{
	hero_ATK = 100;
	hero_DEF = 100;
	hero_HP = 5000;
}
Hero::~Hero()
{

}
bool Hero::init()
{
	return true;
}
int Hero::getATK()
{
	return this->hero_ATK;
}
int Hero::getDEF()
{
	return this->hero_DEF;
}
int Hero::getHP()
{
	return this->hero_HP;
}