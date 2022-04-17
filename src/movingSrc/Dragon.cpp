#include "MovingInclude/Dragon.h"
#include <iostream>

//-------------------------------------------------------
//Constructor of Dragon
Dragon::Dragon(sf::Vector2f& place)
	: Enemy(place, ResourceManager::instance().GetTexture(TEXTURE_TYPE::DragonNum))
{}

//-------------------------------------------------------
//Dragon smart move
void Dragon::move(const sf::Time& )
{
	if (m_clock.getElapsedTime().asSeconds() > 2)	//make a move every 2 sec
	{
		sf::Vector2f newDirection = STOP;
		
		m_clock.restart();
			
		m_creatFire = true;

		newDirection = calcDirection(); 
		
		MovingObject::setDirection(newDirection);

		sf::Time newdelta = sf::seconds(0.2); //in order to move large amount

		MovingObject::move(newdelta); // move
	}
}

//-------------------------------------------------------
//calculate the smart move of the dragon to the king
sf::Vector2f Dragon::calcDirection()
{
	// get king location
	sf::Vector2f kingplace = ResourceManager::instance().returnKingPosition();
	//get dragon location
	sf::Vector2f dragonplace = m_sprit.getPosition();

	if (m_oldplace == dragonplace) // dident move!
	{
		m_counter = 0;

		if (m_tryDirection != STOP) //dident move 2 time ! - change direction
		{
			if (m_tryDirection == UP || m_tryDirection == DOWN)
				m_Ycheck = true;

			if (m_tryDirection == RIGHT || m_tryDirection == LEFT)
				m_Xcheck = true;
		}
		else
			m_wantDirection = m_direction; //first dident move

		if (m_wantDirection == UP || m_wantDirection == DOWN)
		{
			if (m_Xcheck == false)
				m_tryDirection = RIGHT; //first time
			else
				m_tryDirection = LEFT;	//if RIGHT did stuck two
		}

		if (m_wantDirection == LEFT || m_wantDirection == RIGHT)
		{
			if (m_Ycheck == false)
				m_tryDirection = DOWN;	//first time
			else
				m_tryDirection = UP; //if DOWN did stuck two
		}

		return m_tryDirection; //sends the direction we want to try
	}

	m_counter++;

	if (m_counter < 3) // if from the first dident move dident pass 3 turns
		return m_wantDirection;
	
	if (m_counter == 3)  // if pass 3 turns
	{
		m_tryDirection = STOP;
		m_Xcheck = false;
		m_Ycheck = false;
	}

	int zoom = 70; // initial zoom

	while (true)
	{
		if (kingplace.x > dragonplace.x && abs(kingplace.x - dragonplace.x) > zoom)
			return RIGHT;

		if (kingplace.x < dragonplace.x && abs(dragonplace.x - kingplace.x) > zoom)
			return LEFT;
		
		if (kingplace.y < dragonplace.y && abs(dragonplace.y - kingplace.y) > zoom)
			return UP;
		
		if (kingplace.y > dragonplace.y && abs(kingplace.y - dragonplace.y) > zoom)
			return DOWN;
		
		zoom = zoom / 2; //if we are to close
	}
}

//-------------------------------------------------------
void Dragon::handleCollision(Object& object)
{
	if (&object == this) return;

	//double dispatch
	object.handleCollision(*this);
}

//-------------------------------------------------------
void Dragon::handleCollision(King& king)
{
	king.handleCollision(*this);
}

//-------------------------------------------------------
void Dragon::handleCollision(Mage& )
{
	m_isDisposed = true;
}

//-------------------------------------------------------
void Dragon::handleCollision(Warrior& warrior)
{
	warrior.moveback();
}

//-------------------------------------------------------
void Dragon::handleCollision(Thief& thief)
{
	thief.moveback();
}

//-------------------------------------------------------
void Dragon::handleCollision(Dwarf& dwarf)
{
	dwarf.moveback();
}

//-------------------------------------------------------
void Dragon::handleCollision(Wall& )
{
	m_creatFire = false;
	moveback();
}

//-------------------------------------------------------
void Dragon::setDragonFire()
{
	m_creatFire = false;
}

//-------------------------------------------------------
//sends last place to creat fire and bool if nedded
bool Dragon::creatDragonFire(sf::Vector2f& place)
{
	place = m_oldplace;
	bool stat = m_creatFire;
	m_creatFire = false;
	return stat;
}


