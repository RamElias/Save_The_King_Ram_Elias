//in this file we Declares the
//Main textures class and his members
#pragma once
#include "Object.h"

class MovingObject : public Object
{
public:
	MovingObject(const  sf::Vector2f&, sf::Texture&);
	virtual ~MovingObject() {}
	
	void setDirection(sf::Vector2f& direction);
	void moveback();
	virtual void move(const sf::Time& delta);
	

protected:
		sf::Vector2f m_oldplace = STOP;
		sf::Vector2f m_direction = STOP;
};

