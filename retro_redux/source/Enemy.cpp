//Last Edit 11/12/2013
//Will Gilstrap
/////////////////////
#include <stdlib.h>
#include "AIE.h"
#include "GameEngine.h"
#include "Enemy.h"
#include "Collision.h"

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


void Enemy::CheckEnemyCollision(Enemy& enemy, Enemy& enemy2, Enemy& enemy3, PBullet& playerBullet, PBullet& playerBullet2, PBullet& playerBullet3, Player& player)
{
	Player p;
	if (playerBullet.dead == true && playerBullet2.dead == true && playerBullet3.dead == true)
		p.IfDead(playerBullet, playerBullet2, playerBullet3, player);

	if (Collision::CheckCollision(enemy, playerBullet) == true || Collision::CheckCollision(enemy, playerBullet2) == true || Collision::CheckCollision(enemy, playerBullet3) == true)
	{
		//scores++;
		//checkKilled++;
		Enemy::ResetEnemy(enemy);
	}

	if (Collision::CheckCollision(enemy2, playerBullet) == true || Collision::CheckCollision(enemy2, playerBullet2) == true || Collision::CheckCollision(enemy2, playerBullet3) == true)
	{
		//scores++;
		//checkKilled++;
		Enemy::ResetEnemy(enemy2);
	}

	if (Collision::CheckCollision(enemy3, playerBullet) == true || Collision::CheckCollision(enemy3, playerBullet2) == true || Collision::CheckCollision(enemy3, playerBullet3) == true)
	{
		//scores++;
		//checkKilled++;
		Enemy::ResetEnemy(enemy3);
	}
}
