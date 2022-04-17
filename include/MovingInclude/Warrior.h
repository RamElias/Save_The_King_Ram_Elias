//in this file we Declares the
//Fire class and his members
#pragma once

#include "Player.h"
#include "Board.h"

class Warrior :public Player
{
public:
	Warrior(sf::Vector2f & place);
	~Warrior(){}

	virtual void handleCollision(Object& object) override;

	virtual void handleCollision(King& king) override;
	virtual void handleCollision(Mage& mage) override;
	virtual void handleCollision(Warrior& ) override {}
	virtual void handleCollision(Thief& thief) override;
	virtual void handleCollision(Dwarf& dwarf) override;
	virtual void handleCollision(Dragon& dragon) override;

	virtual void handleCollision(Fire& fire) override;
	virtual void handleCollision(Gate& gate) override;
	virtual void handleCollision(Key& key) override;
	virtual void handleCollision(Ork& ork) override;
	virtual void handleCollision(Teleport& teleport) override;
	virtual void handleCollision(Throne& throne) override;
	virtual void handleCollision(Wall& wall) override;
	virtual void handleCollision(Gift& gift) override;

	bool creatKey();

	bool getGift();

private:
	bool m_creatkey = false;
	bool m_gift = false;
};

