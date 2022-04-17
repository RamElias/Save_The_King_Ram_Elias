#include "MovingInclude/Thief.h"

//Constructor of Thief
Thief::Thief( sf::Vector2f & place) :
	Player(place, ResourceManager::instance().GetTexture(TEXTURE_TYPE::ThiefNum))
{}

//-------------------------------------------------------
void Thief::handleCollision(Object& object)
{
	if (&object == this) return;
	//double dispatch
	object.handleCollision(*this);
}

//-------------------------------------------------------
void Thief::handleCollision(Gift& )
{
	m_gift = true;
}

//-------------------------------------------------------
void Thief::handleCollision(Dragon& dragon)
{
	dragon.setDragonFire();
	dragon.moveback();
}

//-------------------------------------------------------
void Thief::handleCollision(Dwarf& dwarf)
{
	dwarf.moveback();
}

//-------------------------------------------------------
void Thief::handleCollision(King& king)
{
	king.moveback();
}

//-------------------------------------------------------
void Thief::handleCollision(Mage& mage)
{
	mage.moveback();
}

//-------------------------------------------------------
void Thief::handleCollision(Warrior& warrior)
{
	warrior.moveback();
}

//-------------------------------------------------------
void Thief::handleCollision(Fire& )
{
	moveback();
}

//-------------------------------------------------------
void Thief::handleCollision(Gate& )
{
	if (hasKey() == false)
		moveback();
	else
		m_hadBonus = true;

	m_hasKey = false;

}

//-------------------------------------------------------
void Thief::handleCollision(Key& )
{
	m_hasKey = true;
	m_hadBonus = true;
}

//-------------------------------------------------------
void Thief::handleCollision(Ork& )
{
	moveback();
}

//-------------------------------------------------------
void Thief::handleCollision(Teleport& teleport)
{
	m_inTeleport = true;

	m_hadBonus = true;

	sf::Vector2f location = teleport.getTelePosition();

	movebyteleport(location);
}

//-------------------------------------------------------
void Thief::handleCollision(Throne& )
{
	moveback();
}

//-------------------------------------------------------
void Thief::handleCollision(Wall& )
{
	moveback();
}

//-------------------------------------------------------
bool Thief::hasKey()
{
	return m_hasKey;
}

//-------------------------------------------------------
void Thief::removeKey(bool stat)
{
	m_hasKey = stat;
}

//-------------------------------------------------------
bool Thief::getGift()
{
	bool stat = m_gift;
	m_gift = false;
	return stat;
}

