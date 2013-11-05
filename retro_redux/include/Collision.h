//Last Edit 11/4/2013
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
	bool checkCollision(movableObject& obj1, bullets& obj2);
	bool checkCollision(movableObject& obj1, movableObject& obj2);
	bool checkCollision(movableObject& obj1, enemybullets& obj2);
};


#endif