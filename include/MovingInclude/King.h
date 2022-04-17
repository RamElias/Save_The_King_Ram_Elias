//in this file we Declares the
//Fire class and his members
#pragma once

#include "Player.h"
#include "Board.h"

class King :public Player
{
public:
	King(sf::Vector2f & place);
	~King(){}

	virtual void handleCollision(Object& object) override;

	virtual void handleCollision(King& ) override {}
	virtual void handleCollision(Mage& mage) override;
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


	bool getThrone();
	bool getGift();
	bool dragonCatchKingCheck();

private:
	bool m_gotThrone = false;
	bool m_gift = false;
	bool m_dragonCatchMe = false;
};

