//Last Edit 11/12/2013
//Will Gilstrap
/////////////////////
#include "AIE.h"
#include <iostream>
#include "GameEngine.h"

HighScore h;

int main()
{
	Engine shmup;
	Initialise(shmup.GetScreenX(), shmup.GetScreenY(), false, "Shoot em up 2");
	shmup.RunEngine();
	h.read();
	Shutdown();
	return 0;
}