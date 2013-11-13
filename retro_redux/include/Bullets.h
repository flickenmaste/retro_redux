//Last Edit 11/12/2013
//Will Gilstrap
/////////////////////
#ifndef _BULLETS_H_
#define _BULLETS_H_

#include "Sprite.h"

class Bullet: public Sprite
{
public:
	bool dead;
};

class PBullet: public Bullet
{
public:
	void PBUpdate();
	void IfAlive();
	void IfAlive2();
	void IfAlive3();
	PBullet() { this->m_vPosition.SetX(0); this->m_vPosition.SetY(0); this->dead = true; this->SetWidth(10); };
};

class EBullet: public Bullet
{

};

#endif