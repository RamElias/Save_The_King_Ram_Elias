#include "StaticInclude/Throne.h"

//-------------------------------------------------------
//Constructor of Throne
Throne::Throne(const  sf::Vector2f& place) :
	StaticObject(place, ResourceManager::instance().GetTexture(TEXTURE_TYPE::ThroneNum))
{}
//-------------------------------------------------------
void Throne::handleCollision(Object& object)
{
	if (&object == this) return;
	//double dispatch
	object.handleCollision(*this);
}
//-------------------------------------------------------
void Throne::handleCollision(King& king)
{
	king.handleCollision(*this);
}
//-------------------------------------------------------
void Throne::handleCollision(Mage& mage)
{
	mage.handleCollision(*this);
}
//-------------------------------------------------------
void Throne::handleCollision(Warrior& warrior)
{
	warrior.handleCollision(*this);
}
//-------------------------------------------------------
void Throne::handleCollision(Thief& thief)
{
	thief.handleCollision(*this);
}