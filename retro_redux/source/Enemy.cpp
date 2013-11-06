//Last Edit 11/5/2013
//Will Gilstrap
/////////////////////
#include <stdlib.h>
#include "AIE.h"
#include "GameEngine.h"
#include "Enemy.h"

static const int SCREEN_X = 1280;
static const int SCREEN_Y = 780;

void Enemy::SpawnEnemy(Enemy& obj)	// function to spawn a basic enemy
{
	int spawn = rand() % SCREEN_X;
	if (obj.GetPos().GetY() > SCREEN_Y)
	obj.GetPos().SetX(spawn);
	if (obj.GetPos().GetY() > SCREEN_Y)
	obj.GetPos().SetY(0);
	else {
	int y = obj.GetPos().GetY();
	y += obj.m_vSpeed.GetY();

	obj.GetPos().SetY(y);
	}
}

void Enemy::ResetEnemy(Enemy& obj)
{
	int spawn = rand() % SCREEN_X;
	obj.GetPos().SetX(spawn);
	obj.GetPos().SetY(0);
}

void Enemy::SpawnEnemySide(Enemy& obj)	// function to spawn a basic enemy
{
	int spawn = rand() % SCREEN_X;
	

	int spawnSide = 0;


	if (obj.GetPos().GetX() >= 640)
	{
		int x = obj.GetPos().GetX();
		x -= 1;
		int y = obj.GetPos().GetY();
		y += obj.m_vSpeed.GetY();

		obj.GetPos().SetX(x);
		obj.GetPos().SetY(y);
	}
	
	if (obj.GetPos().GetX() <= 640)
	{
		int x = obj.GetPos().GetX();
		x += 1;
		int y = obj.GetPos().GetY();
		y += obj.m_vSpeed.GetY();

		obj.GetPos().SetX(x);
		obj.GetPos().SetY(y);
	}

	if (obj.GetPos().GetY() > SCREEN_Y / 2)
	{
		int y = obj.GetPos().GetY();
		y += obj.m_vSpeed.GetY();

		obj.GetPos().SetY(y);
	}

	if (obj.GetPos().GetY() > SCREEN_Y)
		ResetEnemySide(obj);

}

void Enemy::ResetEnemySide(Enemy& obj)
{
	int spawn = rand() % SCREEN_X;

	obj.GetPos().SetX(spawn);
	obj.GetPos().SetY(0);
}

void Enemy::EnemyShoot(EBullet& obj, Enemy& enemy)
{
	float speed = 2;

	if (obj.GetPos().GetY() <= 0)
	{
		obj.GetPos().SetX(enemy.GetPos().GetX());
		obj.GetPos().SetY(enemy.GetPos().GetY());
	}

	if (obj.GetPos().GetY() >= 780)
	{
		obj.GetPos().SetX(enemy.GetPos().GetX());
		obj.GetPos().SetY(enemy.GetPos().GetY());
	}
	
	float moveSpeed = obj.GetPos().GetY(); 
	moveSpeed += speed;
	obj.GetPos().SetY(moveSpeed);
}