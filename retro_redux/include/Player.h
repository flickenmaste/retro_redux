//Last Edit 11/12/2013
//Will Gilstrap
/////////////////////
#ifndef _PLAYER_H_
#define _PLAYER_H_



#include "Vector2.h"
#include "Sprite.h"
#include "Bullets.h"

class Player: public Sprite
{
public:
	void SeekX(Player& mouse);
	void SeekY(Player& mouse);
	void MovePlayer(Player& obj);
	void PlayerShoot(PBullet& obj, PBullet& obj2, PBullet& obj3);
	//void IfAlive(PBullet& obj, PBullet& obj2, PBullet& obj3);
	int GetPlayerLocationX(Player& player);
	int GetPlayerLocationY(Player& player);
	void IfDead(PBullet& obj, PBullet& obj2, PBullet& obj3, Player &player);	// executed if bullets leave screen
	Player() { this->m_vPosition.SetX(600); this->m_vPosition.SetY(300); this->SetWidth(100); this->SetHeight(50); };
};

#endif