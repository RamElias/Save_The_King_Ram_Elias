//in this file we Declares the
//Fire class and his members
#pragma once

#include "StaticObject.h"
#include "Board.h"

class Teleport :public StaticObject
{
public:
	Teleport(const  sf::Vector2f & placeX, sf::Vector2f& placeY);
	~Teleport(){}

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

	sf::Vector2f getTelePosition();

private:
	bool m_occupied = false;
	sf::Vector2f m_secondteleport = STOP;
};

