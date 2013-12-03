//Last Edit 11/6/2013
//Will Gilstrap
/////////////////////
#ifndef _COLLISION_H_
#define _COLLISION_H_

#include "Player.h"
#include "Enemy.h"
#include "Bullets.h"

class Collision
{
public:
	static bool CheckCollision(Enemy& obj1, PBullet& obj2);
	static bool CheckCollision(Enemy& obj1, Player& obj2);
	static bool CheckCollision(Player& obj1, EBullet& obj2);
	static bool CheckCollision(Player& obj1, EBullet enemyHell[]);
};


#endif