#include "Object.h"

//#include <iostream>
//-------------------------------------------------------
//Constructor of Gameobject
Object::Object(const  sf::Vector2f& postion, sf::Texture& texture)
{
	m_sprit.setTexture(texture);
	m_sprit.setPosition(postion);
	m_sprit.setScale(m_size);
}

//-------------------------------------------------------
//this function drawing the Gameobject on the window
void Object::draw(sf::RenderWindow& window)const 
{
	window.draw(m_sprit);
}

//-------------------------------------------------------
bool Object::checkCollision(const Object& other) const{
	return getGlobalBounds().intersects(other.getGlobalBounds());
}

//-------------------------------------------------------
sf::FloatRect Object::getGlobalBounds() const{
	return m_sprit.getGlobalBounds();
}

//-------------------------------------------------------
bool Object::isDisposed() const{
	return m_isDisposed;
}


