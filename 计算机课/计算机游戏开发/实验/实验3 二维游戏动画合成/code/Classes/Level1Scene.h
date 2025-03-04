#ifndef __LEVEL1_SCENE_H__
#define __LEVEL1_SCENE_H__

#include "Headers.h"
#include "Config.h"
#include "BasicScene.h"
#include "Joystick.h"
#include "BloodBar.h"
#include "Hero.h"
#include "Tauren.h"
#include "TaurenAI.h"
#include "CollisionDetection.h"

#include "Level2Scene.h"

class BasicScene;

class Level1Scene : public BasicScene {
private:
	Joystick* joystick;

	// Hero
	int heroMaxHP;
	Hero* hero;
	float heroWidth;
	BloodBar* heroBloodBar;

	// Tauren
	int taurenMaxHP;
	Tauren* tauren;
	float taurenWidth;
	BloodBar* taurenBloodBar;
	TaurenAI* taurenAI;
	Sprite* taurenShield;  // Tauren 的盾牌

	// 碰撞检测
	CollisionDetection* collisionDetection;

	// 技能 CD
	int attackCD;
	int defenseCD;

	// 计分板标签
	Label* heroScoreboard;
	Label* taurenScoreboard;

public:
	Level1Scene();

	~Level1Scene();

	static Scene* createScene();

	bool init();

	CREATE_FUNC(Level1Scene);

	void update(float dt);

	// 预加载音乐
	void preloadSounds();

	// 键盘监听的回调函数
	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);

	// 游戏胜利
	void workVictory();

	// 游戏失败
	void workDefeat();

	// 游戏胜负判定
	void gameJudgement();

	// 加载摇杆
	void loadJoystick(std::string joystickPath, std::string joystickButtonPath, float joystickRadius, Point position, int z);

	// 加载 Hero
	void loadHero(int _maxHP, Point position, int z);

	// 加载 Hero 血条
	void loadHeroBloodBar(int _maxHP, int _HP, Point position, int z,
		std::string bloodBarPath, std::string bloodBarBackgroundPath, BloodBarDirection _bloodBarDirection = RIGHT, int tag = -1);

	// 控制 Hero 移动
	void workHeroMovement();

	// 加载 Tauren
	void loadTauren(int _maxHP, Point position, int z);

	// 加载 Tauren 血条
	void loadTaurenBloodBar(int _maxHP, int _HP, Point position, int z,
		std::string bloodBarPath, std::string bloodBarBackgroundPath, BloodBarDirection _bloodBarDirection = RIGHT, int tag = -1);

	// 控制 Tauren 移动
	void workTaurenMovement();

	// 更新血条
	void updateBloodBar();

	// 加载 Hero 计分板
	void loadHeroScoreboard(int score, Point position, int z, int tag = -1);

	// 加载 Tauren 计分板
	void loadTaurenScoreboard(int score, Point position, int z, int tag = -1);

	// 更新 Hero 计分板
	void updateHeroScoreboard(int score);

	// 更新 Tauren 计分板
	void updateTaurenScoreboard(int score);

	// 加载云背景
	void loadCloudBackground(int z, int tag = -1);

	// 更新云背景
	void updateCloudBackground();

	// 更新所有技能的按钮
	void updateSkillButtons();

	// 加载攻击按钮
	void loadAttackButton(Point position, int z, int tag = -1);

	// 攻击按钮的回调函数
	void attackButtonCallback(Ref* pSender);

	// 加载防御按钮
	void loadDefenseButton(Point position, int z, int tag = -1);

	// 防御按钮的回调函数
	void defenseButtonCallback(Ref* pSender);

	// 加载 Tauren 的盾牌
	void loadTaurenShield();

	// 更新 Tauren 的盾牌的位置
	void updateTaurenShieldPosition();
};

#endif