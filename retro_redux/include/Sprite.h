//Last Edit 11/4/2013
//Will Gilstrap
/////////////////////
#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "Vector2.h"

class Sprite
{
public:
	// Get Set v_position
	void SetPos(const float &x, const float &y);
	vector2 GetPos();

	// Get Set v_speed
	void SetSpeed(const float &x, const float &y);
	vector2 GetSpeed();

	// Get Set iSpriteID
	void SetSpriteID();
	int GetSpriteID();

	// Get Set iWidth
	void SetWidth(const int &w);
	int GetWidth();

	// Get Set iHeight
	void SetHeight(const int &h);
	int GetHeight();

protected:
	vector2 m_vPosition;
	vector2 m_vSpeed;
	int m_iSpriteID;
	int m_iWidth;
	int m_iHeight;
};

#endif