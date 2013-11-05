//Last Edit 11/4/2013
//Will Gilstrap
/////////////////////
#ifndef _GAMEENGINE_H_
#define _GAMEENGINE_H_


class Engine
{
public:
	void (*Engine::Process)();
	void RunEngine();
	// Gets
	int GetScreenX() {return m_SCREEN_X;}
	int GetScreenY() {return m_SCREEN_Y;}
	Engine() { }
private:
	static const int m_SCREEN_X = 1280;
	static const int m_SCREEN_Y = 780;

};


#endif