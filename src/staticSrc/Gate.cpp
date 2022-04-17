#include "StaticInclude/Gate.h"

//-------------------------------------------------------
//Constructor of Gate
Gate::Gate(const  sf::Vector2f& place) :
	StaticObject(place, ResourceManager::instance().GetTexture(TEXTURE_TYPE::GateNum))
{}

//-------------------------------------------------------
//handles collision bwtween Gate and an Object
void Gate::handleCollision(Object& object)
{
	if (&object == this) return;
	//double dispatch
	object.handleCollision(*this);
}

//-------------------------------------------------------
void Gate::handleCollision(King& king)
{
	king.handleCollision(*this);
}

//-------------------------------------------------------
void Gate::handleCollision(Mage& mage)
{
	mage.handleCollision(*this);
}

//-------------------------------------------------------
void Gate::handleCollision(Warrior& warrior)
{
	warrior.handleCollision(*this);
}

//-------------------------------------------------------
void Gate::handleCollision(Thief& thief)
{
	if (thief.hasKey() == true)
		m_isDisposed = true;

	thief.handleCollision(*this);
}