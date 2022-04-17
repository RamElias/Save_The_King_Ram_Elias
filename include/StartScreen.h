#pragma once
#include <SFML/Graphics.hpp>
#include "ResourceManager.h"
#include "Windows.h"

class StartScreen
{
public:
	StartScreen(); 

	void runScreen(sf::RenderWindow&);
	void restartScreen(sf::RenderWindow& window, bool);
	void setEndLevel();

	void drawScreen(sf::RenderWindow&);

	bool getCreatLevel();

	void finishScreen(sf::RenderWindow&);

	void doOnce();

private:
	bool m_inHelp = false;
	bool m_endLevel = false;

	sf::Font m_font;
	sf::Text m_title;
	sf::Text m_start;
	sf::Text m_help;
	sf::Text m_back;
	sf::Text m_wellDone;
	sf::Text m_restart;
	sf::Text m_dragonRestart;
	sf::Text m_next;
	sf::Text m_exit;
	sf::Text m_creatLevel;
	sf::Text m_game_Over;
	sf::RectangleShape m_background;

	bool m_inCreatL = false;
	bool m_creatL = false;
	bool m_doOnce = true;
	
	void drawInst(sf::RenderWindow&, std::string);
	bool handleClick(const sf::Vector2f&, sf::RenderWindow&);
	void handleMove(const sf::Vector2f&);
};