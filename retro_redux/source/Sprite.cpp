//Last Edit 11/12/2013
//Will Gilstrap
/////////////////////
#include "AIE.h"
#include "Sprite.h"
#include "Bullets.h"

// Get Set v_position
	void Sprite::SetPos(const float &x, const float &y)
	{
		this->m_vPosition.SetX(x);
		this->m_vPosition.SetY(y);
	}
	vector2& Sprite::GetPos()
	{
		return m_vPosition;
	}
	float Sprite::GetPosX()
	{
		return this->m_vPosition.GetX();
	}
	float Sprite::GetPosY()
	{
		return this->m_vPosition.GetY();
	}
	// Get Set v_speed
	void Sprite::SetSpeed(const float &x, const float &y)
	{
		this->m_vSpeed.SetX(x);
		this->m_vSpeed.SetY(y);
	}
	vector2 Sprite::GetSpeed()
	{
		return m_vSpeed;
	}
	// Get Set iSpriteID
	void Sprite::SetSpriteID(Sprite &name, const char* a_Texture, int a_iWidth, int a_iHeight)
	{
		name.m_iSpriteID = CreateSprite( a_Texture, a_iWidth, a_iHeight, true ); // do something here
	}

	int Sprite::GetSpriteID()
	{
		return m_iSpriteID;
	}
	// Get Set iWidth
	void Sprite::SetWidth(const int &w)
	{
		this->m_iWidth = w;
	}
	int Sprite::GetWidth()
	{
		return m_iWidth;
	}
	// Get Set iHeight
	void Sprite::SetHeight(const int &h)
	{
		this->m_iHeight = h;
	}
	int Sprite::GetHeight()
	{
		return m_iHeight;
	}