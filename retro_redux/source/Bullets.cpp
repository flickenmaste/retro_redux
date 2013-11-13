//Last Edit 11/12/2013
//Will Gilstrap
/////////////////////

#include "Bullets.h"

void PBullet::PBUpdate()
{
	if(this->GetPos().GetY() < -5)
		dead = true;
}

void PBullet::IfAlive()	// function executed if player is shooting
{

	//bullet 1
	this->GetPos().SetX( this->GetPos().GetX() + this->GetSpeed().GetX() );
	this->GetPos().SetY( this->GetPos().GetY() + this->GetSpeed().GetY() );
}

void PBullet::IfAlive2()	// function executed if player is shooting
{
	//bullet 2
	this->GetPos().SetX( this->GetPos().GetX() + this->GetSpeed().GetX() );
	this->GetPos().SetY( this->GetPos().GetY() + this->GetSpeed().GetY() );
}

void PBullet::IfAlive3()	// function executed if player is shooting
{
	//bullet 3
	this->GetPos().SetX( this->GetPos().GetX() + this->GetSpeed().GetX() );
	this->GetPos().SetY( this->GetPos().GetY() + this->GetSpeed().GetY() );
}