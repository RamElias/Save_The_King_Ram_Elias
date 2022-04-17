#pragma once
#include "StartScreen.h"
#include "Globals.h"
#include <fstream>
#include <list>
#include <iostream>

//-------------------------------------------------------
StartScreen::StartScreen()
{
	// intialize title
	this->m_title.setFont(*ResourceManager::instance().getFont());
	m_title.setStyle(sf::Text::Style::Bold | sf::Text::Style::Italic | sf::Text::Style::Underlined);
	m_title.setCharacterSize(100);
	m_title.setPosition(TITLE_POS);
	m_title.setString("Save The King!");
	m_title.setFillColor(sf::Color(52, 152, 219));
	m_title.setOutlineColor(sf::Color::Black);
	m_title.setOutlineThickness(OUTLINE_THICKNESS + 5.0);

	// intialize start button
	this->m_start.setFont(*ResourceManager::instance().getFont());
	m_start.setFillColor(sf::Color(39, 174, 96));
	m_start.setCharacterSize(START_CHAR_SIZE);
	m_start.setPosition({ CENTER.x - 140 , CENTER.y - 200 });
	m_start.setString("Start");
	m_start.setOutlineColor(sf::Color::Black);
	m_start.setOutlineThickness(OUTLINE_THICKNESS);

	// intialize creatLevel button
	this->m_creatLevel.setFont(*ResourceManager::instance().getFont());
	m_creatLevel.setFillColor(sf::Color(255, 160, 0));
	m_creatLevel.setCharacterSize(START_CHAR_SIZE);
	m_creatLevel.setPosition({ CENTER.x - 300, CENTER.y - 75 });
	m_creatLevel.setString("Creat a level");
	m_creatLevel.setOutlineColor(sf::Color::Black);
	m_creatLevel.setOutlineThickness(OUTLINE_THICKNESS);

	// intialize help button
	this->m_help.setFont(*ResourceManager::instance().getFont());
	m_help.setFillColor(sf::Color(255, 160, 0));
	m_help.setCharacterSize(START_CHAR_SIZE);
	m_help.setPosition({ CENTER.x - 100 , CENTER.y + 50 });
	m_help.setString("Help");
	m_help.setOutlineColor(sf::Color::Black);
	m_help.setOutlineThickness(OUTLINE_THICKNESS);

	// intialize exit button
	this->m_exit.setFont(*ResourceManager::instance().getFont());
	m_exit.setFillColor(sf::Color(255, 51, 0));
	m_exit.setCharacterSize(START_CHAR_SIZE);
	m_exit.setPosition({ CENTER.x - 100, CENTER.y + 175 });
	m_exit.setString("Exit");
	m_exit.setOutlineColor(sf::Color::Black);
	m_exit.setOutlineThickness(OUTLINE_THICKNESS);

	// intialize back button
	this->m_back.setFont(*ResourceManager::instance().getFont());
	m_back.setFillColor(sf::Color(255, 160, 0));
	m_back.setCharacterSize(START_CHAR_SIZE);
	m_back.setPosition({ CENTER.x - 500 , CENTER.y - 200 });
	m_back.setString("back");
	m_back.setOutlineColor(sf::Color::Black);
	m_back.setOutlineThickness(OUTLINE_THICKNESS);

	// intialize next button
	this->m_next.setFont(*ResourceManager::instance().getFont());
	m_next.setFillColor(sf::Color(39, 174, 96));
	m_next.setCharacterSize(START_CHAR_SIZE);
	m_next.setPosition({ CENTER.x + 150 , CENTER.y + 175 });
	m_next.setString("next");
	m_next.setOutlineColor(sf::Color::Black);
	m_next.setOutlineThickness(OUTLINE_THICKNESS);

	// intialize well done text
	this->m_wellDone.setFont(*ResourceManager::instance().getFont());
	m_wellDone.setFillColor(sf::Color(255, 160, 0));
	m_wellDone.setCharacterSize(START_CHAR_SIZE - 20);
	m_wellDone.setPosition({ CENTER.x - 340 , CENTER.y - 220 });
	m_wellDone.setString(WELL_DONE);
	m_wellDone.setOutlineColor(sf::Color::Black);
	m_wellDone.setOutlineThickness(OUTLINE_THICKNESS);

	// intialize restart text
	this->m_restart.setFont(*ResourceManager::instance().getFont());
	m_restart.setFillColor(sf::Color(142, 68, 173));
	m_restart.setCharacterSize(START_CHAR_SIZE - 10);
	m_restart.setPosition({ CENTER.x - 400, CENTER.y - 100 });
	m_restart.setString("          Time is up!\n\nInitializes the level..");
	m_restart.setOutlineColor(sf::Color(189, 195, 199));
	m_restart.setOutlineThickness(OUTLINE_THICKNESS);

	// intialize restart by dragon killed text
	this->m_dragonRestart.setFont(*ResourceManager::instance().getFont());
	m_dragonRestart.setFillColor(sf::Color(142, 68, 173));
	m_dragonRestart.setCharacterSize(START_CHAR_SIZE - 10);
	m_dragonRestart.setPosition({ CENTER.x - 400, CENTER.y - 200 });
	m_dragonRestart.setString("OOOH NO!\n\nThe king was eaten by a \n         DRAGON :(\n\nLets try again..");
	m_dragonRestart.setOutlineColor(sf::Color(189, 195, 199));
	m_dragonRestart.setOutlineThickness(OUTLINE_THICKNESS);

	// intialize game over text
	this->m_game_Over.setFont(*ResourceManager::instance().getFont());
	m_game_Over.setFillColor(sf::Color(211, 84, 0));
	m_game_Over.setCharacterSize(60);
	m_game_Over.setPosition({ CENTER.x - 450 , CENTER.y - 225 });
	m_game_Over.setString(GAME_OVER);
	m_game_Over.setOutlineColor(sf::Color::Black);
	m_game_Over.setOutlineThickness(OUTLINE_THICKNESS);

	//set the background
	this->m_background.setSize({ WINDOW_WIDTH, WINDOW_LENGTH });
	this->m_background.setTexture(ResourceManager::instance().getBackGround());

}

