#include "StaticInclude/Wall.h"

//-------------------------------------------------------
//Constructor of Wall
Wall::Wall(const  sf::Vector2f& place) :
	StaticObject(place, ResourceManager::instance().GetTexture(TEXTURE_TYPE::WallNum))
{}

//-------------------------------------------------------
void Wall::handleCollision(Object& object)
{
	if (&object == this) return;
	//double dispatch
	object.handleCollision(*this);
}

//-------------------------------------------------------
void Wall::handleCollision(Dragon& dragon)
{
	dragon.setDragonFire();
	dragon.handleCollision(*this);
}

//-------------------------------------------------------
void Wall::handleCollision(Dwarf& dwarf)
{
	dwarf.handleCollision(*this);
}

//-------------------------------------------------------
void Wall::handleCollision(King& king)
{
	king.handleCollision(*this);
}

//-------------------------------------------------------
void Wall::handleCollision(Mage& mage)
{
	mage.handleCollision(*this);
}

//-------------------------------------------------------
void Wall::handleCollision(Warrior& warrior)
{
	warrior.handleCollision(*this);
}

//-------------------------------------------------------
void Wall::handleCollision(Thief& thief)
{
	thief.handleCollision(*this);
}