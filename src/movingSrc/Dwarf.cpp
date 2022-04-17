#include "MovingInclude/Dwarf.h"

//Constructor of Dwarf
Dwarf::Dwarf(sf::Vector2f& place)
	: Enemy(place, ResourceManager::instance().GetTexture(TEXTURE_TYPE::DwarfNum))
{}

//-------------------------------------------------------
//Dwarf move by rand
void Dwarf::move(const sf::Time& delta)
{
	if (m_clock.getElapsedTime().asSeconds() > DWARF_MOVE)	//changes direction every 0.3 second
	{
		m_clock.restart();
		sf::Vector2f newDirection;

		switch (rand() % DWARF_RAND)
		{
		case 0:
			newDirection = UP;
			break;
		case 1:
			newDirection = DOWN;
			break;
		case 2:
			newDirection = RIGHT;
			break;
		case 3:
			newDirection = LEFT;
			break;
		case 4:
			newDirection = STOP;
			break;
		}

		MovingObject::setDirection(newDirection);
	}

	MovingObject::move(delta);
}

//-------------------------------------------------------
void Dwarf::handleCollision(Object& object)
{
	if (&object == this) return;

	//double dispatch
	object.handleCollision(*this);
}

//-------------------------------------------------------
void Dwarf::handleCollision(Dragon& dragon)
{
	dragon.setDragonFire();
	dragon.moveback();
}

//-------------------------------------------------------
void Dwarf::handleCollision(King& king)
{
	king.moveback();
}

//-------------------------------------------------------
void Dwarf::handleCollision(Mage& mage)
{
	mage.moveback();
}

//-------------------------------------------------------
void Dwarf::handleCollision(Warrior& warrior)
{
	warrior.moveback();
}

//-------------------------------------------------------
void Dwarf::handleCollision(Thief& thief)
{
	thief.moveback();
}

//-------------------------------------------------------
void Dwarf::handleCollision(Dwarf& dwarf)
{
	dwarf.moveback();
}

//-------------------------------------------------------
void Dwarf::handleCollision(Wall& )
{
	moveback();
}

//-------------------------------------------------------
void Dwarf::killDwarf()
{
	m_isDisposed = true;
}


