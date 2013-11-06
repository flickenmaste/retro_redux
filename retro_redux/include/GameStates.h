//Last Edit 11/5/2013
//Will Gilstrap
/////////////////////
#ifndef _GAMESTATES_H_
#define _GAMESTATES_H_


class Menu
{
public:
	void initMenu();
	void updateMenu();
	void drawMenu();
	void destroyMenu();
	void menuState();
};

class Play
{
public:
	void playState();
};

class Gameover
{
public:
	void initBoss();
	void updateBoss();
	void drawBoss();
	void destroyBoss();
	void bossState();
};

#endif