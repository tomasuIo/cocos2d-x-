
#include "Game_Scene.h"
#include "help_scene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include <fstream>

USING_NS_CC;

using namespace cocostudio::timeline;

void Game_scene::update(float dt)
{

}

bool Game_scene::isCanReach(float x, float y)
{
	bool result;
	int mapX = (int)((x - 25) / 50);
	int mapY = (int)(14 - (y - 25) / 50);
	int tileGid = meta->tileGIDAt(Vec2(mapX, mapY));
	if (tileGid != 0)
	{
		result = false;
	}
	else
	{
		result = true;
	}
	return result;
}
bool Game_scene::init()
{
	return true;
}



Scene* Game_scene1::createScene()
{

	auto scene = Scene::create();
	auto layer = Game_scene1::create();
	scene->addChild(layer);
	return scene;
}


Scene* Game_scene2::createScene()
{
	auto scene = Scene::create();
	auto layer = Game_scene2::create();
	scene->addChild(layer);
	return scene;
}


Scene* Game_scene3::createScene()
{
	auto scene = Scene::create();
	auto layer = Game_scene3::create();
	scene->addChild(layer);
	return scene;
}

void Game_scene1::update(float dt)
{

	if (hero->hero_ATK != memory[1])
	{
		memory[1] = hero->hero_ATK;
		label[1]->setString(String::createWithFormat("%d", hero->hero_ATK)->getCString());
	}
	if (hero->hero_DEF != memory[2])
	{
		memory[2] = hero->hero_DEF;
		label[2]->setString(String::createWithFormat("%d", hero->hero_DEF)->getCString());
	}
	if (hero->hero_HP != memory[0])
	{
		memory[0] = hero->hero_HP;
		label[0]->setString(String::createWithFormat("%d", hero->hero_HP)->getCString());
	}
	if (hero->hero_money != memory[3])
	{
		memory[3] = hero->hero_money;
		label[3]->setString(String::createWithFormat("%d", hero->hero_money)->getCString());
	}
	if (hero->hero1->getPosition() == Vec2(375, 675))
	{

		
		Json::Value root0;
		Json::FastWriter writer0;
		root0["atk"] = hero->hero_ATK;
		root0["def"] = hero->hero_DEF;
		root0["hp"] = hero->hero_HP;
		root0["posx"] = hero->hero1->getPositionX()+50;
		root0["posy"] = hero->hero1->getPositionY();
		std::string json_file0 = writer0.write(root0);
		FILE* file0 = fopen("hero.json", "w");
		fprintf(file0, json_file0.c_str());
		fclose(file0);


		Json::Value root1;
		Json::Value arrayobj;

		Json::FastWriter writer;
		std::vector<Json::Value> Item;
		for (auto &mon : Monster)
		{
			if (mon->monster->getOpacity() != 0)
			{
				Json::Value item;
				item["name1"] = mon->monstername1;
				item["name2"] = mon->monstername2;
				item["name3"] = mon->monstername3;
				item["name4"] = mon->monstername4;
				item["name5"] = mon->monstername5;
				item["case"] = mon->CallbackFucSelector;
				item["size"] = mon->monstersize;
				item["atk"] = mon->monster_ATK;
				item["def"] = mon->monster_DEF;
				item["hp"] = mon->monster_HP;
				item["money_change"] = mon->hero_money_change;
				item["atk_change"] = mon->hero_atk_change;
				item["def_change"] = mon->hero_def_change;
				item["hp_change"] = mon->hero_hp_change;
				item["posx"] = mon->monster->getPositionX();
				item["posy"] = mon->monster->getPositionY();
				Item.push_back(item);
			}

		}
		for (auto &ary : Item)
		{
			arrayobj.append(ary);
		}
		root1["monster"] = arrayobj;
		std::string json_file = writer.write(root1);
		FILE* file = fopen("floor1_monster.json", "w");
		fprintf(file, json_file.c_str());
		fclose(file);
		Director::getInstance()->pushScene(Game_scene2::createScene());
	}

}

