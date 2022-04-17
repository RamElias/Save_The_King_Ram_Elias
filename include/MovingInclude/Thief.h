//in this file we Declares the
//Fire class and his members
#pragma once

#include "Player.h"
#include "Board.h"

class Thief :public Player
{
public:
	Thief(sf::Vector2f & place);
	~Thief(){}

	virtual void handleCollision(Object& object) override;

	virtual void handleCollision(King& king) override;
	virtual void handleCollision(Mage& mage) override;
	virtual void handleCollision(Warrior& warrior) override;
	virtual void handleCollision(Thief& ) override {}
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


	bool hasKey();
	void removeKey(bool);

	bool getGift();

private:
	bool m_hasKey = false;
	bool m_gift = false;
};

