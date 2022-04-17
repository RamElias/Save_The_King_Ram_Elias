#pragma once

#include "Board.h"
#include "Globals.h"
#include "StartScreen.h"
#include "GameInfo.h"
//#include "Object.h"
//#include "MovingObject.h"
//#include "StaticObject.h"
#include <string>
#include <vector>
//#include <sstream>
#include <fstream>
//#include <iostream>
using std::vector;
using std::ifstream;

class Controller: public Board
{
public:

	Controller();
	~Controller();

	void run();
	
	void handleKeyPressed(const sf::Event&, int&);

	void handleKeyReleased(int);

	void createSounds();

	void playBGmusic();

	void playCollSound(int);

	int numOfLevel();
	
	void readlevels(std::string[]);

	void handleMusicBG(const sf::Event& );

private:
	int m_levelNum = 1;
	int m_numOfLvls = 0;
	bool m_restartLvl = false;
	Board m_board;
	GameInfo m_gameInfo;
	StartScreen m_menu;
	sf::RenderWindow m_window;
	std::string m_levelsName[10];

	std::vector<sf::Sound> m_sounds;
};


