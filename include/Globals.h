#pragma once
#include <SFML\Graphics.hpp>

const int WINDOW_WIDTH = 1200;
const int WINDOW_LENGTH = 800;
const int GAMEINFO_HEIGHT = 100;
const sf::Color WINDOW_COLOR = sf::Color(245, 203, 167);

// for start screen
const sf::Vector2f TITLE_POS = { WINDOW_WIDTH / 2 - 400, 10 };
const sf::Vector2f CENTER = { WINDOW_WIDTH / 2, WINDOW_LENGTH / 2 };
const int HEADER_SIZE = 100;
const int START_CHAR_SIZE = 70;
const float OUTLINE_THICKNESS = 5.0;
const float BOLD_OUTLINE = 10.0;


// for game info
const int CHAR_SIZE = 40;
const float GI_OUTLINE_THICKNESS = 3.0;
const int BUFF_DISTANCE = 10;
const int MUSIC_ICON_SIZE = 60;
const sf::Vector2f MUSIC_ICON_SCALE = { 2.0f, 2.0f };

const sf::Color GAMEINFO_COLOR = sf::Color(146, 43, 33);
const sf::Color GAMEINFO_OUTLINE_COLOR = sf::Color(212, 172, 13);
const sf::Color GAMEINFO_BONUS_COLOR = sf::Color(46, 64, 83);
const sf::Color BONUS_OUTLINE_COLOR = sf::Color(208, 211, 212);

const int SECOND = 1000; // for sleep call

const sf::Vector2f RECTANGLESIZE = sf::Vector2f(65, 65);
const float RECTANGLE_THICKNESS = 2;
const sf::Color GAMEOBJECTCOLOR(65, 105, 225, 0);

const float VER_START = 100;////the vertical distance between the begining of the board and the begining in the window
const float HOR_START = 20;//the horizontal distance between the begining of the board and the begining in the window
const int CELLS_GAP = 60;//the distance between to cells in the board

const std::string TEXTURE_NAME[] = { "king.png", "mage.png", "warrior.png", "thief.png",
									 "throne.png", "wall.png", "gate.png", "fire.png",
									 "ork.png", "key.png", "teleport.png", "dwarf.png", "gift.png", "dragon.png" };

const std::string WELL_DONE = "           well done! :)\n\n you think you can \n              handle\n      the next level?";

const std::string GAME_OVER = "You finished the game ! \n\n           you rock :) \n\nUntil next time friend  \n              BYE BYE";

const enum class TEXTURE_TYPE
{
	KingNum, MageNum, WarriorNum, ThiefNum, ThroneNum,
	WallNum, GateNum, FireNum, OrkNum, KeyNum, TeleportNum, DwarfNum, GiftNum, DragonNum
};

const enum class PLAYER_INDEX
{
	KingIndex, MageIndex, WarriorIndex, ThiefIndex
};

const int NUM_OF_TEXTURES = 14;

const int MOVING_TEXTURES = 4;

const  sf::Vector2f UP = { 0, -1 };
const  sf::Vector2f DOWN = { 0, 1 };
const  sf::Vector2f LEFT = { -1, 0 };
const  sf::Vector2f RIGHT = { 1, 0 };
const  sf::Vector2f STOP = { 0, 0 };

const float SPEED = 250.f;


const enum class ObjectType
{
	KingType = 'K', MageType = 'M', WarriorType = 'W', ThiefType = 'T',
	ThroneType = '@', WallType = '=', GateType = '#', FireType = '*',
	OrkType = '!', KeyType = 'F', TeleportType = 'X', DwarfType = '^',
	GiftType = '$', DragonType = 'D'
};


const enum class Sounds
{
	background, collision, win, bonus
};

//for gift
const int NO_GIFT = 99;
const int NO_TIME = -1; 
const int KILL_DWARFS = 0;

//for playerIndex
const int NOT_INDEX = 5;

//for game info
const int DWARFS_KILED = 2;

//for Dwarf
const double DWARF_MOVE = 0.3;
const int DWARF_RAND = 5;
