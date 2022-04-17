//in this file we Declares the
//Fire class and his members
#pragma once

#include "StaticObject.h"
#include "Board.h"

class Throne :public StaticObject
{
public:
	Throne(const  sf::Vector2f & place);
	~Throne(){}

	virtual void handleCollision(Object& object) override;

	virtual void handleCollision(King& king) override;
	virtual void handleCollision(Mage& mage) override;
	virtual void handleCollision(Warrior& warrior) override;
	virtual void handleCollision(Thief& thief) override;
	virtual void handleCollision(Dwarf& ) override {}
	virtual void handleCollision(Dragon&) override {}

	virtual void handleCollision(Fire& ) override {}
	virtual void handleCollision(Gate& ) override {}
	virtual void handleCollision(Key& ) override {}
	virtual void handleCollision(Ork& ) override {}
	virtual void handleCollision(Teleport& ) override {}
	virtual void handleCollision(Throne& ) override {}
	virtual void handleCollision(Wall& ) override {}
	virtual void handleCollision(Gift& ) override {}


private:

};