void Game_scene2::update(float dt)
{
	if (hero->hero_ATK != memory[1])
	{
		memory[1] = hero->hero_ATK;
		label[1]->setString(String::createWithFormat("%d", hero->hero_ATK)->getCString());
	}
	if (hero->hero_DEF != memory[2])
	{
		memory[2] = hero->hero_DEF;
		label[2]->setString(String::createWithFormat("%d", hero->hero_DEF)->getCString());
	}
	if (hero->hero_HP != memory[0])
	{
		memory[0] = hero->hero_HP;
		label[0]->setString(String::createWithFormat("%d", hero->hero_HP)->getCString());
	}
	if (hero->hero_money != memory[3])
	{
		memory[3] = hero->hero_money;
		label[3]->setString(String::createWithFormat("%d", hero->hero_money)->getCString());
	}
	if (hero->hero1->getPosition() == Vec2(75, 75))
	{
		Json::Value root0;
		Json::FastWriter writer0;
		root0["atk"] = hero->hero_ATK;
		root0["def"] = hero->hero_DEF;
		root0["hp"] = hero->hero_HP;
		root0["posx"] = hero->hero1->getPositionX()+50;
		root0["posy"] = hero->hero1->getPositionY();
		std::string json_file0 = writer0.write(root0);
		FILE* file0 = fopen("hero.json", "w");
		fprintf(file0, json_file0.c_str());
		fclose(file0);

		Json::Value root1;
		Json::Value arrayobj;
		Json::FastWriter writer;
		std::vector<Json::Value> Item;
		for (auto &mon : Monster)
		{
			if (mon->monster->getOpacity() != 0)
			{
				Json::Value item;
				item["name1"] = mon->monstername1;
				item["name2"] = mon->monstername2;
				item["name3"] = mon->monstername3;
				item["name4"] = mon->monstername4;
				item["name5"] = mon->monstername5;
				item["case"] = mon->CallbackFucSelector;
				item["size"] = mon->monstersize;
				item["atk"] = mon->monster_ATK;
				item["def"] = mon->monster_DEF;
				item["hp"] = mon->monster_HP;
				item["money_change"] = mon->hero_money_change;
				item["atk_change"] = mon->hero_atk_change;
				item["def_change"] = mon->hero_def_change;
				item["hp_change"] = mon->hero_hp_change;
				item["posx"] = mon->monster->getPositionX();
				item["posy"] = mon->monster->getPositionY();
				Item.push_back(item);
			}

		}
		for (auto &ary : Item)
		{
			arrayobj.append(ary);
		}
		root1["monster"] = arrayobj;
		std::string json_file = writer.write(root1);
		FILE* file = fopen("floor2_monster.json", "w");
		fprintf(file, json_file.c_str());
		fclose(file);

	    Director::getInstance()->pushScene(Game_scene3::createScene());
	}

	if (hero->hero1->getPosition() == Vec2(375, 675))
	{
		Json::Value root0;
		Json::FastWriter writer0;
		root0["atk"] = hero->hero_ATK;
		root0["def"] = hero->hero_DEF;
		root0["hp"] = hero->hero_HP;
		root0["posx"] = hero->hero1->getPositionX()+50;
		root0["posy"] = hero->hero1->getPositionY();
		std::string json_file0 = writer0.write(root0);
		FILE* file0 = fopen("hero.json", "w");
		fprintf(file0, json_file0.c_str());
		fclose(file0);

		Json::Value root1;
		Json::Value arrayobj;
		Json::FastWriter writer;
		std::vector<Json::Value> Item;
		for (auto &mon : Monster)
		{
			if (mon->monster->getOpacity() != 0)
			{
				Json::Value item;
				item["name1"] = mon->monstername1;
				item["name2"] = mon->monstername2;
				item["name3"] = mon->monstername3;
				item["name4"] = mon->monstername4;
				item["name5"] = mon->monstername5;
				item["case"] = mon->CallbackFucSelector;
				item["size"] = mon->monstersize;
				item["atk"] = mon->monster_ATK;
				item["def"] = mon->monster_DEF;
				item["hp"] = mon->monster_HP;
				item["money_change"] = mon->hero_money_change;
				item["atk_change"] = mon->hero_atk_change;
				item["def_change"] = mon->hero_def_change;
				item["hp_change"] = mon->hero_hp_change;
				item["posx"] = mon->monster->getPositionX();
				item["posy"] = mon->monster->getPositionY();
				Item.push_back(item);
			}

		}
		for (auto &ary : Item)
		{
			arrayobj.append(ary);
		}
		root1["monster"] = arrayobj;
		std::string json_file = writer.write(root1);
		FILE* file = fopen("floor2_monster.json", "w");
		fprintf(file, json_file.c_str());
		fclose(file);

		Director::getInstance()->pushScene(Game_scene1::createScene());
	}

}
	void Game_scene3::update(float dt)
	{
		if (hero->hero_ATK != memory[1])
		{
			memory[1] = hero->hero_ATK;
			label[1]->setString(String::createWithFormat("%d", hero->hero_ATK)->getCString());
		}
		if (hero->hero_DEF != memory[2])
		{
			memory[2] = hero->hero_DEF;
			label[2]->setString(String::createWithFormat("%d", hero->hero_DEF)->getCString());
		}
		if (hero->hero_HP != memory[0])
		{
			memory[0] = hero->hero_HP;
			label[0]->setString(String::createWithFormat("%d", hero->hero_HP)->getCString());
		}
		if (hero->hero_money != memory[3])
		{
			memory[3] = hero->hero_money;
			label[3]->setString(String::createWithFormat("%d", hero->hero_money)->getCString());
		}
		if (hero->hero1->getPosition() == Vec2(75, 75))
		{


			Json::Value root0;
			Json::FastWriter writer0;
			root0["atk"] = hero->hero_ATK;
			root0["def"] = hero->hero_DEF;
			root0["hp"] = hero->hero_HP;
			root0["posx"] = hero->hero1->getPositionX()+50;
			root0["posy"] = hero->hero1->getPositionY();
			std::string json_file0 = writer0.write(root0);
			FILE* file0 = fopen("hero.json", "w");
			fprintf(file0, json_file0.c_str());
			fclose(file0);




			Json::Value root1;
			Json::Value arrayobj;

			Json::FastWriter writer;
			std::vector<Json::Value> Item;
			for (auto &mon : Monster)
			{
				if (mon->monster->getOpacity() != 0)
				{
					Json::Value item;
					item["name1"] = mon->monstername1;
					item["name2"] = mon->monstername2;
					item["name3"] = mon->monstername3;
					item["name4"] = mon->monstername4;
					item["name5"] = mon->monstername5;
					item["case"] = mon->CallbackFucSelector;
					item["size"] = mon->monstersize;
					item["atk"] = mon->monster_ATK;
					item["def"] = mon->monster_DEF;
					item["hp"] = mon->monster_HP;
					item["money_change"] = mon->hero_money_change;
					item["atk_change"] = mon->hero_atk_change;
					item["def_change"] = mon->hero_def_change;
					item["hp_change"] = mon->hero_hp_change;
					item["posx"] = mon->monster->getPositionX();
					item["posy"] = mon->monster->getPositionY();
					Item.push_back(item);
				}

			}
			for (auto &ary : Item)
			{
				arrayobj.append(ary);
			}
			root1["monster"] = arrayobj;
			std::string json_file = writer.write(root1);
			FILE* file = fopen("floor3_monster.json", "w");
			fprintf(file, json_file.c_str());
			fclose(file);

			Director::getInstance()->pushScene(Game_scene2::createScene());
		}
	}

	void Game_scene::mupdate(float dt)
	{

		auto leftArrow = EventKeyboard::KeyCode::KEY_LEFT_ARROW, rightArrow = EventKeyboard::KeyCode::KEY_RIGHT_ARROW;
		auto upArrow = EventKeyboard::KeyCode::KEY_UP_ARROW, downArrow = EventKeyboard::KeyCode::KEY_DOWN_ARROW;
		if (isKeyPressed(leftArrow))
		{
			float x = hero->hero1->getPositionX();

			if (hero->move2 &&hero->hero4->getOpacity() != 255)
			{
				hero->move = true;
				hero->hero1->setOpacity(0);
				hero->hero2->setOpacity(0);
				hero->hero3->setOpacity(0);
				hero->hero4->setOpacity(255);
			}
			else
			{
				if (isCanReach(hero->hero1->getPositionX() - 50, hero->hero1->getPositionY()))
				{
					if (hero->move)
					{
						x -= 50;
						hero->hero1->setPositionX(x);
						hero->hero2->setPositionX(x);
						hero->hero3->setPositionX(x);
						hero->hero4->setPositionX(x);
					}

				}
			}
		}
		if (isKeyPressed(rightArrow))
		{
			float x = hero->hero1->getPositionX();
			if (hero->move2 &&hero->hero2->getOpacity() != 255)
			{
				hero->move = true;
				hero->hero1->setOpacity(0);
				hero->hero2->setOpacity(255);
				hero->hero3->setOpacity(0);
				hero->hero4->setOpacity(0);
			}
			else
			{


				if (isCanReach(hero->hero1->getPositionX() + 50, hero->hero1->getPositionY()))
				{
					if (hero->move)
					{
						x += 50;
						hero->hero1->setPositionX(x);
						hero->hero2->setPositionX(x);
						hero->hero4->setPositionX(x);
						hero->hero3->setPositionX(x);
					}
				}

			}
		}
		if (isKeyPressed(upArrow))
		{
			float y = hero->hero1->getPositionY();
			if (hero->move2 &&hero->hero3->getOpacity() != 255)
			{
				hero->move = true;
				hero->hero1->setOpacity(0);
				hero->hero2->setOpacity(0);
				hero->hero4->setOpacity(0);
				hero->hero3->setOpacity(255);
			}
			else
			{

				if (isCanReach(hero->hero1->getPositionX(), hero->hero1->getPositionY() + 50))
				{
					if (hero->move)
					{
						y += 50;
						hero->hero3->setPositionY(y);
						hero->hero4->setPositionY(y);
						hero->hero1->setPositionY(y);
						hero->hero2->setPositionY(y);
					}
				}
			}
		}
		if (isKeyPressed(downArrow))
		{
			float y = hero->hero1->getPositionY();
			if (hero->move2 && hero->hero1->getOpacity() != 255)
			{
				hero->move = true;
				hero->hero1->setOpacity(255);
				hero->hero2->setOpacity(0);
				hero->hero3->setOpacity(0);
				hero->hero4->setOpacity(0);

			}
			else
			{
				if (isCanReach(hero->hero1->getPositionX(), hero->hero1->getPositionY() - 50))
				{
					if (hero->move)
					{
						y -= 50;
						hero->hero3->setPositionY(y);
						hero->hero4->setPositionY(y);
						hero->hero2->setPositionY(y);
						hero->hero1->setPositionY(y);
					}
				}
			}
		}

	}




	bool Game_scene1::init()
	{

		if (!Layer::init())
		{
			return false;
		}


		Point origin = Director::getInstance()->getVisibleOrigin();
		Size size = Director::getInstance()->getVisibleSize();
		map = TMXTiledMap::create("map1.tmx");
		map->setPosition(0, 0);
		addChild(map);
		meta = map->layerNamed("layer3");
		auto* map2 = TMXTiledMap::create("Layer.tmx");
		map2->setPosition(750, 0);
		addChild(map2);
		do
		{
			hero = Hero::create();
			hero->retain();
			hero->hero1 = Sprite::create("hero1.png");

			hero->hero2 = Sprite::create("hero2.png");

			hero->hero3 = Sprite::create("hero3.png");

			hero->hero4 = Sprite::create("hero4.png");

		} while (0);

		Json::Reader reader0;
		Json::Value root0;
		std::ifstream file0("hero.json");
		file0.seekg(0, file0.end);
		int length0 = file0.tellg();
		file0.seekg(0, file0.beg);
		char *cache0 = new char[length0];
		file0.read(cache0, length0);
		std::string data0 = cache0;
		delete[] cache0;
		if (reader0.parse(data0, root0, false) == true)
		{
			hero->hero_ATK = root0["atk"].asInt();
			hero->hero_DEF = root0["def"].asInt();
			hero->hero_HP = root0["hp"].asInt();
			hero->hero1->setPositionX(root0["posx"].asInt());
			hero->hero1->setPositionY(root0["posy"].asInt());
			hero->hero2->setPositionX(root0["posx"].asInt());
			hero->hero2->setPositionY(root0["posy"].asInt());
			hero->hero3->setPositionX(root0["posx"].asInt());
			hero->hero3->setPositionY(root0["posy"].asInt());
			hero->hero4->setPositionX(root0["posx"].asInt());
			hero->hero4->setPositionY(root0["posy"].asInt());
		}

		
		hero->hero1->setOpacity(255);
		
		hero->hero2->setOpacity(0);
		
		hero->hero3->setOpacity(0);
		
		hero->hero4->setOpacity(0);
		map->addChild(hero->hero1, 5);
		map->addChild(hero->hero2, 5);
		map->addChild(hero->hero3, 5);
		map->addChild(hero->hero4, 5);

		
		
		auto* louti1 = Sprite::create("louti1.png");
		louti1->setPosition(375, 675);
		map->addChild(louti1);

		Sprite* sprite4 = Sprite::create("herolabel.png");
		sprite4->setPosition(850, 115);
		this->addChild(sprite4);

		if (!Monster.empty())
		{
			Monster.clear();
		}

		Json::Reader reader;
		Json::Value root;

		std::ifstream file("floor1_monster.json");
		file.seekg(0, file.end);
		int length = file.tellg();
		file.seekg(0, file.beg);
		char *cache = new char[length];
		file.read(cache, length);
		std::string data = cache;
		delete[] cache;

		cocos2d::log(data.c_str());
		if (reader.parse(data, root, false) == true)
		{

			int iNum = root["monster"].size();
			for (int i = 0; i < iNum; i++)
			{
				monsterMG* monster = monsterMG::create();

				int x, y;

				char* tmp1 = root["monster"][i]["name1"].asCString();
				int len1 = strlen(tmp1);
				monster->monstername1 = new char[len1];
				strcpy(monster->monstername1, tmp1);

				char* tmp2 = root["monster"][i]["name2"].asCString();
				int len2 = strlen(tmp2);
				monster->monstername2 = new char[len2];
				strcpy(monster->monstername2, tmp2);

				char* tmp3 = root["monster"][i]["name3"].asCString();
				int len3 = strlen(tmp3);
				monster->monstername3 = new char[len3];
				strcpy(monster->monstername3, tmp3);

				char* tmp4 = root["monster"][i]["name4"].asCString();
				int len4 = strlen(tmp4);
				monster->monstername4 = new char[len4];
				strcpy(monster->monstername4, tmp4);

				char* tmp5 = root["monster"][i]["name5"].asCString();
				int len5 = strlen(tmp5);
				monster->monstername5 = new char[len5];
				strcpy(monster->monstername5, tmp5);

				monster->CallbackFucSelector = root["monster"][i]["case"].asInt();
				monster->monstersize = root["monster"][i]["size"].asInt();
				monster->monster_ATK = root["monster"][i]["atk"].asInt();
				monster->monster_DEF = root["monster"][i]["def"].asInt();
				monster->monster_HP = root["monster"][i]["hp"].asInt();
				monster->hero_atk_change = root["monster"][i]["atk_change"].asInt();
				monster->hero_def_change = root["monster"][i]["def_change"].asInt();
				monster->hero_hp_change = root["monster"][i]["hp_change"].asInt();
				monster->hero_money_change = root["monster"][i]["money_change"].asInt();
				x = root["monster"][i]["posx"].asInt();
				y = root["monster"][i]["posy"].asInt();
				monster->monsterPosition = Vec2(x, y);
				monster->bindHero(hero);
				Monster.push_back(monster);

			}


		}


		for (int i = 0; i < Monster.size(); i++)
		{
			this->addChild(Monster[i]);
		}
		Sprite* sprite3 = Sprite::create("hero1.png");
		sprite3->setPosition(790, 615);
		this->addChild(sprite3);
		Sprite* sprite1 = Sprite::create("herolabel.png");
		sprite1->setPosition(850, 500);
		this->addChild(sprite1);





		label[1] = Label::create(String::createWithFormat("%d", hero->hero_ATK)->getCString(), "Arial", 25);
		label[2] = Label::create(String::createWithFormat("%d", hero->hero_DEF)->getCString(), "Arial", 25);
		label[0] = Label::create(String::createWithFormat("%d", hero->hero_HP)->getCString(), "Arial", 25);
		label[3] = Label::create(String::createWithFormat("%d", hero->hero_money)->getCString(), "Arial", 25);
		for (int i = 0; i < 4; i++)
		{
			label[i]->setAnchorPoint(Vec2(0, 0));
			label[i]->setPosition(822, 546 - i * 39);
			addChild(label[i], 12);
		}


		auto listenerKeyboard = EventListenerKeyboard::create();
		listenerKeyboard->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
			keys[keyCode] = true;
		};
		listenerKeyboard->onKeyReleased = [=](EventKeyboard::KeyCode keycode, Event* event) {
			keys[keycode] = false;
		};
		_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerKeyboard, this);
		this->schedule(schedule_selector(Game_scene3::mupdate), 0.09f);

		this->scheduleUpdate();
		return true;

	}






