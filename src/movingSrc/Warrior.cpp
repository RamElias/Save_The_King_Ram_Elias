#include "MovingInclude/Warrior.h"

//Constructor of Warrior
Warrior::Warrior( sf::Vector2f & place) :
	Player(place, ResourceManager::instance().GetTexture(TEXTURE_TYPE::WarriorNum))
{}

//-------------------------------------------------------
void Warrior::handleCollision(Object& object)
{
	if (&object == this) return;
	//double dispatch
	object.handleCollision(*this);
}

//-------------------------------------------------------
void Warrior::handleCollision(Gift& )
{
	m_gift = true;
}

//-------------------------------------------------------
void Warrior::handleCollision(Dragon& dragon)
{
	dragon.setDragonFire();
	dragon.moveback();
}

//-------------------------------------------------------
void Warrior::handleCollision(Dwarf& dwarf)
{
	dwarf.moveback();
}

//-------------------------------------------------------
void Warrior::handleCollision(King& king)
{
	king.moveback();
}

//-------------------------------------------------------
void Warrior::handleCollision(Mage& mage)
{
	mage.moveback();
}

//-------------------------------------------------------
void Warrior::handleCollision(Thief& thief)
{
	thief.moveback();
}

//-------------------------------------------------------
void Warrior::handleCollision(Fire& )
{
	moveback();
}

//-------------------------------------------------------
void Warrior::handleCollision(Gate& )
{
	moveback();
}

//-------------------------------------------------------
void Warrior::handleCollision(Key& )
{
}

//-------------------------------------------------------
void Warrior::handleCollision(Ork& )
{
	m_creatkey = true;
	m_hadBonus = true;
}

//-------------------------------------------------------
void Warrior::handleCollision(Teleport& teleport)
{
	m_inTeleport = true;
	
	m_hadBonus = true;

	sf::Vector2f location = teleport.getTelePosition();

	movebyteleport(location);

}

//-------------------------------------------------------
void Warrior::handleCollision(Throne& )
{
	moveback();
}

//-------------------------------------------------------
void Warrior::handleCollision(Wall& )
{
	moveback();
}

//-------------------------------------------------------
bool Warrior::creatKey()
{
	bool stat = m_creatkey;
	m_creatkey = false;
	return stat;
}

//-------------------------------------------------------
bool Warrior::getGift()
{
	bool stat = m_gift;
	m_gift = false;
	return stat;
}