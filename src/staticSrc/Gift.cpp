#include "StaticInclude/Gift.h"

//-------------------------------------------------------
//Constructor of Gift
Gift::Gift(sf::Vector2f& place) :
	StaticObject(place, ResourceManager::instance().GetTexture(TEXTURE_TYPE::GiftNum))
{}

//-------------------------------------------------------
//handles collision bwtween Gift and an Object
void Gift::handleCollision(Object& object)
{
	if (&object == this) return;
	//double dispatch
	object.handleCollision(*this);
}

//-------------------------------------------------------
void Gift::handleCollision(King& king)
{
	m_isDisposed = true;
	king.handleCollision(*this);
}

//-------------------------------------------------------
void Gift::handleCollision(Mage& mage)
{
	m_isDisposed = true;
	mage.handleCollision(*this);
}

//-------------------------------------------------------
void Gift::handleCollision(Warrior& warrior)
{
	m_isDisposed = true;
	warrior.handleCollision(*this);
}

//-------------------------------------------------------
void Gift::handleCollision(Thief& thief)
{
	m_isDisposed = true;
	thief.handleCollision(*this);
}