#include "HelloWorldScene.h"

#include "help_scene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* Help_scene::createScene()
{

	auto scene = Scene::create();

	auto layer = Help_scene::create();

	scene->addChild(layer);

	return scene;
}


bool Help_scene::init()
{

	if (!Layer::init())
	{
		return false;
	}
	Size size = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	auto *chnStirngs = Dictionary::createWithContentsOfFile("CHN_Strings.xml");   //解析xml文件，显示汉字

	
	auto background = LayerColor::create(Color4B(0,180,255, 50));
	addChild(background);
	const char* str2 = ((String*)chnStirngs->objectForKey("string5"))->getCString();
	auto label1 = Label::create(str2,"Arial",36);
	label1->setPosition(480, 300);
	addChild(label1);
	auto * pButton1 = MenuItemImage::create("button1.png", "button2.png", CC_CALLBACK_1(Help_scene::popScene, this));
	const char* str1 = ((String*)chnStirngs->objectForKey("string4"))->getCString();
	auto* label = LabelTTF::create(str1, "Arial", 40);
	auto* pLabel = MenuItemLabel::create(label, this, menu_selector(Help_scene::popScene, this));
	auto* button = Menu::create(pButton1,pLabel,NULL);
	button->setAnchorPoint(Vec2(0, 0));
	button->setPosition(480, 100);
	button->setScale(0.6f);
	addChild(button,1);
	return true;
}

void Help_scene::popScene(Ref* pSender)
{
	// 推进场景
	Director::getInstance()->pushScene(HelloWorld::createScene());
}
