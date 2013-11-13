//Last Edit 11/12/2013
//Will Gilstrap
/////////////////////
#include "AIE.h"
#include "GameEngine.h"
#include "Player.h"
#include  <iostream>

static const int SCREEN_X = 1280;
static const int SCREEN_Y = 780;


void Player::SeekX(Player& mouse) // code to make the player sprite follow behind mouse
{
	float speed = 1;
	float x = GetPos().GetX();

	if(GetPos().GetX() < mouse.GetPos().GetX() - speed) {
		int diff = mouse.GetPos().GetX() - GetPos().GetX();
		if(diff > speed) {
			x += speed;
			GetPos().SetX(x);
		}
		else {
			x += diff;
			GetPos().SetX(x);
		}
	}
	else if (GetPos().GetX() > mouse.GetPos().GetX() + speed) {
		int diff = GetPos().GetX() - mouse.GetPos().GetX();
		if(diff > speed) {
			x -= speed;
			GetPos().SetX(x);
		}
		else {
			x -= diff;
			GetPos().SetX(x);
		}
}
}

void Player::SeekY(Player& mouse) // code to make the player sprite follow behind mouse
{
	float speed = 1;
	float y = GetPos().GetY();

	if(GetPos().GetY() < mouse.GetPos().GetY() - speed) {
		int diff = mouse.GetPos().GetY() - GetPos().GetY();
		if(diff > speed) {
			y += speed;
			GetPos().SetY(y);
		}
		else {
			y += diff;
			GetPos().SetY(y);
		}
	}
	else if (GetPos().GetY() > mouse.GetPos().GetY() + speed) {
		int diff = GetPos().GetY() - mouse.GetPos().GetY();
		if(diff > speed) {
			y -= speed;
			GetPos().SetY(y);
		}
		else {
			y -= diff;
			GetPos().SetY(y);
		}
	}
}

void Player::MovePlayer(Player& obj)	// function to make the player sprite follow mouse
{
	int x; int y;
	GetMouseLocation(x,y);
	//obj.position.x = x;
	//obj.position.y = y;
	Player mouse; //= {x, y, 0, 0, -1 , 50, 50};
	mouse.GetPos().SetX(x);
	mouse.GetPos().SetY(y);
	mouse.m_vSpeed.SetX(0);
	mouse.m_vSpeed.SetY(0);
	//mouse.SetSpriteID(mouse, "./images/player.png", 50, 50);
	mouse.SetWidth(50);
	mouse.SetHeight(50);

	if (x <= SCREEN_X) // to keep player going off screen
		SeekX( mouse);
	if (y <= SCREEN_Y)	// to keep player going off screen
		SeekY( mouse);
	MoveSprite(obj.GetSpriteID(), obj.GetPos().GetX(), obj.GetPos().GetY());
	
	return;
}

void Player::PlayerShoot(PBullet& obj, PBullet& obj2, PBullet& obj3)	// function to test if player is shooting or not
{
	// bullet 1
	if (GetMouseButtonDown(MOUSE_BUTTON_1) == true){
	int x; int y;
	GetMouseLocation(x,y);
	if(obj.dead)
	{
		obj.dead = false;
	}
	if(obj2.dead)
	{
		obj2.dead = false;
	}
	if(obj3.dead)
	{
		obj3.dead = false;
	}

	}
	
}

/*
void Player::IfAlive(PBullet& obj, PBullet& obj2, PBullet& obj3)	// function executed if player is shooting
{

	//bullet 1
	int y1 = obj.GetSpeed().GetY();
	y1 -= obj.GetSpeed().GetY();

	obj.GetPos().SetY(y1);

	//bullet 2
	int x1 = obj2.GetPos().GetX();
	int y2 = obj2.GetSpeed().GetY();
	x1 -= 1;
	y2 -= obj2.GetSpeed().GetY();

	obj2.GetPos().SetX(x1);
	obj2.GetPos().SetY(y2);
	
	//bullet 3
	int x2 = obj2.GetPos().GetX();
	int y3 = obj2.GetSpeed().GetY();
	x2 += 1;
	y3 -= obj2.GetSpeed().GetY();

	obj3.GetPos().SetX(x2);
	obj3.GetPos().SetY(y3);

}
*/


int Player::GetPlayerLocationX(Player& player)
{
	int locX = player.GetPos().GetX();
	return locX;
}

int Player::GetPlayerLocationY(Player& player)
{
	int locY = player.GetPos().GetY();
	return locY;
}

void Player::IfDead(PBullet& obj, PBullet& obj2, PBullet& obj3, Player &player)
{
	if (GetMouseButtonDown(MOUSE_BUTTON_1) == true) {
	// bullet 1
	int x; int y;
	x = GetPlayerLocationX(player); y = GetPlayerLocationY(player);
	//GetMouseLocation(x,y);
	if (obj.GetPos().GetY() < 0)
	obj.GetPos().SetX(x);
	if (obj.GetPos().GetY() < 0)
	obj.GetPos().SetY(y);

	// bullet 2
	if (obj2.GetPos().GetY() < 0 || obj2.GetPos().GetX() < 0)
	obj2.GetPos().SetX(x);
	if (obj2.GetPos().GetY() < 0 || obj2.GetPos().GetY() < 0)
	obj2.GetPos().SetY(y);

	//bullet 3
	if (obj3.GetPos().GetY() < 0)
	obj3.GetPos().SetX(x);
	if (obj3.GetPos().GetY() < 0)
	obj3.GetPos().SetY(y);

	obj.dead = obj2.dead =obj3.dead =true;
	}
}