//Last Edit 11/4/2013
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

	std::cin.get();
	std::cin.get();
	Shutdown();
	return 0;
}