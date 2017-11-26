#include "HelloWorldScene.h"
#include "Game_Scene.h"
#include "help_scene.h"
#include "Hero.h"
  
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

//using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    auto scene = Scene::create();
    auto layer = HelloWorld::create();
    scene->addChild(layer);
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

	Size size = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	auto *chnStirngs = Dictionary::createWithContentsOfFile("CHN_Strings.xml");

	auto* background = Sprite::create("mota.png");                   //创建开始场景
	background->setPosition(size.width / 2, size.width / 2-110);
	background->setScale(0.9f);
	addChild(background, 0);
	
	auto* pButton1 = MenuItemImage::create("button1.png", "button2.png", CC_CALLBACK_1(HelloWorld::menuCloseCallback1, this));
	const char *str1 = ((String*)chnStirngs->objectForKey("string2"))->getCString();      //创建开始按钮
	auto* label1 = LabelTTF::create(str1, "Arial", 40);
	auto* pLabel1 = MenuItemLabel::create(label1, this, menu_selector(HelloWorld::menuCloseCallback1, this));
	auto* button1 = Menu::create(pButton1, pLabel1, NULL);
	button1->setAnchorPoint(Vec2(0, 0));
	button1->setPosition(size.width / 2, size.height / 2 - 180);
	button1->setScale(0.6f);
	addChild(button1,1);
	 
	auto* pButton2 = MenuItemImage::create("button1.png", "button1.png", CC_CALLBACK_1(HelloWorld::menuCloseCallback2, this));
	const char *str2 = ((String*)chnStirngs->objectForKey("string3"))->getCString();       //创建帮助按钮
	auto* label2 = LabelTTF::create(str2, "Arial", 40);
	auto* pLabel2 = MenuItemLabel::create(label2, this, menu_selector(HelloWorld::menuCloseCallback2, this));
	auto* button2 = Menu::create(pButton2,pLabel2,NULL);
	button2->setAnchorPoint(Vec2(0, 0));
	button2->setPosition(480, size.height / 2 -240 );
	button2->setScale(0.6f);
	addChild(button2,1);
	return true;
}
/*auto game_scene1 = Game_scene1::createScene();
auto game_scene2 = Game_scene2::createScene();
auto game_scene3 = Game_scene3::createScene();
*/
void HelloWorld::menuCloseCallback1(Ref* pSender)
{
	// 推进场景
	Director::getInstance()->pushScene(Game_scene1::createScene());    //游戏场景1
	//Director::getInstance()->runWithScene(game_scene1);
}

void HelloWorld::menuCloseCallback2(Ref* pSender)
{
	// 推进场景                                                              //帮助场景
	Director::getInstance()->/*pushScene(Help_scene::createScene())*/popScene();
}

