//Last Edit 11/4/2013
//Will Gilstrap
/////////////////////
#include "AIE.h"
#include "GameEngine.h"
#include "Player.h"

static const int SCREEN_X = 1280;
static const int SCREEN_Y = 780;


void Player::SeekX(Player& player, Player& mouse) // code to make the player sprite follow behind mouse
{
	float speed = 1;
	float x = player.m_vPosition.GetX();

	if(player.m_vPosition.GetX() < mouse.m_vPosition.GetX() - speed) {
		int diff = mouse.m_vPosition.GetX() - player.m_vPosition.GetX();
		if(diff > speed) {
			x += speed;
			player.m_vPosition.SetX(x);
		}
		else {
			x += diff;
			player.m_vPosition.SetX(x);
		}
	}
	else if (player.m_vPosition.GetX() > mouse.m_vPosition.GetX() + speed) {
		int diff = player.m_vPosition.GetX() - mouse.m_vPosition.GetX();
		if(diff > speed) {
			x -= speed;
			player.m_vPosition.SetX(x);
		}
		else {
			x -= diff;
			player.m_vPosition.SetX(x);
		}
}
}

void Player::SeekY(Player& player, Player& mouse) // code to make the player sprite follow behind mouse
{
	float speed = 1;
	float y = player.m_vPosition.GetY();

	if(player.m_vPosition.GetY() < mouse.m_vPosition.GetY() - speed) {
		int diff = mouse.m_vPosition.GetY() - player.m_vPosition.GetY();
		if(diff > speed) {
			y += speed;
			player.m_vPosition.SetY(y);
		}
		else {
			y += diff;
			player.m_vPosition.SetY(y);
		}
	}
	else if (player.m_vPosition.GetY() > mouse.m_vPosition.GetY() + speed) {
		int diff = player.m_vPosition.GetY() - mouse.m_vPosition.GetY();
		if(diff > speed) {
			y -= speed;
			player.m_vPosition.SetY(y);
		}
		else {
			y -= diff;
			player.m_vPosition.SetY(y);
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
	mouse.m_vPosition.SetX(x);
	mouse.m_vPosition.SetY(y);
	mouse.m_vSpeed.SetX(0);
	mouse.m_vSpeed.SetY(0);
	mouse.SetSpriteID();
	mouse.SetWidth(50);
	mouse.SetHeight(50);

	if (x <= SCREEN_X) // to keep player going off screen
		SeekX(obj, mouse);
	if (y <= SCREEN_Y)	// to keep player going off screen
		SeekY(obj, mouse);
	MoveSprite(obj.GetSpriteID(), obj.m_vPosition.GetX(), obj.m_vPosition.GetY());
	return;
}