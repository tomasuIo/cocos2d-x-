#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_
#include "cocos2d.h"
#include "Hero.h"
#include "Monstermanager.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "json\writer.h"
#include "json\reader.h"
#include "json\value.h"
#include <vector>
#include "help_scene.h"
class Game_scene : public cocos2d::Layer
{
public:
	cocos2d::TMXTiledMap* map;
	cocos2d::TMXLayer* meta;
	Hero* hero;
	Label*  label[8];
	int memory[8];
	virtual void update(float dt);
	
	std::vector<monsterMG*>  Monster;
	void up(cocos2d::Object* pSender);
	void down(cocos2d::Object* pSender);
	void right(cocos2d::Object* pSender);
	void left(cocos2d::Object* pSender);
	bool isCanReach(float x, float y);
	virtual bool init();
	void mupdate(float dt);
	bool isKeyPressed(EventKeyboard::KeyCode keyCode);
	CREATE_FUNC(Game_scene);
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;
	~Game_scene() {
	}
};


class Game_scene1 : public Game_scene
{
public:
	static cocos2d::Scene* createScene();
	virtual void update(float dt);
	virtual bool init();

	CREATE_FUNC(Game_scene1);
};
class Game_scene2 : public Game_scene
{
public:
	static cocos2d::Scene* createScene();
	virtual void update(float dt);
	virtual bool init();

	CREATE_FUNC(Game_scene2);
};
class Game_scene3 : public Game_scene
{
public:
	static cocos2d::Scene* createScene();
	virtual void update(float dt);
	virtual bool init();
	
	CREATE_FUNC(Game_scene3);
private:
	
};



#endif // !_GAME_SCENE_H