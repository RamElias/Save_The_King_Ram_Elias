//in this file we Declares the
//board class and his members
#pragma once

#include "SFML/Graphics.hpp"
#include "Globals.h"
#include "ResourceManager.h"

class King;
class Mage;
class Warrior;
class Thief;
class Dwarf;
class Dragon;

class Gift;
class Fire;
class Gate;
class Key;
class Ork;
class Teleport;
class Throne;
class Wall;

class Object {
public:
	Object(const  sf::Vector2f& place, sf::Texture& texture);
	virtual ~Object() {}
	
	 //needs to change only for player
		
	bool checkCollision(const Object& other) const;
	sf::FloatRect getGlobalBounds() const;
	bool isDisposed() const;

	//Object Object Collision
	
	//Moving Object Collision
	virtual void handleCollision(King& gameObject) = 0;
	virtual void handleCollision(Mage& gameObject) = 0;
	virtual void handleCollision(Warrior& gameObject) = 0;
	virtual void handleCollision(Thief& gameObject) = 0;
	virtual void handleCollision(Dwarf& gameObject) = 0;
	virtual void handleCollision(Dragon& gameObject) = 0;
	//static Object Collision
	virtual void handleCollision(Gift& gameObject) = 0;
	virtual void handleCollision(Fire& gameObject) = 0;
	virtual void handleCollision(Gate& gameObject) = 0;
	virtual void handleCollision(Key& gameObject) = 0;
	virtual void handleCollision(Ork& gameObject) = 0;
	virtual void handleCollision(Teleport& gameObject) = 0;
	virtual void handleCollision(Throne& gameObject) = 0;
	virtual void handleCollision(Wall& gameObject) = 0;
	
	virtual void draw(sf::RenderWindow& window)const;
	virtual void handleCollision(Object& gameObject) = 0;
	


protected:
	
	sf::Sprite m_sprit;
	
	sf::Vector2f m_size = ResourceManager::instance().returnScale();

	bool m_isDisposed = false;
};
