//Last Edit 11/13/2013
//Will Gilstrap
/////////////////////
#include "AIE.h"
#include <iostream>
#include "GameEngine.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix.h"
#include "ComMath.h"

HighScore h;

int main()
{
	Engine shmup;
	shmup.RunEngine();
	h.read();
	Shutdown();
	return 0;
}