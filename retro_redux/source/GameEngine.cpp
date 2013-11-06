//Last Edit 11/5/2013
//Will Gilstrap
/////////////////////
#include "AIE.H"
#include <iostream>
#include "GameEngine.h"
#include "Sprite.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullets.h"
//#include "GameStates.h"

int frameCounter = 0;

void Engine::RunEngine()
{
	
	std::cout << "Does this work?";

	InitVars();
	InitMenu();
	/*
	Process = &Menu::menuState;	
	do {
		frameCounter++;

		if(frameCounter > 5000)
			frameCounter = 0;
		
		Process();	// function pointer to run game
		
	} while ( FrameworkUpdate() == false );
	*/
}

void Engine::InitVars()
{
	unsigned int bgImage = -1;
	unsigned int bgGameOver = -1;
	Player player1; //= {687, 386, 0, 0, -1 , 100, 50};
	PBullet playerBullet; //= {-100, 0, 0, 4, -1 , 10, 10, false, true};
	PBullet playerBullet2;
	PBullet playerBullet3;
	//PBullet playerBullet2; //= {-100, 0, -4, 4, -1 , 10, 10, false, true};
	//PBullet playerBullet3;//= {-100, 0, -4, 4, -1 , 10, 10, false, true};
	Enemy enemy; //= {-500, 800, 0, 1, -1 , 50, 50};
	Enemy enemy2; //= {-500, 800, 0, 1, -1 , 50, 50};
	Enemy enemy3; //= {0, 0, 0, 1, -1 , 50, 50};
	Enemy boss; //= {GetScreenX() / 2, GetScreenY() / 6, 0, 1, -1 , 100, 100};
	Enemy enemyB1; //= {0, 0, 0, 1, -1 , 50, 50};
	Enemy enemyB2; //= {0, 0, 0, 1, -1 , 50, 50};
	EBullet enemyBullet; //= {600, -10, 0, 4, -1 , 10, 10, false, true};
	bool menuEnd = false;
	EBullet * enemyHell[10];
	EBullet bossShot[10];
	EBullet bossShot2[10];
	EBullet miniShot[2];
	int player1Score = 0;
	//highScore h;
	unsigned int checkKilled = 0;
	float circle = 10;
	int bossHP = 2000;
	int tick = 0;

	InitGame(&enemyHell[10], bgImage, bgGameOver, player1, playerBullet, playerBullet2, playerBullet3, enemy, enemy2, enemy3, boss, enemyB1, enemyB2, enemyBullet);

}

void Engine::InitGame(EBullet * enemyHell[], unsigned int& bgImage, unsigned int& bgGameOver, Player& player1, PBullet& playerBullet, 
	PBullet& playerBullet2, PBullet& playerBullet3, Enemy& enemy, Enemy& enemy2, Enemy& enemy3, Enemy& boss, Enemy& enemyB1, Enemy& enemyB2, EBullet& enemyBullet)
{
	
	bgImage = CreateSprite( "./images/bg.png", GetScreenX(), GetScreenY(), true );
	player1.SetSpriteID(player1, "./images/player.png", 50, 50);
	playerBullet.SetSpriteID(playerBullet, "./images/bullet.png", 10, 10);
	playerBullet2.SetSpriteID(playerBullet, "./images/bullet.png", 10, 10);
	playerBullet3.SetSpriteID(playerBullet, "./images/bullet.png", 10, 10);
	enemy.SetSpriteID(enemy, "./images/enemy.png", 50, 50);
	enemy2.SetSpriteID(enemy2, "./images/enemy.png", 50, 50);
	enemy3.SetSpriteID(enemy3, "./images/enemy.png", 50, 50);
	enemyBullet.SetSpriteID(enemy, "./images/enemybullet.png", 10, 10);
	/*
	for (int i = 0; i < 10; i++)
	{
		enemyHell[i].SetSpriteID(enemyHell, "./images/enemybullet.png", 10, 10, true);
		enemyHell[i].GetPos().SetX(600);
		enemyHell[i].GetPos().SetY(-10);
		enemyHell[i].GetSpeed().SetX(0);
		enemyHell[i].GetSpeed().SetY(4);
		enemyHell[i].SetWidth(10);
		enemyHell[i].SetHeight(10);
	}
	*/
}

void Engine::InitMenu()
{
	Sprite splash;
	unsigned int bgMenu = -1;
	splash.SetSpriteID(splash, "./images/splash.png", GetScreenX(), GetScreenY());
	MoveSprite(splash.GetSpriteID(), GetScreenX()>>1, GetScreenY()>>1);
	bgMenu = CreateSprite( "./images/menu3.jpg", GetScreenX(), GetScreenY(), true );
	MoveSprite(bgMenu, GetScreenX()>>1, GetScreenY()>>1);
	int tick = 0;

	do {
		MenuState(tick, splash, bgMenu);

	} while ( FrameworkUpdate() == false );
}

void Engine::UpdateMenu()
{
	//if (IsKeyDown(32) == true)
		//gameProcess = &playState;
}

void Engine::DrawMenu(int &tick, Sprite &splash, unsigned int &bgMenu)
{

	if (tick <= 1000)
	{
		ClearScreen();
		DrawSprite(splash.GetSpriteID());
		MoveSprite(splash.GetSpriteID(), GetScreenX()>>1, GetScreenY()>>1);
		tick++;
	}
	else
	{
	//DrawSprite(bgMenu);
	DrawString("Menu", GetScreenX() / 2, GetScreenY() / 2, SColour(0,0xFF,0,0));
	DrawString("Press SPACE to play...", GetScreenX() / 2 - 100, GetScreenY() / 2 + 50, SColour(0,255,255,255));
	//DrawString("Exit", SCREEN_X / 2, SCREEN_Y / 2 + 100, SColour(255,4,45,255));
	DrawString("Controls: LEFT MOUSE to shoot", 870, 750, SColour(0,255,0,255));
	DrawSprite(bgMenu);
	}
}

void Engine::DestroyMenu()
{
	//DestroySprite(bgMenu);
}

void Engine::MenuState(int &tick, Sprite &splash, unsigned int &bgMenu)
{
	ClearScreen();
	UpdateMenu();
	DrawMenu(tick, splash, bgMenu);
}