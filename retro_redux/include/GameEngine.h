//Last Edit 11/6/2013
//Will Gilstrap
/////////////////////
#ifndef _GAMEENGINE_H_
#define _GAMEENGINE_H_

#include "Sprite.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullets.h"

class Engine
{
public:
	void (Engine::*Process)(int &tick, Sprite &splash, unsigned int &bgMenu);
	void RunEngine();
	void InitGame(EBullet * enemyHell[], unsigned int& bgImage, unsigned int& bgGameOver, Player& player1, PBullet& playerBullet, 
	PBullet& playerBullet2, PBullet& playerBullet3, Enemy& enemy, Enemy& enemy2,
	Enemy& enemy3, Enemy& boss, Enemy& enemyB1, Enemy& enemyB2, EBullet& enemyBullet);
	void InitVars();

	void InitMenu();
	void MenuState(int &tick, Sprite &splash, unsigned int &bgMenu);

	// Gets
	int GetScreenX() {return m_SCREEN_X;}
	int GetScreenY() {return m_SCREEN_Y;}
	Engine() { }
private:
	static const int m_SCREEN_X = 1280;
	static const int m_SCREEN_Y = 780;

};

class Menu: public Engine
{
public:
	//Menu state
	void InitMenu();
	void UpdateMenu();
	void DrawMenu(int &tick, Sprite &splash, unsigned int &bgMenu);
	void DestroyMenu(Sprite &splash, unsigned int &bgMenu);
};

#endif