//-------------------------------------------------------
//function that draw the screens between the games
void StartScreen::drawScreen(sf::RenderWindow& window)
{
	window.clear();
	window.draw(this->m_background);
	window.draw(this->m_title);

	if (m_inHelp) // in help screen
	{
		drawInst(window, "rules.txt");
		window.draw(this->m_back);
	}
	else if (m_endLevel) // in end level screen
	{
		window.draw(this->m_wellDone);
		window.draw(this->m_next);
		m_exit.setPosition({ CENTER.x - 300, CENTER.y + 175 });
		window.draw(this->m_exit);
	}
	else if (m_inCreatL) //in freate new level screen
	{
		window.draw(this->m_back);
		m_start.setPosition({ CENTER.x + 200 , CENTER.y - 200 });
		window.draw(this->m_start);
		drawInst(window, "createLevelInst.txt");
	}
	else //the first screen
	{
		m_start.setPosition({ CENTER.x - 140 , CENTER.y - 200 });
		window.draw(this->m_start);
		window.draw(this->m_help);
		window.draw(this->m_exit);
		window.draw(this->m_creatLevel);
	}

	window.display();

	if (m_inCreatL)
		doOnce();

}

//-------------------------------------------------------
//run the events on the screens
void StartScreen::runScreen(sf::RenderWindow& window)
{
	while (window.isOpen())
	{
		drawScreen(window);

		if (auto event = sf::Event{}; window.waitEvent(event))
		{
			sf::Vector2f Location;
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonReleased:
				Location = window.mapPixelToCoords
				({ event.mouseButton.x, event.mouseButton.y });
				if (handleClick(Location, window))
					return;
				break;
			case sf::Event::MouseMoved:
				Location = (sf::Vector2f)sf::Mouse::getPosition(window);
				handleMove(Location);
				break;
			}
		}
	}
}

//-------------------------------------------------------
//function that draw the restert screen after killed bt the dragon
void StartScreen::restartScreen(sf::RenderWindow& window, bool kingKiled)
{
	window.clear();
	window.draw(this->m_background);
	window.draw(this->m_title);
	if (kingKiled)
		window.draw(this->m_dragonRestart);
	else
		window.draw(this->m_restart);

	window.display();

	Sleep(5 * SECOND);
}

//-------------------------------------------------------
// handle the clicked on the buttons
bool StartScreen::handleClick(const sf::Vector2f& Location, sf::RenderWindow& window)
{
	if (this->m_start.getGlobalBounds().contains(Location)) // pressed start
	{
		return true;
	}

	if (this->m_next.getGlobalBounds().contains(Location)) // pressed start
	{
		m_creatL = false;
		m_endLevel = false;
		return true;
	}

	if (this->m_help.getGlobalBounds().contains(Location)) // pressed help
	{
		m_inHelp = true;
	}

	if (this->m_creatLevel.getGlobalBounds().contains(Location)) // pressed create
	{
		m_inCreatL = true;
		m_creatL = true;
	}

	if (this->m_back.getGlobalBounds().contains(Location)) // pressed back
	{
		m_inHelp = false;
		m_inCreatL = false;
		m_creatL = false;
		m_doOnce = true;

	}

	if (this->m_exit.getGlobalBounds().contains(Location)) //pressed exit
	{
		window.close();
	}

	return false;
}

