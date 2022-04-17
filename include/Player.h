//in this file we Declares the
//Main textures class and his members
#pragma once
#include <SFML\Graphics.hpp>
#include "MovingObject.h"

class Player : public MovingObject
{
public:
	Player(const  sf::Vector2f&, sf::Texture&);
	virtual ~Player() {}

	void moveback(); //all player
	bool getHadBonus(); // all player check if needs to make good sound

	//teleport for all player
	void SetInTeleort(bool stat); 
	void movebyteleport(sf::Vector2f& location);
	bool getInTeleort();

	bool hadCollosion(); // all player check if needs to make bad sound
	sf::Vector2f getPosition(); // all player to set the rect in board // NEED TO CHANG?

	virtual bool dragonCatchKingCheck() { return false; } //check if dragon tached king

	virtual bool getGift() { return false; } // all player picked gift  

	virtual bool hasKey() { return false; } // thief hes key?
	virtual bool creatKey() { return false; } //warrior seys creat key
	virtual bool getThrone() { return false; } //king got throne?

protected:
	bool m_hadCollsion = false;
	bool m_hadBonus = false;
	bool m_inTeleport = false;
};

