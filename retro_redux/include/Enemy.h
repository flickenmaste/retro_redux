//Last Edit 11/5/2013
//Will Gilstrap
/////////////////////
#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Vector2.h"
#include "Sprite.h"
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

};

#endif