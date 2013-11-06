//Last Edit 11/5/2013
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
	void SeekX(Player& player, Player& mouse);
	void SeekY(Player& player, Player& mouse);
	void MovePlayer(Player& obj);
	void PlayerShoot(PBullet& obj, PBullet& obj2, PBullet& obj3);
	void IfAlive(PBullet& obj, PBullet& obj2, PBullet& obj3);
	int GetPlayerLocationX(Player& player);
	int GetPlayerLocationY(Player& player);
	void IfDead(PBullet& obj, PBullet& obj2, PBullet& obj3, Player &player);	// executed if bullets leave screen

};

#endif