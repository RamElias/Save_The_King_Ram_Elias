#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class GameInfo
{
public:
	GameInfo();
	void draw(sf::RenderWindow& ,bool, int);

	bool getUnlimtedTime() { return  m_unLimited; }
	void updateTime(int);
	void updateKey(bool hasKey);
	float getLevelTime() { return m_levelTime; }

	bool MusicIconContains(const sf::Event&) const;
	void setMusicIcon(bool);
	void updateGI(int levelNum, int time);
private:
	sf::Clock m_Timer;
	sf::Clock m_clockDraw;

	float m_levelTime = 0;
	bool m_unLimited =false;
	bool m_dwarf = false;
	bool m_inc = false;
	bool m_dec = false;
	int m_dwarfKilled = 0;
	
	sf::Text m_time;
	sf::Text m_levelNum;
	sf::Text m_thiefHasKey;
	sf::Text m_dwarfPic;
	sf::Text m_incPic;
	sf::Text m_decPic;
	sf::Sprite m_musicIcon;
};
