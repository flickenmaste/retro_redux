//Last Edit 12/2/2013
//Will Gilstrap
/////////////////////
#include "AIE.h"
#include "Collision.h"

// check collision of bullet and enemy
bool Collision::CheckCollision(Enemy& obj1, PBullet& obj2) {
	int x; int y;
	GetMouseLocation(x,y);
	double rE = obj1.GetPos().GetX();
	double radiusEnemy = obj1.GetWidth() / 2;

	double rB = obj2.GetPos().GetX();
	double radiusBullet = obj2.GetWidth() / 2;

	double distX = obj1.GetPos().GetX() - obj2.GetPos().GetX();
	double distY = obj1.GetPos().GetY() - obj2.GetPos().GetY();

	double dist = sqrt((distX * distX) + (distY * distY));
	double radii = (radiusEnemy + radiusBullet) * (radiusEnemy + radiusBullet);

	if (dist < radiusEnemy + radiusBullet)
		return true;
	else
		return false;
}
// check collision of enemy and player
bool Collision::CheckCollision(Enemy& obj1, Player& obj2) {
	int x; int y;
	GetMouseLocation(x,y);
	double rE = obj1.GetPos().GetX();
	double radiusEnemy = obj1.GetWidth() / 2;

	double rB = obj2.GetPos().GetX();
	double radiusPlayer = obj2.GetWidth() / 2;

	double distX = obj1.GetPos().GetX() - obj2.GetPos().GetX();
	double distY = obj1.GetPos().GetY() - obj2.GetPos().GetY();

	double dist = sqrt((distX * distX) + (distY * distY));
	double radii = (radiusEnemy + radiusPlayer) * (radiusEnemy + radiusPlayer);

	if (dist < radiusEnemy + radiusPlayer)
		return true;
	else
		return false;
}

bool Collision::CheckCollision(Player& obj1, EBullet& obj2) {
	int x; int y;
	GetMouseLocation(x,y);
	double rE = obj1.GetPos().GetX();
	double radiusEnemy = 5;

	double rB = obj2.GetPos().GetX();
	double radiusBullet = obj2.GetWidth() / 2;

	double distX = obj1.GetPos().GetX() - obj2.GetPos().GetX();
	double distY = obj1.GetPos().GetY() - obj2.GetPos().GetY();

	double dist = sqrt((distX * distX) + (distY * distY));
	double radii = (radiusEnemy + radiusBullet) * (radiusEnemy + radiusBullet);

	if (dist < radiusEnemy + radiusBullet)
		return true;
	else
		return false;
}
/*
bool Collision::CheckCollision(Player& obj1, EBullet enemyHell[])
{

}
*/