bool Game_scene2::init()
{

	if (!Layer::init())
	{
		return false;
	}


	Point origin = Director::getInstance()->getVisibleOrigin();
	Size size = Director::getInstance()->getVisibleSize();
	map = TMXTiledMap::create("map2.tmx");
	map->setPosition(0, 0);
	addChild(map);
	meta = map->layerNamed("layer3");
	auto* map2 = TMXTiledMap::create("Layer.tmx");
	map2->setPosition(750, 0);
	addChild(map2);
	do
	{
		hero = Hero::create();
		hero->retain();
		hero->hero1 = Sprite::create("hero1.png");

		hero->hero2 = Sprite::create("hero2.png");

		hero->hero3 = Sprite::create("hero3.png");

		hero->hero4 = Sprite::create("hero4.png");

	} while (0);

	Json::Reader reader0;
	Json::Value root0;
	std::ifstream file0("hero.json");
	file0.seekg(0, file0.end);
	int length0 = file0.tellg();
	file0.seekg(0, file0.beg);
	char *cache0 = new char[length0];
	file0.read(cache0, length0);
	std::string data0 = cache0;
	delete[] cache0;
	if (reader0.parse(data0, root0, false) == true)
	{
		hero->hero_ATK = root0["atk"].asInt();
		hero->hero_DEF = root0["def"].asInt();
		hero->hero_HP = root0["hp"].asInt();
		hero->hero1->setPositionX(root0["posx"].asInt());
		hero->hero1->setPositionY(root0["posy"].asInt());
		hero->hero2->setPositionX(root0["posx"].asInt());
		hero->hero2->setPositionY(root0["posy"].asInt());
		hero->hero3->setPositionX(root0["posx"].asInt());
		hero->hero3->setPositionY(root0["posy"].asInt());
		hero->hero4->setPositionX(root0["posx"].asInt());
		hero->hero4->setPositionY(root0["posy"].asInt());
	}


	hero->hero1->setOpacity(255);

	hero->hero2->setOpacity(0);

	hero->hero3->setOpacity(0);

	hero->hero4->setOpacity(0);
	map->addChild(hero->hero1, 5);
	map->addChild(hero->hero2, 5);
	map->addChild(hero->hero3, 5);
	map->addChild(hero->hero4, 5);



	auto* louti1 = Sprite::create("louti1.png");
	louti1->setPosition(75, 75);
	map->addChild(louti1);
	auto* louti2 = Sprite::create("louti2.png");
	louti2->setPosition(375, 675);
	map->addChild(louti2);

	Sprite* sprite4 = Sprite::create("herolabel.png");
	sprite4->setPosition(850, 115);
	this->addChild(sprite4);

	if (!Monster.empty())
	{
		Monster.clear();
	}

	Json::Reader reader;
	Json::Value root;

	std::ifstream file("floor2_monster.json");
	file.seekg(0, file.end);
	int length = file.tellg();
	file.seekg(0, file.beg);
	char *cache = new char[length];
	file.read(cache, length);
	std::string data = cache;
	delete[] cache;

	cocos2d::log(data.c_str());
	if (reader.parse(data, root, false) == true)
	{

		int iNum = root["monster"].size();
		for (int i = 0; i < iNum; i++)
		{
			monsterMG* monster = monsterMG::create();

			int x, y;

			char* tmp1 = root["monster"][i]["name1"].asCString();
			int len1 = strlen(tmp1);
			monster->monstername1 = new char[len1];
			strcpy(monster->monstername1, tmp1);

			char* tmp2 = root["monster"][i]["name2"].asCString();
			int len2 = strlen(tmp2);
			monster->monstername2 = new char[len2];
			strcpy(monster->monstername2, tmp2);

			char* tmp3 = root["monster"][i]["name3"].asCString();
			int len3 = strlen(tmp3);
			monster->monstername3 = new char[len3];
			strcpy(monster->monstername3, tmp3);

			char* tmp4 = root["monster"][i]["name4"].asCString();
			int len4 = strlen(tmp4);
			monster->monstername4 = new char[len4];
			strcpy(monster->monstername4, tmp4);

			char* tmp5 = root["monster"][i]["name5"].asCString();
			int len5 = strlen(tmp5);
			monster->monstername5 = new char[len5];
			strcpy(monster->monstername5, tmp5);

			monster->CallbackFucSelector = root["monster"][i]["case"].asInt();
			monster->monstersize = root["monster"][i]["size"].asInt();
			monster->monster_ATK = root["monster"][i]["atk"].asInt();
			monster->monster_DEF = root["monster"][i]["def"].asInt();
			monster->monster_HP = root["monster"][i]["hp"].asInt();
			monster->hero_atk_change = root["monster"][i]["atk_change"].asInt();
			monster->hero_def_change = root["monster"][i]["def_change"].asInt();
			monster->hero_hp_change = root["monster"][i]["hp_change"].asInt();
			monster->hero_money_change = root["monster"][i]["money_change"].asInt();
			x = root["monster"][i]["posx"].asInt();
			y = root["monster"][i]["posy"].asInt();
			monster->monsterPosition = Vec2(x, y);
			monster->bindHero(hero);
			Monster.push_back(monster);

		}


	}


	for (int i = 0; i < Monster.size(); i++)
	{
		this->addChild(Monster[i]);
	}
	Sprite* sprite3 = Sprite::create("hero1.png");
	sprite3->setPosition(790, 615);
	this->addChild(sprite3);
	Sprite* sprite1 = Sprite::create("herolabel.png");
	sprite1->setPosition(850, 500);
	this->addChild(sprite1);





	label[1] = Label::create(String::createWithFormat("%d", hero->hero_ATK)->getCString(), "Arial", 25);
	label[2] = Label::create(String::createWithFormat("%d", hero->hero_DEF)->getCString(), "Arial", 25);
	label[0] = Label::create(String::createWithFormat("%d", hero->hero_HP)->getCString(), "Arial", 25);
	label[3] = Label::create(String::createWithFormat("%d", hero->hero_money)->getCString(), "Arial", 25);
	for (int i = 0; i < 4; i++)
	{
		label[i]->setAnchorPoint(Vec2(0, 0));
		label[i]->setPosition(822, 546 - i * 39);
		addChild(label[i], 12);
	}


	auto listenerKeyboard = EventListenerKeyboard::create();
	listenerKeyboard->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
		keys[keyCode] = true;
	};
	listenerKeyboard->onKeyReleased = [=](EventKeyboard::KeyCode keycode, Event* event) {
		keys[keycode] = false;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerKeyboard, this);
	this->schedule(schedule_selector(Game_scene3::mupdate), 0.09f);

	this->scheduleUpdate();
		
	return true;
}

