//Last Edit 11/18/2013
//Will Gilstrap
/////////////////////
#ifndef _GAMEENGINE_H_
#define _GAMEENGINE_H_

#include "Sprite.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullets.h"
#include "highScores.h"

class Engine
{
public:
	void (Engine::*Process)(int &tick, Sprite &splash, unsigned int &bgMenu);
	void RunEngine();
	
	void RunGame(int &tick, Sprite &splash, unsigned int &bgMenu, EBullet enemyHell[], unsigned int& bgImage, unsigned int& bgGameOver, Player& player1, PBullet& playerBullet, 
	PBullet& playerBullet2, PBullet& playerBullet3, Enemy& enemy, Enemy& enemy2, Enemy& enemy3, Enemy& boss, Enemy& enemyB1, Enemy& enemyB2, EBullet& enemyBullet);

	void InitGame(EBullet enemyHell[], unsigned int& bgImage, unsigned int& bgGameOver, Player& player1, PBullet& playerBullet, 
	PBullet& playerBullet2, PBullet& playerBullet3, Enemy& enemy, Enemy& enemy2,
	Enemy& enemy3, Enemy& boss, Enemy& enemyB1, Enemy& enemyB2, EBullet& enemyBullet);
	void InitVars();

	void InitMenu(EBullet enemyHell[], unsigned int& bgImage, unsigned int& bgGameOver, Player& player1, PBullet& playerBullet, 
	PBullet& playerBullet2, PBullet& playerBullet3, Enemy& enemy, Enemy& enemy2, Enemy& enemy3, Enemy& boss, Enemy& enemyB1, Enemy& enemyB2, EBullet& enemyBullet);
	void MenuState(int &tick, Sprite &splash, unsigned int &bgMenu);
	
	void PlayState(EBullet enemyHell[], unsigned int& bgImage, unsigned int& bgGameOver, Player& player1, PBullet& playerBullet, 
	PBullet& playerBullet2, PBullet& playerBullet3, Enemy& enemy, Enemy& enemy2, Enemy& enemy3, Enemy& boss, Enemy& enemyB1, Enemy& enemyB2, EBullet& enemyBullet);

	void InitBoss(int &tick, Sprite &splash, unsigned int &bgMenu, EBullet enemyHell[], unsigned int& bgImage, unsigned int& bgGameOver, Player& player1, PBullet& playerBullet, 
	PBullet& playerBullet2, PBullet& playerBullet3, Enemy& enemy, Enemy& enemy2, Enemy& enemy3, Enemy& boss, Enemy& enemyB1, Enemy& enemyB2, EBullet& enemyBullet);
	void BossState(unsigned int& bgImage, Player& player1, PBullet& playerBullet, 
	PBullet& playerBullet2, PBullet& playerBullet3, Enemy& boss, Enemy& enemyB1, Enemy& enemyB2);

	void WriteHS();

	// Gets
	int GetScreenX() {return m_SCREEN_X;}
	int GetScreenY() {return m_SCREEN_Y;}
	//int GetScore() {return m_iScores;}
	//int GetScoreP() {return m_iScores++;}
	Engine() { }

	// Sets
	//void SetScore(int a_score) {this->m_iScores = a_score;}

private:
	static const int m_SCREEN_X = 1280;
	static const int m_SCREEN_Y = 780;
	unsigned int m_iScores;

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

class Play: public Engine
{
public:
	void UpdateGame(EBullet enemyHell[], unsigned int& bgImage, unsigned int& bgGameOver, Player& player1, PBullet& playerBullet, 
	PBullet& playerBullet2, PBullet& playerBullet3, Enemy& enemy, Enemy& enemy2, Enemy& enemy3, Enemy& boss, Enemy& enemyB1, Enemy& enemyB2, EBullet& enemyBullet);
	void DrawGame(EBullet enemyHell[], unsigned int& bgImage, unsigned int& bgGameOver, Player& player1, PBullet& playerBullet, 
	PBullet& playerBullet2, PBullet& playerBullet3, Enemy& enemy, Enemy& enemy2, Enemy& enemy3, Enemy& boss, Enemy& enemyB1, Enemy& enemyB2, EBullet& enemyBullet);
};

class GameOver: public Engine
{
public:
	unsigned int GameO;
	void UpdateGO();
};

class Boss: public Engine
{
public:
	void UpdateBoss(unsigned int& bgImage, Player& player1, PBullet& playerBullet, 
	PBullet& playerBullet2, PBullet& playerBullet3, Enemy& boss, Enemy& enemyB1, Enemy& enemyB2);
	void DrawBoss(unsigned int& bgImage, Player& player1, PBullet& playerBullet, 
	PBullet& playerBullet2, PBullet& playerBullet3, Enemy& boss, Enemy& enemyB1, Enemy& enemyB2);
};

#endif