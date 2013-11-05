//Last Edit 11/4/2013
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
	void EnemyShoot(Enemy& obj);
	void EnemyShoot(int x, int y);

};

#endif