bool Game_scene3::init()
{

	if (!Layer::init())
	{
		return false;
	}


	Point origin = Director::getInstance()->getVisibleOrigin();
	Size size = Director::getInstance()->getVisibleSize();
	map = TMXTiledMap::create("map5.tmx");
	map->setPosition(0, 0);
	addChild(map);
	meta = map->layerNamed("layer3");
	auto* map2 = TMXTiledMap::create("Layer.tmx");
	map2->setPosition(750, 0);
	addChild(map2);
	do
	{
		hero = Hero::create();
		hero->retain();
		hero->hero1 = Sprite::create("hero1.png");

		hero->hero2 = Sprite::create("hero2.png");

		hero->hero3 = Sprite::create("hero3.png");

		hero->hero4 = Sprite::create("hero4.png");

	} while (0);

	Json::Reader reader0;
	Json::Value root0;
	std::ifstream file0("hero.json");
	file0.seekg(0, file0.end);
	int length0 = file0.tellg();
	file0.seekg(0, file0.beg);
	char *cache0 = new char[length0];
	file0.read(cache0, length0);
	std::string data0 = cache0;
	delete[] cache0;
	if (reader0.parse(data0, root0, false) == true)
	{
		hero->hero_ATK = root0["atk"].asInt();
		hero->hero_DEF = root0["def"].asInt();
		hero->hero_HP = root0["hp"].asInt();
		hero->hero1->setPositionX(root0["posx"].asInt());
		hero->hero1->setPositionY(root0["posy"].asInt());
		hero->hero2->setPositionX(root0["posx"].asInt());
		hero->hero2->setPositionY(root0["posy"].asInt());
		hero->hero3->setPositionX(root0["posx"].asInt());
		hero->hero3->setPositionY(root0["posy"].asInt());
		hero->hero4->setPositionX(root0["posx"].asInt());
		hero->hero4->setPositionY(root0["posy"].asInt());
	}


	hero->hero1->setOpacity(255);

	hero->hero2->setOpacity(0);

	hero->hero3->setOpacity(0);

	hero->hero4->setOpacity(0);
	map->addChild(hero->hero1, 5);
	map->addChild(hero->hero2, 5);
	map->addChild(hero->hero3, 5);
	map->addChild(hero->hero4, 5);



	auto* louti1 = Sprite::create("louti2.png");
	louti1->setPosition(75, 75);
	map->addChild(louti1);

	Sprite* sprite4 = Sprite::create("herolabel.png");
	sprite4->setPosition(850, 115);
	this->addChild(sprite4);

	if (!Monster.empty())
	{
		Monster.clear();
	}

	Json::Reader reader;
	Json::Value root;

	std::ifstream file("floor3_monster.json");
	file.seekg(0, file.end);
	int length = file.tellg();
	file.seekg(0, file.beg);
	char *cache = new char[length];
	file.read(cache, length);
	std::string data = cache;
	delete[] cache;

	cocos2d::log(data.c_str());
	if (reader.parse(data, root, false) == true)
	{

		int iNum = root["monster"].size();
		for (int i = 0; i < iNum; i++)
		{
			monsterMG* monster = monsterMG::create();

			int x, y;

			char* tmp1 = root["monster"][i]["name1"].asCString();
			int len1 = strlen(tmp1);
			monster->monstername1 = new char[len1];
			strcpy(monster->monstername1, tmp1);

			char* tmp2 = root["monster"][i]["name2"].asCString();
			int len2 = strlen(tmp2);
			monster->monstername2 = new char[len2];
			strcpy(monster->monstername2, tmp2);

			char* tmp3 = root["monster"][i]["name3"].asCString();
			int len3 = strlen(tmp3);
			monster->monstername3 = new char[len3];
			strcpy(monster->monstername3, tmp3);

			char* tmp4 = root["monster"][i]["name4"].asCString();
			int len4 = strlen(tmp4);
			monster->monstername4 = new char[len4];
			strcpy(monster->monstername4, tmp4);

			char* tmp5 = root["monster"][i]["name5"].asCString();
			int len5 = strlen(tmp5);
			monster->monstername5 = new char[len5];
			strcpy(monster->monstername5, tmp5);

			monster->CallbackFucSelector = root["monster"][i]["case"].asInt();
			monster->monstersize = root["monster"][i]["size"].asInt();
			monster->monster_ATK = root["monster"][i]["atk"].asInt();
			monster->monster_DEF = root["monster"][i]["def"].asInt();
			monster->monster_HP = root["monster"][i]["hp"].asInt();
			monster->hero_atk_change = root["monster"][i]["atk_change"].asInt();
			monster->hero_def_change = root["monster"][i]["def_change"].asInt();
			monster->hero_hp_change = root["monster"][i]["hp_change"].asInt();
			monster->hero_money_change = root["monster"][i]["money_change"].asInt();
			x = root["monster"][i]["posx"].asInt();
			y = root["monster"][i]["posy"].asInt();
			monster->monsterPosition = Vec2(x, y);
			monster->bindHero(hero);
			Monster.push_back(monster);

		}


	}


	for (int i = 0; i < Monster.size(); i++)
	{
		this->addChild(Monster[i]);
	}
	Sprite* sprite3 = Sprite::create("hero1.png");
	sprite3->setPosition(790, 615);
	this->addChild(sprite3);
	Sprite* sprite1 = Sprite::create("herolabel.png");
	sprite1->setPosition(850, 500);
	this->addChild(sprite1);





	label[1] = Label::create(String::createWithFormat("%d", hero->hero_ATK)->getCString(), "Arial", 25);
	label[2] = Label::create(String::createWithFormat("%d", hero->hero_DEF)->getCString(), "Arial", 25);
	label[0] = Label::create(String::createWithFormat("%d", hero->hero_HP)->getCString(), "Arial", 25);
	label[3] = Label::create(String::createWithFormat("%d", hero->hero_money)->getCString(), "Arial", 25);
	for (int i = 0; i < 4; i++)
	{
		label[i]->setAnchorPoint(Vec2(0, 0));
		label[i]->setPosition(822, 546 - i * 39);
		addChild(label[i], 12);
	}


	auto listenerKeyboard = EventListenerKeyboard::create();
	listenerKeyboard->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
		keys[keyCode] = true;
	};
	listenerKeyboard->onKeyReleased = [=](EventKeyboard::KeyCode keycode, Event* event) {
		keys[keycode] = false;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerKeyboard, this);
	this->schedule(schedule_selector(Game_scene3::mupdate), 0.09f);

	this->scheduleUpdate();
	
	return true;
}
bool Game_scene::isKeyPressed(EventKeyboard::KeyCode keyCode)
{
	if (keys[keyCode])
	{
		return true;
	}
	else
	{
		return false;
	}
}
