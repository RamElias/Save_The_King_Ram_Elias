//in this file we Declares the
//Main textures class and his members
#pragma once
#include "Object.h"

class StaticObject : public Object
{
public: 
	virtual ~StaticObject() {}
	StaticObject(const  sf::Vector2f&, sf::Texture&);
	sf::Vector2f getlocation();
protected:

};

