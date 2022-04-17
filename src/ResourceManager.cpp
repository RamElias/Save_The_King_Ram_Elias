#include "ResourceManager.h"
#include <iostream>

//-------------------------------------------------------
//destructor :
ResourceManager::~ResourceManager()
{}

//-------------------------------------------------------
//builts one object ResourceManager object only at the first call
//and later just returns the object already created
ResourceManager& ResourceManager::instance() {

	static ResourceManager inst; //only does this ones
	return inst;
}

//-------------------------------------------------------
//constructor : loads the textures and sounds of the game
ResourceManager::ResourceManager()
{
	createBackgrounds(); //loads backgroung image

	createMusicIcon(); //loads images for Music Icon button

	for (int i = 0; i < NUM_OF_TEXTURES; i++) //loads textures
	{
		sf::Texture temp;
		if (!temp.loadFromFile(TEXTURE_NAME[i])) {
			exit(EXIT_FAILURE);
		}
		m_textures.push_back(temp);
	}

	this->m_font.loadFromFile("CrispyTofu.ttf"); //loads font
	createSound();  //loads sounds
}

//-------------------------------------------------------
//loads the sounds of the game
void ResourceManager::createSound()
{
	sf::SoundBuffer newSound;

	newSound.loadFromFile("backgroundMusic.ogg");
	m_soundVec.push_back(newSound);

	newSound.loadFromFile("strikeSound.wav");
	m_soundVec.push_back(newSound);

	newSound.loadFromFile("winSound.wav");
	m_soundVec.push_back(newSound);

	newSound.loadFromFile("bonusSound.wav");
	m_soundVec.push_back(newSound);
}

//-------------------------------------------------------
//loads the textures of the music icon button
void ResourceManager::createMusicIcon()
{
	sf::Texture newImage;

	newImage.loadFromFile("music.png");
	m_musicIcon.push_back(newImage);

	newImage.loadFromFile("music2.png");
	m_musicIcon.push_back(newImage);
}

//-------------------------------------------------------
//returns the textures of the music icon button when on or off
sf::Texture* ResourceManager::getMusicIcon(bool soundOn)
{
	if (soundOn)
		return &this->m_musicIcon[0];
	else
		return &this->m_musicIcon[1];
}

//-------------------------------------------------------
sf::SoundBuffer* ResourceManager::getSound(Sounds record)
{
	return &this->m_soundVec[(int)record];
}

//-------------------------------------------------------
void ResourceManager::createBackgrounds()
{
	m_background.loadFromFile("background1.jpg");
}

//-------------------------------------------------------
const sf::Texture* ResourceManager::getBackGround()
{
	return &this->m_background;
}

//-------------------------------------------------------
sf::Texture& ResourceManager::GetTexture(enum class TEXTURE_TYPE type)
{
	return (m_textures[(int)type]);
}

//-------------------------------------------------------
//calcultaes the scale of the game's objects according to the borad's size of the current level
void ResourceManager::setScale(int rows, int cols)
{
	double numA = (WINDOW_LENGTH - 100) / rows;
	double scaleA = (numA / 80);

	double numB = (WINDOW_WIDTH - 100) / cols;
	double scaleB = (numB / 80);

	double scale = std::min(scaleA, scaleB); //gets the smallest scale
	double num = numB;
	if (scale == scaleA)
		num = numA;

	double space = (num / 5);

	space += (scale * 64);

	double middleCols = space * cols;
	middleCols = (WINDOW_WIDTH - middleCols) / 2;

	double middleRows = space * rows;
	middleRows = ((WINDOW_LENGTH - middleRows) / 2) + 35;

	//keeps the new scale
	ResourceManager::instance().m_scale.x = (float)scale;
	ResourceManager::instance().m_scale.y = (float)scale;
	ResourceManager::instance().m_space = space;
	ResourceManager::instance().m_middleCols = middleCols;
	ResourceManager::instance().m_middleRows = middleRows;
}

//-------------------------------------------------------
double ResourceManager::returnMiddleCols()
{
	return m_middleCols;
}

//-------------------------------------------------------
double ResourceManager::returnMiddleRows()
{
	return m_middleRows;
}

//-------------------------------------------------------
void ResourceManager::setKingPosition(sf::Vector2f position)
{
	ResourceManager::instance().m_kingPos = position;
}

//-------------------------------------------------------
sf::Vector2f ResourceManager::returnKingPosition()
{
	return m_kingPos;
}

//-------------------------------------------------------
sf::Vector2f ResourceManager::returnScale()
{
	return m_scale;
}

//-------------------------------------------------------
double ResourceManager::returnSpace()
{
	return m_space;
}

//-------------------------------------------------------
sf::Font* ResourceManager::getFont()
{
	return &this->m_font;
}