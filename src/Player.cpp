#include "Player.h"

//-------------------------------------------------------
//constructor of player
Player::Player(const  sf::Vector2f& place, sf::Texture& texture)
	:MovingObject(place, texture)
{}

//-------------------------------------------------------
void Player::moveback()
{
	if (m_inTeleport)
		m_hadBonus = false;
	else
		m_hadCollsion = true;

	m_sprit.setPosition(m_oldplace);
}

//-------------------------------------------------------
void Player::movebyteleport(sf::Vector2f& location)
{
	m_sprit.setPosition(location);
}

//-------------------------------------------------------
bool Player::getInTeleort()
{
	return m_inTeleport;
}

//-------------------------------------------------------
void Player::SetInTeleort(bool stat)
{
	m_inTeleport = stat;
}

//-------------------------------------------------------
bool Player::hadCollosion()
{
	bool stat = m_hadCollsion;
	m_hadCollsion = false;
	return stat;
}

//-------------------------------------------------------
bool Player::getHadBonus()
{
	bool stat = m_hadBonus;
	m_hadBonus = false;
	return stat;
}

//-------------------------------------------------------
sf::Vector2f Player::getPosition()
{
	return m_sprit.getPosition();
}