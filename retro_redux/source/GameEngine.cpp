//Last Edit 12/2/2013
//Will Gilstrap
/////////////////////
#include "AIE.H"
#include <iostream>
#include <time.h>
#include "GameEngine.h"
#include "Sprite.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullets.h"
#include "Collision.h"

int frameCounter = 0;
int state = 0;
unsigned int scores = 0;
Menu m;
Play p;
GameOver g;
Boss b;
Player pl;
Enemy e;

void Engine::RunEngine()
{
	srand(time(NULL));
	Initialise(GetScreenX(), GetScreenY(), false, "Shoot em up 2");
	InitVars();
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

void Engine::RunGame(int &tick, Sprite &splash, unsigned int &bgMenu, EBullet enemyHell[], unsigned int& bgImage, unsigned int& bgGameOver, Player& player1, PBullet& playerBullet, 
	PBullet& playerBullet2, PBullet& playerBullet3, Enemy& enemy, Enemy& enemy2, Enemy& enemy3, Enemy& boss, Enemy& enemyB1, Enemy& enemyB2, EBullet& enemyBullet)
{
	state = 1;
	
	do {
		switch(state)
		{
		case 1: m.MenuState(tick, splash, bgMenu);
				break;
		case 2: p.PlayState(enemyHell, bgImage, bgGameOver, player1, playerBullet, playerBullet2, playerBullet3, enemy, enemy2, enemy3, boss, enemyB1, enemyB2, enemyBullet);
				break;
		case 3: g.UpdateGO();
				break;
		case 4: b.BossState(bgImage, player1, playerBullet, playerBullet2, playerBullet3, boss, enemyB1, enemyB2);
		}

	} while ( FrameworkUpdate() == false );
	
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
	EBullet enemyHell[10];
	EBullet bossShot[10];
	EBullet bossShot2[10];
	EBullet miniShot[2];
	int player1Score = 0;
	//highScore h;
	unsigned int checkKilled = 0;
	float circle = 10;
	int bossHP = 2000;
	int tick = 0;
	enemy3.EScores = 0;

	InitGame(enemyHell, bgImage, bgGameOver, player1, playerBullet, playerBullet2, playerBullet3, enemy, enemy2, enemy3, boss, enemyB1, enemyB2, enemyBullet);

}

void Engine::InitGame(EBullet enemyHell[], unsigned int& bgImage, unsigned int& bgGameOver, Player& player1, PBullet& playerBullet, 
	PBullet& playerBullet2, PBullet& playerBullet3, Enemy& enemy, Enemy& enemy2, Enemy& enemy3, Enemy& boss, Enemy& enemyB1, Enemy& enemyB2, EBullet& enemyBullet)
{
	
	bgImage = CreateSprite( "./images/bg.png", GetScreenX(), GetScreenY(), true );
	MoveSprite(bgImage, GetScreenX()>>1, GetScreenY()>>1);
	player1.SetSpriteID(player1, "./images/player.png", 100, 50);
	playerBullet.SetSpriteID(playerBullet, "./images/bullet.png", 10, 10);
	playerBullet2.SetSpriteID(playerBullet2, "./images/bullet.png", 10, 10);
	playerBullet3.SetSpriteID(playerBullet3, "./images/bullet.png", 10, 10);
	playerBullet.SetSpeed(0,-4);
	playerBullet2.SetSpeed(-1,-4);
	playerBullet3.SetSpeed(1,-4);
	enemy.SetSpriteID(enemy, "./images/enemy.png", 50, 50);
	enemy2.SetSpriteID(enemy2, "./images/enemy.png", 50, 50);
	enemy3.SetSpriteID(enemy3, "./images/enemy.png", 50, 50);
	enemyBullet.SetSpriteID(enemyBullet, "./images/enemybullet.png", 10, 10);
	
	for (int i = 0; i < 10; i++)
	{
		enemyHell[i].SetSpriteID(enemyHell[i], "./images/enemybullet.png", 10, 10);
		enemyHell[i].GetPos().SetX(600);
		enemyHell[i].GetPos().SetY(-10);
		enemyHell[i].GetSpeed().SetX(0);
		enemyHell[i].GetSpeed().SetY(4);
		enemyHell[i].SetWidth(10);
		enemyHell[i].SetHeight(10);
	}
	
	InitMenu(enemyHell, bgImage, bgGameOver, player1, playerBullet, playerBullet2, playerBullet3, enemy, enemy2, enemy3, boss, enemyB1, enemyB2, enemyBullet);
}

void Engine::InitMenu(EBullet enemyHell[], unsigned int& bgImage, unsigned int& bgGameOver, Player& player1, PBullet& playerBullet, 
	PBullet& playerBullet2, PBullet& playerBullet3, Enemy& enemy, Enemy& enemy2, Enemy& enemy3, Enemy& boss, Enemy& enemyB1, Enemy& enemyB2, EBullet& enemyBullet)
{
	Sprite splash;
	unsigned int bgMenu = -1;
	splash.SetSpriteID(splash, "./images/splash.png", GetScreenX(), GetScreenY());
	MoveSprite(splash.GetSpriteID(), GetScreenX()>>1, GetScreenY()>>1);
	bgMenu = CreateSprite( "./images/menu3.jpg", GetScreenX(), GetScreenY(), true );
	MoveSprite(bgMenu, GetScreenX()>>1, GetScreenY()>>1);
	int tick = 0;
	
	InitBoss(tick, splash, bgMenu, enemyHell, bgImage, bgGameOver, player1, playerBullet, playerBullet2, playerBullet3, enemy, enemy2, enemy3, boss, enemyB1, enemyB2, enemyBullet);
	/*
	Process = &Menu::MenuState;
	do {
		(this->*Process)(tick, splash, bgMenu);

	} while ( FrameworkUpdate() == false );
	m.DestroyMenu(splash, bgMenu);
	*/
}

void Engine::InitBoss(int &tick, Sprite &splash, unsigned int &bgMenu, EBullet enemyHell[], unsigned int& bgImage, unsigned int& bgGameOver, Player& player1, PBullet& playerBullet, 
	PBullet& playerBullet2, PBullet& playerBullet3, Enemy& enemy, Enemy& enemy2, Enemy& enemy3, Enemy& boss, Enemy& enemyB1, Enemy& enemyB2, EBullet& enemyBullet)
{
	boss.SetSpriteID(boss, "./images/enemy.png", 100, 100);
	enemyB1.SetSpriteID(enemyB1, "./images/enemy.png", 50, 50);
	enemyB2.SetSpriteID(enemyB2, "./images/enemy.png", 50, 50);

	RunGame(tick, splash, bgMenu, enemyHell, bgImage, bgGameOver, player1, playerBullet, playerBullet2, playerBullet3, enemy, enemy2, enemy3, boss, enemyB1, enemyB2, enemyBullet);
}

// Menu update
void Menu::UpdateMenu()
{
	if (IsKeyDown(32) == true)
		state = 2;
}

// Menu Draw
void Menu::DrawMenu(int &tick, Sprite &splash, unsigned int &bgMenu)
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

// Menu Draw
void Menu::DestroyMenu(Sprite &splash, unsigned int &bgMenu)
{
	DestroySprite(splash.GetSpriteID());
	DestroySprite(bgMenu);
}

// Menu State
void Engine::MenuState(int &tick, Sprite &splash, unsigned int &bgMenu)
{
	ClearScreen();
	m.UpdateMenu();
	m.DrawMenu(tick, splash, bgMenu);
}

// Play update
void Play::UpdateGame(EBullet enemyHell[], unsigned int& bgImage, unsigned int& bgGameOver, Player& player1, PBullet& playerBullet, 
	PBullet& playerBullet2, PBullet& playerBullet3, Enemy& enemy, Enemy& enemy2, Enemy& enemy3, Enemy& boss, Enemy& enemyB1, Enemy& enemyB2, EBullet& enemyBullet)
{
	ClearScreen();
	scores = enemy3.EScores;
	player1.MovePlayer(player1);
	player1.PlayerShoot(playerBullet, playerBullet2, playerBullet3);
	enemy.SpawnEnemy(enemy);
	enemy3.EnemyShoot(*enemyHell, enemy3);
	//e.EnemyShoot(enemyBullet, pl.GetPlayerLocationX(), pl.GetPlayerLocationY());
	//e.EnemyShoot(pl.GetPlayerLocationX(player1), pl.GetPlayerLocationY(player1));


	if (playerBullet.dead == true && playerBullet2.dead == true && playerBullet3.dead == true)
		pl.IfDead(playerBullet, playerBullet2, playerBullet3, player1);
	else
	{
		playerBullet.IfAlive();
		playerBullet2.IfAlive2();
		playerBullet3.IfAlive3();
		playerBullet.PBUpdate(); //call update on all bullets
		playerBullet2.PBUpdate();
		playerBullet3.PBUpdate();
	}

	Enemy::CheckEnemyCollision(enemy, enemy2, enemy3, playerBullet, playerBullet2, playerBullet3, player1);

	enemy2.SpawnEnemy(enemy2);
	enemy2.SpawnEnemySide(enemy3);

	if (Collision::CheckCollision(enemy, player1) == true) {
		state = 3;
		enemy.ResetEnemy(enemy);
		enemy2.ResetEnemy(enemy2);
		enemy3.ResetEnemySide(enemy3);
		enemyBullet.GetPos().SetY(-10);
		playerBullet.GetPos().SetX(0);
		playerBullet.GetPos().SetY(0);
		playerBullet2.GetPos().SetX(0);
		playerBullet2.GetPos().SetY(0);
		playerBullet3.GetPos().SetX(0);
		playerBullet3.GetPos().SetY(0);
		WriteHS();
		scores = 0;
	}
	if (Collision::CheckCollision(enemy2, player1) == true) {
		state = 3;
		enemy.ResetEnemy(enemy);
		enemy2.ResetEnemy(enemy2);
		enemy3.ResetEnemySide(enemy3);
		enemyBullet.GetPos().SetY(-10);
		playerBullet.GetPos().SetX(0);
		playerBullet.GetPos().SetY(0);
		playerBullet2.GetPos().SetX(0);
		playerBullet2.GetPos().SetY(0);
		playerBullet3.GetPos().SetX(0);
		playerBullet3.GetPos().SetY(0);
		WriteHS();
		scores = 0;
	}

	if (Collision::CheckCollision(enemy3, player1) == true) {
		state = 3;
		enemy.ResetEnemy(enemy);
		enemy2.ResetEnemy(enemy2);
		enemy3.ResetEnemySide(enemy3);
		enemyBullet.GetPos().SetY(-10);
		playerBullet.GetPos().SetX(0);
		playerBullet.GetPos().SetY(0);
		playerBullet2.GetPos().SetX(0);
		playerBullet2.GetPos().SetY(0);
		playerBullet3.GetPos().SetX(0);
		playerBullet3.GetPos().SetY(0);
		WriteHS();
		scores = 0;
	}

	if (Collision::CheckCollision(player1,enemyBullet) == true) {
		//gameProcess = &gameOverState;
		//writeHS();
	}
	/*
	for (int i = 0; i < 10; i++)
	{
	if (Collision::CheckCollision(player1,enemyHell[i]) == true) {
		//gameProcess = &gameOverState;
		//writeHS();
	}
	}
	*/

	//if (checkKilled >= 50)
		//gameProcess = &bossState;

	//if (IsKeyDown(KEY_SPECIAL+33) && IsKeyDown('W'))
		//gameProcess = &bossState;

	char score[10]; // buffer
	itoa(scores,score,10); // convert int to string
	DrawString("Score: ", 1000, 25, SColour(0,0xFF,0,0));
	DrawString(score, 1100, 25, SColour(0,0x7F,0,0x7F)); // draw string

	RotateSprite(player1.GetSpriteID(), 0);
	MoveSprite(player1.GetSpriteID(), player1.GetPos().GetX(), player1.GetPos().GetY());
	
	
	MoveSprite(playerBullet.GetSpriteID(), playerBullet.GetPos().GetX(), playerBullet.GetPos().GetY());
	MoveSprite(playerBullet2.GetSpriteID(), playerBullet2.GetPos().GetX(), playerBullet2.GetPos().GetY());
	MoveSprite(playerBullet3.GetSpriteID(), playerBullet3.GetPos().GetX(), playerBullet3.GetPos().GetY());

	RotateSprite(enemy.GetSpriteID(), 0);
	MoveSprite(enemy.GetSpriteID(), enemy.GetPos().GetX(), enemy.GetPos().GetY());
	MoveSprite(enemy2.GetSpriteID(), enemy2.GetPos().GetX(), enemy2.GetPos().GetY());
	MoveSprite(enemy3.GetSpriteID(), enemy3.GetPos().GetX(), enemy3.GetPos().GetY());
	MoveSprite(enemyBullet.GetSpriteID(), enemyBullet.GetPos().GetX(), enemyBullet.GetPos().GetY());
	
	for (int i = 0; i < 10; i++)
	{
		MoveSprite(enemyHell[i].GetSpriteID(), enemyHell[i].GetPos().GetX(), enemyHell[i].GetPos().GetY());
	}
	
	if (IsKeyDown(KEY_SPECIAL+38) == true)
		state = 1;

	if (IsKeyDown(KEY_SPECIAL+33) && IsKeyDown('W'))
		state = 4;
}

// Play draw
void Play::DrawGame(EBullet enemyHell[], unsigned int& bgImage, unsigned int& bgGameOver, Player& player1, PBullet& playerBullet, 
	PBullet& playerBullet2, PBullet& playerBullet3, Enemy& enemy, Enemy& enemy2, Enemy& enemy3, Enemy& boss, Enemy& enemyB1, Enemy& enemyB2, EBullet& enemyBullet)
{
	DrawSprite(bgImage);
	DrawSprite(playerBullet.GetSpriteID());
	DrawSprite(playerBullet2.GetSpriteID());
	DrawSprite(playerBullet3.GetSpriteID());
	DrawSprite(player1.GetSpriteID());
	DrawSprite(enemy.GetSpriteID());
	DrawSprite(enemy2.GetSpriteID());
	DrawSprite(enemy3.GetSpriteID());
	DrawSprite(enemyBullet.GetSpriteID());
	
	for (int i = 0; i < 10; i++)
	{
		DrawSprite(enemyHell[i].GetSpriteID());
	}
	
}

// Play State
void Engine::PlayState(EBullet enemyHell[], unsigned int& bgImage, unsigned int& bgGameOver, Player& player1, PBullet& playerBullet, 
	PBullet& playerBullet2, PBullet& playerBullet3, Enemy& enemy, Enemy& enemy2, Enemy& enemy3, Enemy& boss, Enemy& enemyB1, Enemy& enemyB2, EBullet& enemyBullet)
{
	ClearScreen();
	p.UpdateGame(enemyHell, bgImage, bgGameOver, player1, playerBullet, 
	playerBullet2, playerBullet3, enemy, enemy2, enemy3, boss, enemyB1, enemyB2, enemyBullet);
	p.DrawGame(enemyHell, bgImage, bgGameOver, player1, playerBullet, 
	playerBullet2, playerBullet3, enemy, enemy2, enemy3, boss, enemyB1, enemyB2, enemyBullet);
}

// Game Over
void GameOver::UpdateGO()
{
	ClearScreen();
	GameO = CreateSprite( "./images/gameover.jpg", GetScreenX(), GetScreenY(), true );
	MoveSprite(GameO, GetScreenX()>>1, GetScreenY()>>1);
	DrawString("Game over", GetScreenX() / 2, GetScreenY() / 2, SColour(0,0xFF,0,0));
	DrawSprite(GameO);
	if (IsKeyDown(KEY_SPECIAL+38) == true)
		state = 1;
}

// Boss update
void Boss::UpdateBoss(unsigned int& bgImage, Player& player1, PBullet& playerBullet, 
	PBullet& playerBullet2, PBullet& playerBullet3, Enemy& boss, Enemy& enemyB1, Enemy& enemyB2)
{
	boss.SetPos(GetScreenX() / 2, GetScreenY() /6);
	player1.MovePlayer(player1);
	player1.PlayerShoot(playerBullet, playerBullet2, playerBullet3);
	
	if (playerBullet.dead == true && playerBullet2.dead == true && playerBullet3.dead == true)
		player1.IfDead(playerBullet, playerBullet2, playerBullet3, player1);
	else
	{
		playerBullet.IfAlive();
		playerBullet2.IfAlive2();
		playerBullet3.IfAlive3();
		playerBullet.PBUpdate(); //call update on all bullets
		playerBullet2.PBUpdate();
		playerBullet3.PBUpdate();
	}

	Enemy::CheckEnemyCollision(playerBullet, playerBullet2, playerBullet3, player1);

	enemyB1.EnemyPattern(enemyB2);

	
	MoveSprite(boss.GetSpriteID(), boss.GetPos().GetX(), boss.GetPos().GetY());
	MoveSprite(enemyB1.GetSpriteID(), enemyB1.GetPos().GetX(), enemyB1.GetPos().GetY());
	MoveSprite(enemyB2.GetSpriteID(), enemyB2.GetPos().GetX(), enemyB2.GetPos().GetY());

	MoveSprite(playerBullet.GetSpriteID(), playerBullet.GetPos().GetX(), playerBullet.GetPos().GetY());
	MoveSprite(playerBullet2.GetSpriteID(), playerBullet2.GetPos().GetX(), playerBullet2.GetPos().GetY());
	MoveSprite(playerBullet3.GetSpriteID(), playerBullet3.GetPos().GetX(), playerBullet3.GetPos().GetY());
}

// Boss draw
void Boss::DrawBoss(unsigned int& bgImage, Player& player1, PBullet& playerBullet, 
	PBullet& playerBullet2, PBullet& playerBullet3, Enemy& boss, Enemy& enemyB1, Enemy& enemyB2)
{
	DrawSprite(bgImage);
	char score[10];
	itoa(scores,score,10);
	DrawString("Score: ", 1000, 25, SColour(0,0xFF,0,0));
	DrawString(score, 1100, 25, SColour(0,0x7F,0,0x7F));

	DrawSprite(player1.GetSpriteID());
	DrawSprite(playerBullet.GetSpriteID());
	DrawSprite(playerBullet2.GetSpriteID());
	DrawSprite(playerBullet3.GetSpriteID());
	DrawSprite(boss.GetSpriteID());
	DrawSprite(enemyB1.GetSpriteID());	
	DrawSprite(enemyB2.GetSpriteID());
}

// Boss state
void Engine::BossState(unsigned int& bgImage, Player& player1, PBullet& playerBullet, 
	PBullet& playerBullet2, PBullet& playerBullet3, Enemy& boss, Enemy& enemyB1, Enemy& enemyB2)
{
	ClearScreen();
	b.UpdateBoss(bgImage, player1, playerBullet, playerBullet2, playerBullet3, boss, enemyB1, enemyB2);
	b.DrawBoss(bgImage, player1, playerBullet, playerBullet2, playerBullet3, boss, enemyB1, enemyB2);
}
// Write High Scores
void Engine::WriteHS()
{
	HighScore h;
	h.write(scores);
}