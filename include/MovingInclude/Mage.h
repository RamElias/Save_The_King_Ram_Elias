//in this file we Declares the
//Fire class and his members
#pragma once

#include "Player.h"
#include "Board.h"

class Mage :public Player
{
public:
	Mage(sf::Vector2f & place);
	~Mage(){}

	virtual void handleCollision(Object& object) override;

	virtual void handleCollision(King& king) override;
	virtual void handleCollision(Mage& ) override {}
	virtual void handleCollision(Warrior& warrior) override;
	virtual void handleCollision(Thief& thief) override;
	virtual void handleCollision(Dwarf& dwarf) override;
	virtual void handleCollision(Dragon& dragon) override;

	virtual void handleCollision(Fire& fire) override;
	virtual void handleCollision(Gate& gate) override;
	virtual void handleCollision(Key& ) override {}
	virtual void handleCollision(Ork& ork) override;
	virtual void handleCollision(Teleport& teleport) override;
	virtual void handleCollision(Throne& throne) override;
	virtual void handleCollision(Wall& wall) override;
	virtual void handleCollision(Gift& gift) override;

	bool getGift();

private:
	bool m_gift = false;

};

