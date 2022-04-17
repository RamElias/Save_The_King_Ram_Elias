//in this file we Declares the
//Dragon class and his members
#pragma once
#include "Enemy.h"
#include "Board.h"

class  Dragon : public Enemy
{
public:
	Dragon(sf::Vector2f& place);
	~Dragon() {}

	virtual void move(const sf::Time& delta) override;
	virtual void handleCollision(Object& object) override;

	virtual void handleCollision(King& king) override;
	virtual void handleCollision(Mage& mage) override;
	virtual void handleCollision(Warrior& warrior) override;
	virtual void handleCollision(Thief& thief) override;

	virtual void handleCollision(Dwarf& dwarf)override;
	virtual void handleCollision(Dragon&)override {}

	virtual void handleCollision(Fire& ) override {}
	virtual void handleCollision(Gate& ) override {}
	virtual void handleCollision(Key& ) override {}
	virtual void handleCollision(Ork& ) override {}
	virtual void handleCollision(Teleport& ) override {}
	virtual void handleCollision(Throne& ) override {}
	virtual void handleCollision(Wall& wall) override;
	virtual void handleCollision(Gift& ) override {}
	
	void setDragonFire();
	bool creatDragonFire(sf::Vector2f&);
	sf::Vector2f calcDirection();

private:
	sf::Clock m_clock;
	bool m_creatFire = false;

	sf::Vector2f m_wantDirection = STOP;
	sf::Vector2f m_tryDirection = STOP;

	bool m_Xcheck = false;
	bool m_Ycheck = false;

	int m_counter = 3;
};

