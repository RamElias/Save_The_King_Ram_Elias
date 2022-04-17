#include "MovingObject.h"

//-------------------------------------------------------
//constructor of MovingObject
MovingObject::MovingObject(const  sf::Vector2f& place, sf::Texture& texture)
	:Object(place, texture)
{}

//-------------------------------------------------------
void MovingObject::setDirection(sf::Vector2f& direction)
{
	m_direction = direction;
}

//-------------------------------------------------------
//move the sprite of the character
void MovingObject::move(const sf::Time& delta)
{
	m_oldplace = m_sprit.getPosition();

	m_sprit.move(m_direction * delta.asSeconds() * SPEED);
}

//-------------------------------------------------------
//move the sprite back to the last position after collision
void MovingObject::moveback()
{
	m_sprit.setPosition(m_oldplace);
}