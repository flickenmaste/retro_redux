//Last Edit 11/4/2013
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
	if (obj.m_vPosition.GetY() > SCREEN_Y)
	obj.m_vPosition.SetX(spawn);
	if (obj.m_vPosition.GetY() > SCREEN_Y)
	obj.m_vPosition.SetY(0);
	else {
	int y = obj.m_vPosition.GetY();
	y += obj.m_vSpeed.GetY();

	obj.m_vPosition.SetY(y);
	}
}

void Enemy::ResetEnemy(Enemy& obj)
{
	int spawn = rand() % SCREEN_X;
	obj.m_vPosition.SetX(spawn);
	obj.m_vPosition.SetY(0);
}

void Enemy::SpawnEnemySide(Enemy& obj)	// function to spawn a basic enemy
{
	int spawn = rand() % SCREEN_X;
	

	int spawnSide = 0;


	if (obj.m_vPosition.GetX() >= 640)
	{
		int x = obj.m_vPosition.GetX();
		x -= 1;
		int y = obj.m_vPosition.GetY();
		y += obj.m_vSpeed.GetY();

		obj.m_vPosition.SetX(x);
		obj.m_vPosition.SetY(y);
	}
	
	if (obj.m_vPosition.GetX() <= 640)
	{
		int x = obj.m_vPosition.GetX();
		x += 1;
		int y = obj.m_vPosition.GetY();
		y += obj.m_vSpeed.GetY();

		obj.m_vPosition.SetX(x);
		obj.m_vPosition.SetY(y);
	}

	if (obj.m_vPosition.GetY() > SCREEN_Y / 2)
	{
		int y = obj.m_vPosition.GetY();
		y += obj.m_vSpeed.GetY();

		obj.m_vPosition.SetY(y);
	}

	if (obj.m_vPosition.GetY() > SCREEN_Y)
		ResetEnemySide(obj);

}

void Enemy::ResetEnemySide(Enemy& obj)
{
	int spawn = rand() % SCREEN_X;

	obj.m_vPosition.SetX(spawn);
	obj.m_vPosition.SetY(0);
}