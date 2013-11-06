//Last Edit 11/5/2013
//Will Gilstrap
/////////////////////
#ifndef _BULLETS_H_
#define _BULLETS_H_

#include "Sprite.h"

class Bullet: public Sprite
{
public:
	bool alive;
	bool dead;
};

class PBullet: public Bullet
{

};

class EBullet: public Bullet
{

};

#endif