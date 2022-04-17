#include "MovingInclude/Mage.h"

//Constructor of Mage
Mage::Mage( sf::Vector2f & place) :
	Player(place, ResourceManager::instance().GetTexture(TEXTURE_TYPE::MageNum))
{}

//-------------------------------------------------------
void Mage::handleCollision(Object& object)
{
	if (&object == this) return;
	//double dispatch
	object.handleCollision(*this);
}

//-------------------------------------------------------
void Mage::handleCollision(Gift& )
{
	m_gift = true;
}

//-------------------------------------------------------
void Mage::handleCollision(Dragon& dragon)
{
	dragon.handleCollision(*this);
}

//-------------------------------------------------------
void Mage::handleCollision(Dwarf& dwarf)
{
	dwarf.moveback();
}

//-------------------------------------------------------
void Mage::handleCollision(King& king)
{
	king.moveback();
}

//-------------------------------------------------------
void Mage::handleCollision(Warrior& warrior)
{
	warrior.moveback();
}

//-------------------------------------------------------
void Mage::handleCollision(Thief& thief)
{
	thief.moveback();
}

//-------------------------------------------------------
void Mage::handleCollision(Fire& )
{
	m_hadBonus = true;
}

//-------------------------------------------------------
void Mage::handleCollision(Gate& )
{
	moveback();
}

//-------------------------------------------------------
void Mage::handleCollision(Ork& )
{
	moveback();
}

//-------------------------------------------------------
void Mage::handleCollision(Teleport& )
{
	m_hadBonus = true;
}

//-------------------------------------------------------
void Mage::handleCollision(Throne& )
{
	moveback();
}

//-------------------------------------------------------
void Mage::handleCollision(Wall& )
{
	moveback();
}

//-------------------------------------------------------
bool Mage::getGift()
{
	bool stat = m_gift;
	m_gift = false;
	return stat;
}