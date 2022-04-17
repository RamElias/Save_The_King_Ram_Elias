#include "Controller.h"

//-------------------------------------------------------
//Constructor of Controller
Controller::Controller()
	:m_window(sf::VideoMode(WINDOW_WIDTH,WINDOW_LENGTH), "SAVE THE KING", sf::Style::Titlebar | sf::Style::Close)
{
	readlevels(m_levelsName);
}

//-------------------------------------------------------
Controller::~Controller()
{}

//-------------------------------------------------------
//the main func that control the game from start to end
void Controller::run()
{
	createSounds();
	playBGmusic();	// set background music

	m_menu.runScreen(this->m_window); 

	m_gameInfo = GameInfo(); 

	while (m_window.isOpen() && m_levelNum < m_numOfLvls )
	{	
		m_board = Board(m_levelsName[numOfLevel()]); //creat the board

		m_gameInfo.updateGI(m_levelNum, m_board.getlvlTime());

		sf::Clock clockTemp;
		int current = 0;
		m_restartLvl = false;

		while (!m_board.getlvlOver())
		{
			m_board.drawBoard(m_window, current);
			m_gameInfo.draw(m_window, m_board.thiefHasKey(), m_board.calcGift(current));
			m_window.display();

			bool kingKiled = m_board.getKingKiled(); //if king was kiled by dragon

			if (m_gameInfo.getLevelTime() < 0 || (kingKiled)) //time ended or king was eaten
			{
				m_window.clear();
				m_menu.restartScreen(m_window, kingKiled);
				m_restartLvl = true;
				break;
			}

			if (auto event = sf::Event{}; m_window.pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::Closed:
					m_sounds[(int)Sounds::background].stop();
					m_window.close();
					break;
				case sf::Event::KeyPressed:
					handleKeyPressed(event, current);
					break;
				case sf::Event::KeyReleased:
					handleKeyReleased(current);
					break;
				case sf::Event::MouseButtonReleased:  // stopping and resuming background music
					handleMusicBG(event);
					break;
				}
			}
			sf::Time deltaTime = clockTemp.getElapsedTime();
			clockTemp.restart();

			m_board.MoveObj(deltaTime, current); //do move and handleCollisions

			playCollSound(current); 
		}

		if (!m_restartLvl) //finished level successly
		{
			m_sounds[(int)Sounds::win].play();
			m_sounds[(int)Sounds::win].setVolume(5);
			m_levelNum++;
			m_window.clear();
			m_menu.setEndLevel();
			if (m_levelNum < m_numOfLvls) //more levels
				m_menu.runScreen(m_window);
		}

	}
	m_menu.finishScreen(m_window); //last screen
	m_sounds[(int)Sounds::background].stop();
}

//-------------------------------------------------------
void Controller::handleKeyPressed(const sf::Event& event, int& current)
{
	switch (event.key.code)
	{
	case sf::Keyboard::P: //change current player
		if (current == 3)
			current = 0;
		else
			current++;
		break;

	case sf::Keyboard::Up:
		m_board.changeMovingTexture(current, UP);
		break;

	case sf::Keyboard::Down:
		m_board.changeMovingTexture(current, DOWN);
		break;

	case sf::Keyboard::Right:
		m_board.changeMovingTexture(current, RIGHT);
		break;

	case sf::Keyboard::Left:
		m_board.changeMovingTexture(current, LEFT);
		break;
	}
}

//-------------------------------------------------------
void Controller::handleKeyReleased(int current)
{
	m_board.changeMovingTexture(current, STOP);
}

//-------------------------------------------------------
//creat the sound
void Controller::createSounds()
{
	sf::Sound newSound;

	newSound.setBuffer(*ResourceManager::instance().getSound(Sounds::background));
	m_sounds.push_back(newSound);

	newSound.setBuffer(*ResourceManager::instance().getSound(Sounds::collision));
	m_sounds.push_back(newSound);

	newSound.setBuffer(*ResourceManager::instance().getSound(Sounds::win));
	m_sounds.push_back(newSound);

	newSound.setBuffer(*ResourceManager::instance().getSound(Sounds::bonus));
	m_sounds.push_back(newSound);

}

//-------------------------------------------------------
//reas all levels name from levels.txt to levelsname
void Controller::readlevels(std::string levelsname[])
{
	std::ifstream levels;
	levels.open("levels.txt");

	int count = 0;

	while (!levels.eof())
	{
		std::getline(levels, levelsname[count]);
		count++;
	}

	m_numOfLvls = count;
	levels.close();
}

//-------------------------------------------------------
//reas all levels name from levels.txt to levelsname
int Controller::numOfLevel()
{
	if (m_menu.getCreatLevel())
		m_levelNum--;	

	return m_levelNum;
}

//-------------------------------------------------------
void Controller::playBGmusic()
{
	m_sounds[(int)Sounds::background].play();
	m_sounds[(int)Sounds::background].setLoop(true);
	m_sounds[(int)Sounds::background].setVolume(2);
}

//-------------------------------------------------------
//play Collision sound and Bonus sound
void Controller::playCollSound(int current)
{
	if (m_board.hadCollisionCheck(current))
	{
		if (m_sounds[(int) Sounds::collision].getStatus() == sf::Music::Status::Stopped)
		{
			m_sounds[(int)Sounds::collision].play();
			m_sounds[(int)Sounds::collision].setVolume(4);
		}
	}


	if (m_board.hadBonusCheck(current))
	{
		if (m_sounds[(int)Sounds::bonus].getStatus() == sf::Music::Status::Stopped)
		{
			m_sounds[(int)Sounds::bonus].play();
			m_sounds[(int)Sounds::bonus].setVolume(4);
		}
	}

}

//-------------------------------------------------------
void Controller::handleMusicBG(const sf::Event& event)
{
	if (m_gameInfo.MusicIconContains(event))
	{
		if (m_sounds[(int)Sounds::background].getStatus() == sf::SoundSource::Status::Playing)
		{
			m_sounds[(int)Sounds::background].stop();
			m_gameInfo.setMusicIcon(false);
		}
		else
		{
			m_sounds[(int)Sounds::background].play();
			m_gameInfo.setMusicIcon(true);
		}
	}
}