//-------------------------------------------------------
//function that hande the mouse move on the buttons and mark/unmark them
void StartScreen::handleMove(const sf::Vector2f& Location)
{
	// mark/unmark start button
	if (this->m_start.getGlobalBounds().contains(Location))
	{
		this->m_start.setOutlineColor(sf::Color(255, 238, 88));
		this->m_start.setOutlineThickness(BOLD_OUTLINE);
	}
	else
	{
		this->m_start.setOutlineColor(sf::Color::Black);
		this->m_start.setOutlineThickness(OUTLINE_THICKNESS);
	}
	// mark/unmark next button
	if (this->m_next.getGlobalBounds().contains(Location))
	{
		this->m_next.setOutlineColor(sf::Color(255, 238, 88));
		this->m_next.setOutlineThickness(BOLD_OUTLINE);
	}
	else
	{
		this->m_next.setOutlineColor(sf::Color::Black);
		this->m_next.setOutlineThickness(OUTLINE_THICKNESS);
	}
	// mark/unmark help button
	if (this->m_help.getGlobalBounds().contains(Location))
	{
		this->m_help.setOutlineColor(sf::Color(255, 238, 88));
		this->m_help.setOutlineThickness(BOLD_OUTLINE);
	}
	else
	{
		this->m_help.setOutlineColor(sf::Color::Black);
		this->m_help.setOutlineThickness(OUTLINE_THICKNESS);
	}
	// mark/unmark back button
	if (this->m_back.getGlobalBounds().contains(Location))
	{
		this->m_back.setOutlineColor(sf::Color(255, 238, 88));
		this->m_back.setOutlineThickness(BOLD_OUTLINE);
	}
	else
	{
		this->m_back.setOutlineColor(sf::Color::Black);
		this->m_back.setOutlineThickness(OUTLINE_THICKNESS);
	}
	// mark/unmark exit button
	if (this->m_exit.getGlobalBounds().contains(Location))
	{
		this->m_exit.setOutlineColor(sf::Color(255, 238, 88));
		this->m_exit.setOutlineThickness(BOLD_OUTLINE);
	}
	else
	{
		this->m_exit.setOutlineColor(sf::Color::Black);
		this->m_exit.setOutlineThickness(OUTLINE_THICKNESS);
	}

	// mark/unmark create button
	if (this->m_creatLevel.getGlobalBounds().contains(Location))
	{
		this->m_creatLevel.setOutlineColor(sf::Color(255, 238, 88));
		this->m_creatLevel.setOutlineThickness(BOLD_OUTLINE);
	}
	else
	{
		this->m_creatLevel.setOutlineColor(sf::Color::Black);
		this->m_creatLevel.setOutlineThickness(OUTLINE_THICKNESS);
	}
}

//-------------------------------------------------------
//draw the last screen after finished all the levels
void StartScreen::finishScreen(sf::RenderWindow& window)
{
	if (window.isOpen())
	{
		window.clear();
		window.draw(this->m_background);
		window.draw(this->m_title);
		window.draw(this->m_game_Over);
		window.display();
		Sleep(8 * SECOND);
	}
}

//-------------------------------------------------------
void StartScreen::setEndLevel()
{
	m_endLevel = true;
}

//-------------------------------------------------------
bool StartScreen::getCreatLevel()
{
	bool stat = m_creatL;
	m_creatL = false;
	return stat;
}

//-------------------------------------------------------
void StartScreen::doOnce()
{
	if (m_doOnce == true)
		system("newlevel.txt");

	m_doOnce = false;
}

//-------------------------------------------------------
//function that get file name and print the text as sf::text on the screen
void StartScreen::drawInst(sf::RenderWindow& window, std::string filename)
{
	std::string line;
	std::ifstream fileRules;
	std::list<sf::Text> textList;
	sf::Text textRules;

	// intialize creatLevel Instructions
	textRules.setFont(*ResourceManager::instance().getFont());
	textRules.setFillColor(sf::Color(211, 84, 0));
	textRules.setCharacterSize(30);
	textRules.setPosition({ CENTER.x - 500 , CENTER.y - 100 });
	textRules.setOutlineColor(sf::Color::Black);
	textRules.setOutlineThickness(OUTLINE_THICKNESS);

	fileRules.open(filename);

	if (!fileRules.is_open())
	{
		exit(EXIT_FAILURE);
	}

	if (fileRules.is_open())
	{
		while (std::getline(fileRules, line))
		{
			//Getting every line of the .txt file and putting it in the 'line' string
			textRules.setString(line);
			textList.push_back(textRules);
		}
	}
	fileRules.close();

	float i = 0;
	for (std::list<sf::Text>::iterator it = textList.begin(); it != textList.end(); ++it)
	{
		sf::Text& text = *it;
		text.setPosition({ CENTER.x - 500, CENTER.y - 100 + i * 50 });
		++i;

		window.draw(text);
	}
}