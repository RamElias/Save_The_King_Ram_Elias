#pragma once
#include <iostream>
#include "GameInfo.h"
#include "ResourceManager.h"

//-------------------------------------------------------
//initializes texts -font, position, color... 
GameInfo::GameInfo()
{
	this->m_time.setFont(*ResourceManager::instance().getFont());
	this->m_time.setCharacterSize(CHAR_SIZE);
	this->m_time.setPosition(50, BUFF_DISTANCE);
	this->m_time.setFillColor(GAMEINFO_COLOR);
	this->m_time.setOutlineColor(GAMEINFO_OUTLINE_COLOR);
	this->m_time.setOutlineThickness(GI_OUTLINE_THICKNESS);

	this->m_levelNum.setFont(*ResourceManager::instance().getFont());
	this->m_levelNum.setCharacterSize(CHAR_SIZE);
	this->m_levelNum.setPosition(430, BUFF_DISTANCE);
	this->m_levelNum.setFillColor(GAMEINFO_COLOR);
	this->m_levelNum.setOutlineColor(GAMEINFO_OUTLINE_COLOR);
	this->m_levelNum.setOutlineThickness(GI_OUTLINE_THICKNESS);

	this->m_thiefHasKey.setFont(*ResourceManager::instance().getFont());
	this->m_thiefHasKey.setCharacterSize(CHAR_SIZE);
	this->m_thiefHasKey.setPosition(700, BUFF_DISTANCE);
	this->m_thiefHasKey.setFillColor(GAMEINFO_COLOR);
	this->m_thiefHasKey.setOutlineColor(GAMEINFO_OUTLINE_COLOR);
	this->m_thiefHasKey.setOutlineThickness(GI_OUTLINE_THICKNESS);

	this->m_dwarfPic.setFont(*ResourceManager::instance().getFont());
	this->m_dwarfPic.setCharacterSize(CHAR_SIZE);
	this->m_dwarfPic.setPosition(330, BUFF_DISTANCE + 50);
	this->m_dwarfPic.setFillColor(GAMEINFO_BONUS_COLOR);
	this->m_dwarfPic.setOutlineColor(BONUS_OUTLINE_COLOR);
	this->m_dwarfPic.setOutlineThickness(GI_OUTLINE_THICKNESS);
	this->m_dwarfPic.setString("Dwarves were killed!");

	this->m_incPic.setFont(*ResourceManager::instance().getFont());
	this->m_incPic.setCharacterSize(CHAR_SIZE);
	this->m_incPic.setPosition(420, BUFF_DISTANCE + 50);
	this->m_incPic.setFillColor(GAMEINFO_BONUS_COLOR);
	this->m_incPic.setOutlineColor(BONUS_OUTLINE_COLOR);
	this->m_incPic.setOutlineThickness(GI_OUTLINE_THICKNESS);
	this->m_incPic.setString("more time !");

	this->m_decPic.setFont(*ResourceManager::instance().getFont());
	this->m_decPic.setCharacterSize(CHAR_SIZE);
	this->m_decPic.setPosition(420, BUFF_DISTANCE + 50);
	this->m_decPic.setFillColor(GAMEINFO_BONUS_COLOR);
	this->m_decPic.setOutlineColor(BONUS_OUTLINE_COLOR);
	this->m_decPic.setOutlineThickness(GI_OUTLINE_THICKNESS);
	this->m_decPic.setString("less time !");

	this->m_musicIcon.setTexture(*ResourceManager::instance().getMusicIcon(true));
	this->m_musicIcon.setPosition(WINDOW_WIDTH - MUSIC_ICON_SIZE, WINDOW_LENGTH - MUSIC_ICON_SIZE);
	this->m_musicIcon.scale(MUSIC_ICON_SCALE);
}

//-------------------------------------------------------
//updates the current game level information
void GameInfo::updateGI(int levelNum, int time)
{
	m_unLimited = false;
	m_dwarfKilled = KILL_DWARFS;
	this->m_dwarfPic.setString("Dwarves were killed!");

	//updates time
	if (time == NO_TIME) {
		time++;
		m_unLimited = true;
	}
	m_levelTime = (float)time;

	this->m_levelNum.setString("Level:" + std::to_string(levelNum));
}

//-------------------------------------------------------
//draws the game updated information
void GameInfo::draw(sf::RenderWindow& window, bool hasKey, int timeGift)
{
	if (m_clockDraw.getElapsedTime().asSeconds() > 2) //shows a message for 2 seconds when got gift
	{
		m_dwarf = m_inc = m_dec = false;

		if (timeGift == KILL_DWARFS) //kills dwarves gift
		{
			m_dwarf = true;
			m_dwarfKilled++;
			m_clockDraw.restart();
		}
		else if (timeGift > 0 && timeGift < NO_GIFT) //more time gift
		{
			m_inc = true;
			m_clockDraw.restart();
		}
		else if (timeGift < 0) //less time gift
		{
			m_dec = true;
			m_clockDraw.restart();
		}
	}

	if (timeGift == NO_GIFT) //no gift
		timeGift = 0;

	updateTime(timeGift); //calculates the level time

	updateKey(hasKey); //updates if thief has key

	window.draw(this->m_musicIcon);
	window.draw(this->m_time);
	window.draw(this->m_levelNum);
	window.draw(this->m_thiefHasKey);

	//if got gift draws message
	if (m_dwarf)
	{
		if (m_dwarfKilled == DWARFS_KILED)
			this->m_dwarfPic.setString("      Empty gift!");

		window.draw(this->m_dwarfPic);

	}
	else if (m_inc)
		window.draw(this->m_incPic);
	else if (m_dec)
		window.draw(this->m_decPic);
}

//-------------------------------------------------------
//calculates and updates the level's time 
void GameInfo::updateTime(int timeGift)
{
	if (m_unLimited) //if no limited time
	{
		this->m_levelTime += this->m_Timer.getElapsedTime().asSeconds();
		this->m_time.setString("Time passed:" + std::to_string((int)this->m_levelTime));
	}
	else //if has limited time
	{
		this->m_levelTime -= (this->m_Timer.getElapsedTime().asSeconds() - timeGift);
		this->m_time.setString("Time left: " + std::to_string((int)this->m_levelTime));
	}
	this->m_Timer.restart();
}

//-------------------------------------------------------
//updates if thief has key
void GameInfo::updateKey(bool hasKey)
{
	if (hasKey)
		this->m_thiefHasKey.setString("Thief has key: yes");
	else
		this->m_thiefHasKey.setString("Thief has key: No");
}

//-------------------------------------------------------
bool GameInfo::MusicIconContains(const sf::Event& evnt) const
{
	if (this->m_musicIcon.getGlobalBounds().contains((float)evnt.mouseButton.x, (float)evnt.mouseButton.y))
		return true;
	return false;
}

//-------------------------------------------------------
void GameInfo::setMusicIcon(bool isSoundOn)
{
	this->m_musicIcon.setTexture(*ResourceManager::instance().getMusicIcon(isSoundOn));
}