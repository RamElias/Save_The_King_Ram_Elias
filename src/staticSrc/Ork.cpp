#include "StaticInclude/Ork.h"

//-------------------------------------------------------
//Constructor of Ork
Ork::Ork(const  sf::Vector2f& place) :
	StaticObject(place, ResourceManager::instance().GetTexture(TEXTURE_TYPE::OrkNum))
{}

//-------------------------------------------------------
void Ork::handleCollision(Object& object)
{
	if (&object == this) return;
	//double dispatch
	object.handleCollision(*this);
}
//-------------------------------------------------------
void Ork::handleCollision(King& king)
{
	king.handleCollision(*this);
}
//-------------------------------------------------------
void Ork::handleCollision(Mage& mage)
{
	mage.handleCollision(*this);
}
//-------------------------------------------------------
void Ork::handleCollision(Warrior& warrior)
{
	m_isDisposed = true;
	warrior.handleCollision(*this);
}
//-------------------------------------------------------
void Ork::handleCollision(Thief& thief)
{
	thief.handleCollision(*this);
}