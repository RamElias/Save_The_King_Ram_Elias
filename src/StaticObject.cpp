#include "StaticObject.h"

//constructor of tile
StaticObject::StaticObject(const  sf::Vector2f& place, sf::Texture& texture)
	:Object(place, texture) {}


//-------------------------------------------------------
sf::Vector2f StaticObject::getlocation()
{
	return m_sprit.getPosition();
}

