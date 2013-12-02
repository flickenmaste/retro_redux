//Last Edit 11/13/2013
//Will Gilstrap
/////////////////////
#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Vector2.h"
#include "Sprite.h"
#include "Player.h"
#include "Bullets.h"

class Enemy: public Sprite
{
public:
	int EScores;
	void SpawnEnemy(Enemy& obj);
	static void ResetEnemy(Enemy& obj);
	void SpawnEnemySide(Enemy& obj);
	void ResetEnemySide(Enemy& obj);
	void EnemyShoot(EBullet& obj, Enemy& enemy);
	void EnemyShoot(EBullet enemyHell[], Enemy &enemy3);
	void EnemyPattern(Enemy& enemyB2);
	static void CheckEnemyCollision(Enemy& enemy, Enemy& enemy2, Enemy& enemy3, PBullet& playerBullet, PBullet& playerBullet2, PBullet& playerBullet3, Player& player);
	static void CheckEnemyCollision(PBullet& playerBullet, PBullet& playerBullet2, PBullet& playerBullet3, Player& player);
	Enemy() { this->m_vPosition.SetX(0); this->m_vPosition.SetY(0); this->m_vSpeed.SetX(0); this->m_vSpeed.SetY(1); this->m_iSpriteID = -1; this->SetWidth(50); this->SetHeight(50); };
};

#endif