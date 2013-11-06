//Last Edit 11/6/2013
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
	void SpawnEnemy(Enemy& obj);
	void ResetEnemy(Enemy& obj);
	void SpawnEnemySide(Enemy& obj);
	void ResetEnemySide(Enemy& obj);
	void EnemyShoot(EBullet& obj, Enemy& enemy);
	void EnemyShoot(int x, int y);
	void CheckEnemyCollision(Enemy& enemy, Enemy& enemy2, Enemy& enemy3, PBullet& playerBullet, PBullet& playerBullet2, PBullet& playerBullet3, Player& player);
};

#endif