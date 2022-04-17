#pragma once

#include "SFML/Graphics.hpp"
#include <vector>
#include <string>
//#include <sstream>
#include <fstream>
//#include <iostream>
#include <memory>
#include "Object.h"
#include "Globals.h"
#include "ResourceManager.h"
#include "MovingObject.h"
#include "StaticObject.h"
#include "Player.h"
#include "Enemy.h"
#include "StaticInclude/Fire.h"
#include "StaticInclude/Ork.h"
#include "StaticInclude/key.h"
#include "StaticInclude/Teleport.h"
#include "StaticInclude/Wall.h"
#include "StaticInclude/Throne.h"
#include "StaticInclude/Gate.h"
#include "StaticInclude/Gift.h"
#include "MovingInclude/Mage.h"
#include "MovingInclude/Warrior.h"
#include "MovingInclude/Thief.h"
#include "MovingInclude/King.h"
#include "MovingInclude/Dwarf.h"
#include "MovingInclude/Dragon.h"


using std::vector;

class Board
{
public:
	Board() {}
	Board(std::string levelName);
	//~Board();
	
	void createObject(ObjectType type, sf::Vector2f position);
	std::unique_ptr<Player> createPlayerObject(ObjectType, sf::Vector2f, int&);
	std::unique_ptr<StaticObject> createStaticObject(ObjectType type, sf::Vector2f position);
	std::unique_ptr<Enemy> createEnemyObject(ObjectType type, sf::Vector2f position);

	void drawBoard(sf::RenderWindow&, int);

	void changeMovingTexture(int, sf::Vector2f (direction));
	void MoveObj(const sf::Time& delta, int);

	void handleCollisions(MovingObject&, bool&, sf::Vector2f&);

	bool thiefHasKey();
	bool getlvlOver();
	int getlvlTime();

	bool hadCollisionCheck(int);
	int calcGift(int);
	
	bool hadBonusCheck(int );

	void creatTeleport();
	void setTeleport(sf::Vector2f, sf::Vector2f);

	void resetPlayerIndex();
	void savePlayerIndex(int);

	void checkPlayer(Player& ,bool ,sf::Vector2f);
	void checkEnemy(Enemy& current);

	bool getKingKiled();
	void KillDwarfs();


private:
	vector<std::unique_ptr<Player>> m_player;// movingObject or Player ?
	vector<std::unique_ptr<StaticObject>> m_static; // static Object?
	vector<std::unique_ptr<Enemy>> m_enemy; // Dwarf?// Moving Object?

	bool m_kingKiled = false;
	bool m_lvlOver = false;
	bool m_killDwarf = false;
	int m_row = 0 ;   //number of the rows of the board
	int m_col = 0;   //number of the columns of the board
	int m_lvlTime = -1;
	
	sf::RectangleShape m_currentChar;

	std::vector<sf::Vector2f> m_teleportPostion;

	int m_playerIndex[4] = { 0 };

};
