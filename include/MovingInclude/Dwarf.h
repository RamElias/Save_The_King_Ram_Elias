#pragma once

#include "Enemy.h"
#include "Board.h"

class  Dwarf : public Enemy
{
public:
	 Dwarf(sf::Vector2f& place);
	~Dwarf() {}

	virtual void move(const sf::Time& delta) override;
	virtual void handleCollision(Object& object) override;

	virtual void handleCollision(King& king) override;
	virtual void handleCollision(Mage& mage) override;
	virtual void handleCollision(Warrior& warrior) override;
	virtual void handleCollision(Thief& thief) override;

	virtual void handleCollision(Dwarf& dwarf)override;
	virtual void handleCollision(Dragon& dragon)override;


	virtual void handleCollision(Fire& ) override {}
	virtual void handleCollision(Gate& ) override {}
	virtual void handleCollision(Key& ) override {}
	virtual void handleCollision(Ork& ) override {}
	virtual void handleCollision(Teleport& ) override {}
	virtual void handleCollision(Throne& ) override {}
	virtual void handleCollision(Wall& wall) override;
	virtual void handleCollision(Gift& ) override {}

	void killDwarf();


private:
	sf::Clock m_clock;
	bool m_isDwarf = true;

};

