#include "StaticInclude/Teleport.h"

//-------------------------------------------------------
//Constructor of Teleport
Teleport::Teleport(const  sf::Vector2f& placeX, sf::Vector2f& placeY) :
	StaticObject(placeX, ResourceManager::instance().GetTexture(TEXTURE_TYPE::TeleportNum))
{
	m_secondteleport = placeY;
}

//-------------------------------------------------------
void Teleport::handleCollision(Object& object)
{
	if (&object == this) return;
	//double dispatch
	object.handleCollision(*this);
}

//-------------------------------------------------------
void Teleport::handleCollision(King& king)
{
	if (!king.getInTeleort())
		king.handleCollision(*this);
}

//-------------------------------------------------------
void Teleport::handleCollision(Mage&)
{}

//-------------------------------------------------------
void Teleport::handleCollision(Warrior& warrior)
{
	if (!warrior.getInTeleort())
		warrior.handleCollision(*this);
}

//-------------------------------------------------------
void Teleport::handleCollision(Thief& thief)
{
	if (!thief.getInTeleort())
		thief.handleCollision(*this);

}

//-------------------------------------------------------
sf::Vector2f Teleport::getTelePosition()
{
	return m_secondteleport;
}