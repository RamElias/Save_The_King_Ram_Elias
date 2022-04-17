//in this file we Declares the
//Main textures class and his members
#pragma once
#include "MovingObject.h"

class Enemy : public MovingObject
{
public:
	Enemy(const  sf::Vector2f&, sf::Texture&);
	virtual ~Enemy() {}

	virtual bool creatDragonFire(sf::Vector2f&) { return false; }
	virtual void killDwarf() {}

protected:
	
};

