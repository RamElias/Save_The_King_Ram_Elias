#include "MovingInclude/King.h"

//Constructor of King
King::King( sf::Vector2f & place) :
	Player(place, ResourceManager::instance().GetTexture(TEXTURE_TYPE::KingNum))
{}

//-------------------------------------------------------
void King::handleCollision(Object& object)
{
	if (&object == this) return;

	//double dispatch
	object.handleCollision(*this);

}

//-------------------------------------------------------
void King::handleCollision(Gift& )
{
	m_gift = true;
}

//-------------------------------------------------------
void King::handleCollision(Dragon& )
{
	m_dragonCatchMe = true;
}

//-------------------------------------------------------
void King::handleCollision(Dwarf& dwarf)
{
	dwarf.moveback();
}

//-------------------------------------------------------
void King::handleCollision(Mage& mage)
{
	mage.moveback();
}

//-------------------------------------------------------
void King::handleCollision(Warrior& warrior)
{
	warrior.moveback();
}

//-------------------------------------------------------
void King::handleCollision(Thief& thief)
{
	thief.moveback();
}

//-------------------------------------------------------
void King::handleCollision(Fire& )
{
	moveback();
}

//-------------------------------------------------------
void King::handleCollision(Gate& )
{
	moveback();
}

//-------------------------------------------------------
void King::handleCollision(Ork& )
{
	moveback();
}

//-------------------------------------------------------
void King::handleCollision(Teleport& teleport)
{
	m_inTeleport = true;

	m_hadBonus = true;

	sf::Vector2f location = teleport.getTelePosition();

	movebyteleport(location);
}

//-------------------------------------------------------
void King::handleCollision(Throne& )
{
	m_gotThrone = true;
}

//-------------------------------------------------------
void King::handleCollision(Wall& )
{
	moveback();
}

//-------------------------------------------------------
bool King::getThrone()
{
	return m_gotThrone;
}

//-------------------------------------------------------
bool King::getGift()
{
	bool stat = m_gift;
	m_gift = false;
	return stat;
}

//-------------------------------------------------------
bool King::dragonCatchKingCheck()
{
	return m_dragonCatchMe;
}
