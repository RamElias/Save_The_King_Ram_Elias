#include "StaticInclude/Fire.h"

//-------------------------------------------------------
//Constructor of Fire
Fire::Fire(sf::Vector2f& place)
	: StaticObject(place, ResourceManager::instance().GetTexture(TEXTURE_TYPE::FireNum))
{}

//-------------------------------------------------------
//handles collision bwtween Fire and an Object
void Fire::handleCollision(Object& object)
{
	if (&object == this) return;
	//double dispatch
	object.handleCollision(*this);
}

//-------------------------------------------------------
void Fire::handleCollision(King& king)
{
	king.handleCollision(*this);
}

//-------------------------------------------------------
void Fire::handleCollision(Mage& mage)
{
	m_isDisposed = true;
	mage.handleCollision(*this);
}

//-------------------------------------------------------
void Fire::handleCollision(Warrior& warrior)
{
	warrior.handleCollision(*this);
}

//-------------------------------------------------------
void Fire::handleCollision(Thief& thief)
{
	thief.handleCollision(*this);
}