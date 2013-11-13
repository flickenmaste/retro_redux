//Last Edit 10/16/2013
//Will Gilstrap
/////////////////////
#ifndef _HIGHSCORES_H_
#define _HIGHSCORES_H_

#include <string>

class HighScore
{
public:
	std::string line;
	static void write(int scores);
	void read();
};

#endif