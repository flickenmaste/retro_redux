//Last Edit 11/13/2013
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

void Enemy::ResetEnemySide(Enemy& obj) // reset enemy side
{
	int spawn = rand() % SCREEN_X;

	obj.GetPos().SetX(spawn);
	obj.GetPos().SetY(0);
}

void Enemy::EnemyShoot(EBullet& obj, Enemy& enemy) // enemy shoot
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

void Enemy::EnemyShoot(EBullet enemyHell[], Enemy &enemy3)
{
	float speed = 2;
	float sideShot = -5;
	int side = sideShot;
	int speedd = speed;
	for (int i = 0; i < 10; i++)
	{
	if (enemyHell[i].GetPos().GetY() <= 0)
	{
		enemyHell[i].GetPos().SetX(enemy3.GetPos().GetX());
		enemyHell[i].GetPos().SetY(enemy3.GetPos().GetY());
	}

	if (enemyHell[i].GetPos().GetY() >= 780)
	{
		enemyHell[i].GetPos().SetX(enemy3.GetPos().GetX());
		enemyHell[i].GetPos().SetY(enemy3.GetPos().GetY());
	}
	
	side += sideShot;
	speedd += speed;

	enemyHell[i].GetPos().SetX(side);
	enemyHell[i].GetPos().SetY(speedd);
	sideShot++;
	}
}

void Enemy::CheckEnemyCollision(Enemy& enemy, Enemy& enemy2, Enemy& enemy3, PBullet& playerBullet, PBullet& playerBullet2, PBullet& playerBullet3, Player& player) // check collision of enemys
{
	Engine e;
	if (playerBullet.dead == true && playerBullet2.dead == true && playerBullet3.dead == true)
		player.IfDead(playerBullet, playerBullet2, playerBullet3, player);

	if (Collision::CheckCollision(enemy, playerBullet)
		|| Collision::CheckCollision(enemy, playerBullet2) 
		|| Collision::CheckCollision(enemy, playerBullet3))
	{
		enemy3.EScores++;
		//checkKilled++;
		enemy.ResetEnemy(enemy);
	}

	if (Collision::CheckCollision(enemy2, playerBullet) == true || Collision::CheckCollision(enemy2, playerBullet2) == true || Collision::CheckCollision(enemy2, playerBullet3) == true)
	{
		enemy3.EScores++;
		//checkKilled++;
		enemy2.ResetEnemy(enemy2);
	}

	if (Collision::CheckCollision(enemy3, playerBullet) == true || Collision::CheckCollision(enemy3, playerBullet2) == true || Collision::CheckCollision(enemy3, playerBullet3) == true)
	{
		enemy3.EScores++;
		//checkKilled++;
		enemy3.ResetEnemy(enemy3);
	}
}

void Enemy::CheckEnemyCollision(PBullet& playerBullet, PBullet& playerBullet2, PBullet& playerBullet3, Player& player) // check collision
{
	if (playerBullet.dead == true && playerBullet2.dead == true && playerBullet3.dead == true)
		player.IfDead(playerBullet, playerBullet2, playerBullet3, player);
}

void Enemy::EnemyPattern(Enemy& enemyB2) // enemy movement for boss
{
	static float angle = 0.0;
	float pi = 3.14;
	angle += 0.01;
	float inc = 0.0;
	float bossPosX = 1280 / 2;
	float bossPosY = 680 / 6;

	float cosWav = (bossPosX) + cosf( angle+inc ) * 200;
	float sinWav = (bossPosY) + sinf( angle+inc ) * 200;

	this->GetPos().SetX(cosWav);
	this->GetPos().SetY(sinWav);
	inc += 2*pi / 2;
	cosWav = (bossPosX) + cosf( angle+inc ) * 200;
	sinWav = (bossPosY) + sinf( angle+inc ) * 200;
	enemyB2.GetPos().SetX(cosWav);
	enemyB2.GetPos().SetY(sinWav);
	MoveSprite(this->GetSpriteID(), this->GetPos().GetX(), this->GetPos().GetY());
	MoveSprite(enemyB2.GetSpriteID(), enemyB2.GetPos().GetX(), enemyB2.GetPos().GetY());
}