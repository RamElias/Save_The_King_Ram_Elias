//in this file we Declares the
//Fire class and his members
#pragma once
#include <vector>
#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>
#include "Globals.h"

using std::vector;


class ResourceManager 
{
public:
	~ResourceManager();
	static ResourceManager& instance();
	sf::Texture& GetTexture(enum class TEXTURE_TYPE);
	const sf::Texture* getBackGround();

	static void setScale(int, int);
	sf::Vector2f returnScale();
	double returnSpace();
	double returnMiddleCols();
	double returnMiddleRows();

	sf::Vector2f returnKingPosition();
	static void setKingPosition(sf::Vector2f);

	sf::Font* getFont();

	sf::SoundBuffer* getSound(Sounds);
	sf::Texture* getMusicIcon(bool);


private:
	ResourceManager();
	
	void createBackgrounds();
	void createMusicIcon();
	void createSound();

	std::vector<sf::Texture> m_textures;
	std::vector<sf::Texture> m_musicIcon;
	std::vector<sf::SoundBuffer> m_soundVec;

	sf::Vector2f m_kingPos;
	sf::Vector2f m_scale;
	sf::Font m_font;
	sf::Texture m_background;

	double m_space;
	double m_middleCols;
	double m_middleRows;
};

