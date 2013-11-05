//Last Edit 11/4/2013
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

};

#endif