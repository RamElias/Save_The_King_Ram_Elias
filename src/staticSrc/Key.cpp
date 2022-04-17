#include "StaticInclude\Key.h"

//-------------------------------------------------------
//Constructor of Key
Key::Key(const  sf::Vector2f& place) :
	StaticObject(place, ResourceManager::instance().GetTexture(TEXTURE_TYPE::KeyNum))
{}

//-------------------------------------------------------
void Key::handleCollision(Object& object)
{
	if (&object == this) return;
	//double dispatch
	object.handleCollision(*this);
}
//-------------------------------------------------------
void Key::handleCollision(King& king)
{
	king.handleCollision(*this);
}
//-------------------------------------------------------
void Key::handleCollision(Mage& mage)
{
	mage.handleCollision(*this);
}
//-------------------------------------------------------
void Key::handleCollision(Warrior& warrior)
{
	warrior.handleCollision(*this);
}
//-------------------------------------------------------
void Key::handleCollision(Thief& thief)
{
	if (thief.hasKey() == false)
	{
		thief.handleCollision(*this);
		m_isDisposed = true;
	}
}