//Last Edit 11/5/2013
//Will Gilstrap
/////////////////////
#ifndef _COLLISION_H_
#define _COLLISION_H_

#include "Sprite.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullets.h"

class Collision
{
public:
	bool checkCollision(Enemy& obj1, PBullet& obj2);
	bool checkCollision(Enemy& obj1, Player& obj2);
	bool checkCollision(Player& obj1, EBullet& obj2);
};


#endif