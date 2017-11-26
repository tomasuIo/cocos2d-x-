#include "Monstermanager.h"
monsterMG::monsterMG()
{

}

bool monsterMG::init()
{ 
	
	this->scheduleUpdate();
	return true;
}


bool monsterMG::is_fight()
{
	int heroatk = HERO->getATK();
	int herohp = HERO->getHP();
	int herodef = HERO->getDEF();
	if (heroatk <= monster_DEF)
	{
		return false;
	}
	else
	{
		if (herohp*(heroatk-monster_DEF)>monster_HP*(monster_ATK - herodef))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
}

void monsterMG::bindHero(Hero* hero)
{
	switch (CallbackFucSelector)
	{
	case 1:
	{

		monster = Sprite::create(monstername1);
		monster->setPosition(monsterPosition);
		this->addChild(monster, 10);
		auto* monster_animation = Animation::create();
		monster_animation->addSpriteFrameWithFile(monstername1);
		monster_animation->addSpriteFrameWithFile(monstername2);
		monster_animation->setLoops(-1);
		monster_animation->setDelayPerUnit(0.2f);
		auto* monsteraction = Animate::create(monster_animation);
		monster->runAction(monsteraction);
		monster_sprite = Sprite::create(monstername1);
		monster_sprite->setPosition(850, 320);
		monster_sprite->setOpacity(0);
		this->addChild(monster_sprite, 10);
		
		
		HERO = hero;
		HERO->hero1 = hero->hero1;
		HERO->hero2 = hero->hero2;
		HERO->hero3 = hero->hero3;
		HERO->hero4 = hero->hero4;

		monsterlabel[0] = Label::create("0", "Arial", 25);
		monsterlabel[1] = Label::create(String::createWithFormat("%d", monster_ATK)->getCString(), "Arial", 25);
		monsterlabel[2] = Label::create(String::createWithFormat("%d", monster_DEF)->getCString(), "Arial", 25);
		monsterlabel[3] = Label::create(String::createWithFormat("%d", hero_money_change)->getCString(), "Arial", 25);
		for (int i = 0; i < 4; i++)
		{
			monsterlabel[i]->setAnchorPoint(Vec2(0, 0));
			monsterlabel[i]->setPosition(822, 160 - i * 39);
			monsterlabel[i]->setOpacity(0);
			this->addChild(monsterlabel[i], 100);
		}   
	}
		
		break;
	case 2:
	{
		monster = Sprite::create(monstername1);
		monster->setPosition(monsterPosition);
		this->addChild(monster);
		HERO = hero;
		HERO->hero1 = hero->hero1;
		HERO->hero2 = hero->hero2;
		HERO->hero3 = hero->hero3;
		HERO->hero4 = hero->hero4;
	}
		break;
	case 3:
	{
		monster = Sprite::create(monstername1);
		monster->setPosition(monsterPosition);
		this->addChild(monster);
		HERO = hero;
		HERO->hero1 = hero->hero1;
		HERO->hero2 = hero->hero2;
		HERO->hero3 = hero->hero3;
		HERO->hero4 = hero->hero4;
	}
	break;
	case 4:
	{
		monster = Sprite::create(monstername1);
		monster->setPosition(monsterPosition);
		this->addChild(monster);
		HERO = hero;
		HERO->hero1 = hero->hero1;
		HERO->hero2 = hero->hero2;
		HERO->hero3 = hero->hero3;
		HERO->hero4 = hero->hero4;
	}
	default:
		break;
	}
	

}

void monsterMG::update(float dt)
{
	switch (CallbackFucSelector)
	{
	case 1:                              
	{
		
		monster_sprite->setOpacity(0);
		monsterlabel[0]->setOpacity(0);
		monsterlabel[1]->setOpacity(0);
		monsterlabel[2]->setOpacity(0);
		monsterlabel[3]->setOpacity(0);
		if (monstersize == 1)
		{
			if (HERO->hero1->getOpacity() != 0
				&& HERO->hero1->getPosition() == monsterPosition + Vec2(0, 50))
			
			{
				monsterlabel[0]->setOpacity(255);
				monsterlabel[1]->setOpacity(255);
				monsterlabel[2]->setOpacity(255);
				monsterlabel[3]->setOpacity(255);
				monsterlabel[0]->setString(String::createWithFormat("%d", monster_HP)->getCString());
				monsterlabel[1]->setString(String::createWithFormat("%d", monster_ATK)->getCString());
				monsterlabel[2]->setString(String::createWithFormat("%d", monster_DEF)->getCString());
				monsterlabel[3]->setString(String::createWithFormat("%d", hero_money_change)->getCString());
				monster_sprite->setOpacity(255);	
				if (!is_fight())
				{
					HERO->move = false;
					monster_sprite->setOpacity(255);
				}
			}

			if (HERO->hero2->getOpacity() != 0
				&& HERO->hero2->getPosition() == monsterPosition + Vec2(-50, 0))
			{
				monsterlabel[0]->setOpacity(255);
				monsterlabel[1]->setOpacity(255);
				monsterlabel[2]->setOpacity(255);
				monsterlabel[3]->setOpacity(255);
				monsterlabel[0]->setString(String::createWithFormat("%d", monster_HP)->getCString());
				monsterlabel[1]->setString(String::createWithFormat("%d", monster_ATK)->getCString());
				monsterlabel[2]->setString(String::createWithFormat("%d", monster_DEF)->getCString());
				monsterlabel[3]->setString(String::createWithFormat("%d", hero_money_change)->getCString());
				monster_sprite->setOpacity(255);
				if (!is_fight())
				{
					HERO->move = false;
					monster_sprite->setOpacity(255);
				}
			}
			if (HERO->hero3->getOpacity() != 0
				&& HERO->hero3->getPosition() == monsterPosition + Vec2(0, -50))
			{
				monsterlabel[0]->setOpacity(255);
				monsterlabel[1]->setOpacity(255);
				monsterlabel[2]->setOpacity(255);
				monsterlabel[3]->setOpacity(255);
				monsterlabel[0]->setString(String::createWithFormat("%d", monster_HP)->getCString());
				monsterlabel[1]->setString(String::createWithFormat("%d", monster_ATK)->getCString());
				monsterlabel[2]->setString(String::createWithFormat("%d", monster_DEF)->getCString());
				monsterlabel[3]->setString(String::createWithFormat("%d", hero_money_change)->getCString());
				monster_sprite->setOpacity(255);
				if (!is_fight())
				{
					HERO->move = false;
					monster_sprite->setOpacity(255);
				}
			}
			if (HERO->hero4->getOpacity() != 0
				&& HERO->hero4->getPosition() == monsterPosition + Vec2(50, 0))
			{
				monsterlabel[0]->setOpacity(255);
				monsterlabel[1]->setOpacity(255);
				monsterlabel[2]->setOpacity(255);
				monsterlabel[3]->setOpacity(255);
				monsterlabel[0]->setString(String::createWithFormat("%d", monster_HP)->getCString());
				monsterlabel[1]->setString(String::createWithFormat("%d", monster_ATK)->getCString());
				monsterlabel[2]->setString(String::createWithFormat("%d", monster_DEF)->getCString());
				monsterlabel[3]->setString(String::createWithFormat("%d", hero_money_change)->getCString());
				monster_sprite->setOpacity(255);
				if (!is_fight())
				{
					HERO->move = false;
					monster_sprite->setOpacity(255);
				}
			}


			
			if (HERO->hero1->getPosition() == monsterPosition)
			{
				HERO->move2 = false;
				HERO->move = false;
			

				monsterlabel[0]->setOpacity(255);
				monsterlabel[1]->setOpacity(255);
				monsterlabel[2]->setOpacity(255);
				monsterlabel[3]->setOpacity(255);
				monster_sprite->setOpacity(255);
				monster->setOpacity(0);

				auto* fight = Sprite::create("fight1.png");
				fight->setPosition(monsterPosition);
				addChild(fight, 3);
				auto* fight_animation = Animation::create();
				fight_animation->addSpriteFrameWithFile("fight1.png");
				fight_animation->addSpriteFrameWithFile(monstername1);
				fight_animation->addSpriteFrameWithFile("fight21.png");
				fight_animation->addSpriteFrameWithFile("hero1.png");
				fight_animation->addSpriteFrameWithFile("fight41.png");
				fight_animation->setLoops(monster_HP / (HERO->getATK() - monster_DEF));
				fight_animation->setDelayPerUnit(0.1f);
				auto* action1 = Animate::create(fight_animation);
				auto func1 = [=]()
				{
					fight->setOpacity(0);
					HERO->move2 = true;
					HERO->move = true;
					
					if (monster_ATK > HERO->hero_DEF)
					{
						HERO->hero_HP -= monster_HP / (HERO->hero_ATK - monster_DEF)*(monster_ATK - HERO->hero_DEF);
					};
					monster_sprite->setOpacity(0);
					monsterlabel[0]->setOpacity(0);
					monsterlabel[1]->setOpacity(0);
					monsterlabel[2]->setOpacity(0);
					monsterlabel[3]->setOpacity(0);
				};

				CallFunc* callfunc1 = CallFunc::create(func1);

				auto action2 = Sequence::create(action1, callfunc1, NULL);
				fight->runAction(action2);

				HERO->hero_money += hero_money_change;
				this->unscheduleUpdate();

			}
			

		}
		
		if (monstersize == 3)
		{
			if (HERO->hero1->getOpacity() != 0
				&& (HERO->hero1->getPosition() == monsterPosition + Vec2(0, 100)
					|| HERO->hero1->getPosition() == monsterPosition + Vec2(-50, 100)
					|| HERO->hero1->getPosition() == monsterPosition + Vec2(50, 100)))
			{
				monsterlabel[0]->setOpacity(255);
				monsterlabel[1]->setOpacity(255);
				monsterlabel[2]->setOpacity(255);
				monsterlabel[3]->setOpacity(255);
				monsterlabel[0]->setString(String::createWithFormat("%d", monster_HP)->getCString());
				monsterlabel[1]->setString(String::createWithFormat("%d", monster_ATK)->getCString());
				monsterlabel[2]->setString(String::createWithFormat("%d", monster_DEF)->getCString());
				monsterlabel[3]->setString(String::createWithFormat("%d", hero_money_change)->getCString());
				monster_sprite->setOpacity(255);
				if (!is_fight())
				{
					HERO->move = false;
				}
			}

			if (HERO->hero2->getOpacity() != 0
				&& (HERO->hero2->getPosition() == monsterPosition + Vec2(-100, -50)
					|| HERO->hero2->getPosition() == monsterPosition + Vec2(-100, 0)
					|| HERO->hero2->getPosition() == monsterPosition + Vec2(-100, 50)))

			{
				monsterlabel[0]->setOpacity(255);
				monsterlabel[1]->setOpacity(255);
				monsterlabel[2]->setOpacity(255);
				monsterlabel[3]->setOpacity(255);
				monsterlabel[0]->setString(String::createWithFormat("%d", monster_HP)->getCString());
				monsterlabel[1]->setString(String::createWithFormat("%d", monster_ATK)->getCString());
				monsterlabel[2]->setString(String::createWithFormat("%d", monster_DEF)->getCString());
				monsterlabel[3]->setString(String::createWithFormat("%d", hero_money_change)->getCString());
				monster_sprite->setOpacity(255);
				if (!is_fight())
				{
					HERO->move = false;
				}
			}
			if (HERO->hero3->getOpacity() != 0
				&& (HERO->hero3->getPosition() == monsterPosition + Vec2(-50, -100)
					|| HERO->hero3->getPosition() == monsterPosition + Vec2(0, -100)
					|| HERO->hero3->getPosition() == monsterPosition + Vec2(50, -100)))
			{
				monsterlabel[0]->setOpacity(255);
				monsterlabel[1]->setOpacity(255);
				monsterlabel[2]->setOpacity(255);
				monsterlabel[3]->setOpacity(255);
				monsterlabel[0]->setString(String::createWithFormat("%d", monster_HP)->getCString());
				monsterlabel[1]->setString(String::createWithFormat("%d", monster_ATK)->getCString());
				monsterlabel[2]->setString(String::createWithFormat("%d", monster_DEF)->getCString());
				monsterlabel[3]->setString(String::createWithFormat("%d", hero_money_change)->getCString());
				monster_sprite->setOpacity(255);
				if (!is_fight())
				{
					HERO->move = false;
				}
			}
			if (HERO->hero4->getOpacity() != 0
				&& (HERO->hero4->getPosition() == monsterPosition + Vec2(100, -50)
					|| HERO->hero4->getPosition() == monsterPosition + Vec2(100, 0)
					|| HERO->hero4->getPosition() == monsterPosition + Vec2(100, 50)))
			{

				monsterlabel[0]->setOpacity(255);
				monsterlabel[1]->setOpacity(255);
				monsterlabel[2]->setOpacity(255);
				monsterlabel[3]->setOpacity(255);
				monsterlabel[0]->setString(String::createWithFormat("%d", monster_HP)->getCString());
				monsterlabel[1]->setString(String::createWithFormat("%d", monster_ATK)->getCString());
				monsterlabel[2]->setString(String::createWithFormat("%d", monster_DEF)->getCString());
				monsterlabel[3]->setString(String::createWithFormat("%d", hero_money_change)->getCString());
				monster_sprite->setOpacity(255);
				if (!is_fight())
				{
					HERO->move = false;
				}
			}
			
			if (HERO->hero1->getPosition() == monsterPosition
				|| HERO->hero1->getPosition() == monsterPosition + Vec2(0, -50)
				|| HERO->hero1->getPosition() == monsterPosition + Vec2(0, 50)
				|| HERO->hero1->getPosition() == monsterPosition + Vec2(50, 0)
				|| HERO->hero1->getPosition() == monsterPosition + Vec2(-50, 0)
				|| HERO->hero1->getPosition() == monsterPosition + Vec2(-50, -50)
				|| HERO->hero1->getPosition() == monsterPosition + Vec2(50, 50)
				|| HERO->hero1->getPosition() == monsterPosition + Vec2(50, -50)
				|| HERO->hero1->getPosition() == monsterPosition + Vec2(-50, 50))
			{
				HERO->move2 = false;
				HERO->move = false;
				HERO->hero3->setOpacity(0);

				monsterlabel[0]->setOpacity(255);
				monsterlabel[1]->setOpacity(255);
				monsterlabel[2]->setOpacity(255);
				monsterlabel[3]->setOpacity(255);
				monster_sprite->setOpacity(255);
				monster->setOpacity(0);
			
				auto* fight = Sprite::create("fight1.png");
				fight->setPosition(monsterPosition);
				addChild(fight, 3);
				auto* fight_animation = Animation::create();
				fight_animation->addSpriteFrameWithFile("fight1.png");
				fight_animation->addSpriteFrameWithFile("molong1.png");
				fight_animation->addSpriteFrameWithFile("fight21.png");
				fight_animation->addSpriteFrameWithFile("hero1.png");
				fight_animation->addSpriteFrameWithFile("fight41.png");
				fight_animation->setLoops(monster_HP / (HERO->getATK() - monster_DEF));
				fight_animation->setDelayPerUnit(0.1f);
				auto* action1 = Animate::create(fight_animation);
				auto func1 = [=]() 
				{ 
					fight->setOpacity(0);
					HERO->move2 = true;
					HERO->move = true;
					HERO->hero3->setOpacity(255);
					if (monster_ATK > HERO->hero_DEF)
					{
						HERO->hero_HP -= monster_HP / (HERO->hero_ATK - monster_DEF)*(monster_ATK - HERO->hero_DEF);
					};
					monster_sprite->setOpacity(0);
					monsterlabel[0]->setOpacity(0);
					monsterlabel[1]->setOpacity(0);
					monsterlabel[2]->setOpacity(0);
					monsterlabel[3]->setOpacity(0);
				};
				
				CallFunc* callfunc1 = CallFunc::create(func1);
				
				auto action2 = Sequence::create(action1, callfunc1, NULL);
				fight->runAction(action2);
				
				HERO->hero_money += hero_money_change;
				this->unscheduleUpdate();

			}
			
		}
		break;
	}
	case 2:            
	{
		if ((HERO->hero1->getOpacity() != 0 && HERO->hero1->getPosition() == monsterPosition + Vec2(0, 50))
			|| (HERO->hero2->getOpacity() != 0 && HERO->hero2->getPosition() == monsterPosition + Vec2(-50, 0))
			|| (HERO->hero3->getOpacity() != 0 && HERO->hero3->getPosition() == monsterPosition + Vec2(0, -50))
			|| (HERO->hero4->getOpacity() != 0 && HERO->hero4->getPosition() == monsterPosition + Vec2(50, 0)))
		{
			/*bool canopen = false;
			if (monstername1 = "men.png")
			{
				HERO->hero_ykey -= 1;
				if (HERO->hero_ykey>=0)
				{
					canopen = true;
				}
				else
				{
					HERO->hero_ykey = 0;
					canopen = false;
				}

			}
			if (monstername1 = "bdoor")
			{
				HERO->hero_bkey -= 1;
				if (HERO->hero_bkey >= 0)
				{
					canopen = true;
				}
				else
				{
					HERO->hero_bkey = 0;
					canopen = false;
				}
			}
			if (monstername1 = "rdoor")
			{
				HERO->hero_rkey -= 1;
				if (HERO->hero_rkey >= 0)
				{
					canopen = true;
				}
				else
				{
					HERO->hero_rkey = 0;
					canopen = false;
				}
			}*/
			if (true)
			{
				HERO->move = false;
				monster->setOpacity(0);
				auto* eattool = Sprite::create(monstername1);
				addChild(eattool, 3);

				eattool->setPosition(monsterPosition);

				auto* eattool_animation = Animation::create();
				eattool_animation->addSpriteFrameWithFile(monstername1);
				eattool_animation->addSpriteFrameWithFile(monstername2);
				eattool_animation->addSpriteFrameWithFile(monstername3);
				eattool_animation->addSpriteFrameWithFile(monstername4);
				eattool_animation->addSpriteFrameWithFile(monstername5);
				eattool_animation->setLoops(1);
				eattool_animation->setDelayPerUnit(0.09f);
				auto* action1 = Animate::create(eattool_animation);
				auto func1 = [=]() { eattool->setOpacity(0); };
				auto func2 = [=]() { HERO->move = true; };
				CallFunc* callfunc1 = CallFunc::create(func1);
				CallFunc* callfunc2 = CallFunc::create(func2);
				auto action2 = Sequence::create(action1, callfunc1, callfunc2, NULL);
				eattool->runAction(action2);
				HERO->hero_ykey -= 1;
				this->unscheduleUpdate();
			}
			
			
		}
	}
	break;
	case 3:
	{
		if (HERO->hero1->getPosition() == monsterPosition)
		{
			monster->setOpacity(0);
			HERO->hero_ATK += hero_atk_change;
			HERO->hero_DEF += hero_def_change;
			HERO->hero_HP += hero_hp_change;
			this->unscheduleUpdate();
		}
	}

	break;
	case 4:
	{
		if (HERO->hero1->getPosition() == monsterPosition)
		{
			monster->setOpacity(0);
			Director::getInstance()->pushScene(Help_scene::createScene());
			this->unscheduleUpdate();
		}
	}
		

	default:
	
		break;
	}

	
}





