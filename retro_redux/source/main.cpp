//Last Edit 11/6/2013
//Will Gilstrap
/////////////////////
#include "AIE.h"
#include <iostream>
#include "GameEngine.h"

int main()
{
	Engine shmup;
	Initialise(shmup.GetScreenX(), shmup.GetScreenY(), false, "Shoot em up 2");
	shmup.RunEngine();

	Shutdown();
	return 0;
}