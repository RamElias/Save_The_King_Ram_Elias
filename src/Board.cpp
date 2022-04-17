#include "Board.h"
#include "Globals.h"


//-------------------------------------------------------
//Creat Object Type from file 
Board::Board(std::string levelName)
{
	std::ifstream in;
	char a;

	resetPlayerIndex(); //to keep track where each caracter is saved

	in.open(levelName);

	if (!in.is_open()) {
		exit(EXIT_FAILURE);
	}

	in >> m_row;
	in >> m_col;
	in.get(a);
	in >> m_lvlTime;

	ResourceManager::instance().setScale(m_row, m_col); //to calc the scale, cellsgap, widthstart,length

	in.get(a);

	float cellsgap = (float) ResourceManager::instance().returnSpace();
	float widthstart = (float) ResourceManager::instance().returnMiddleCols();
	float length = (float) ResourceManager::instance().returnMiddleRows();

	for (int i = 0; i < m_row; i++)
	{
		float width = widthstart;
		for (int j = 0; j < m_col; j++, width += cellsgap)
		{
			in.get(a);
			//creat all Object
			createObject((ObjectType)a, sf::Vector2f(width, length));
		}
		length += cellsgap;
		in.get(a);
	}

	creatTeleport(); //creat the teleport

	// creat a rect to use to know whice player is current
	m_currentChar.setOutlineColor(sf::Color(63, 81, 181));
	m_currentChar.setOutlineThickness(2.0);
	m_currentChar.setSize(RECTANGLESIZE);
	m_currentChar.setFillColor(sf::Color::Transparent);
	m_currentChar.setScale(ResourceManager::instance().returnScale());
}

//-------------------------------------------------------
//Creat static, player, enemy Object Type
void Board::createObject(ObjectType type, sf::Vector2f position)
{
	int playerIndex;
	std::unique_ptr<Player> Player = createPlayerObject(type, position, playerIndex);
	if (Player)
	{ 
		m_player.push_back(std::move(Player));//creat Player
		savePlayerIndex(playerIndex); //save the player kinde in the arryindex
		return;
	}

	std::unique_ptr<StaticObject> unmovable = createStaticObject(type, position);
	if (unmovable)
	{
		m_static.push_back(std::move(unmovable));//creat static
		return;
	}

	std::unique_ptr<Enemy> Enemy = createEnemyObject(type, position);
	if (Enemy)
	{
		m_enemy.push_back(std::move(Enemy));//creat enemy
		return;
	}

	if (type == ObjectType::TeleportType)
		m_teleportPostion.push_back((position));//save teleport position
}

//-------------------------------------------------------
//creat enemy Object
std::unique_ptr<Enemy> Board::createEnemyObject(ObjectType type, sf::Vector2f position)
{
	switch (type)
	{
	case ObjectType::DwarfType:
		return std::make_unique<Dwarf>(position);

	case ObjectType::DragonType:
		return std::make_unique<Dragon>(position);
	}
	return nullptr;
}

//-------------------------------------------------------
//creat Player Object
std::unique_ptr<Player> Board::createPlayerObject(ObjectType type, sf::Vector2f position, int& player)
{
	switch (type)
	{

	case ObjectType::KingType:
		player = int (PLAYER_INDEX::KingIndex);
		return std::make_unique<King>(position);

	case ObjectType::MageType:
		player = int(PLAYER_INDEX::MageIndex);
		return std::make_unique<Mage>(position);

	case ObjectType::WarriorType:
		player = int(PLAYER_INDEX::WarriorIndex);
		return std::make_unique<Warrior>(position);

	case ObjectType::ThiefType:
		player = int(PLAYER_INDEX::ThiefIndex);
		return std::make_unique<Thief>(position);
	}

	return nullptr;
}

//-------------------------------------------------------
//creat static Object
std::unique_ptr<StaticObject> Board::createStaticObject(ObjectType type, sf::Vector2f position)
{
	switch (type)
	{
	case ObjectType::FireType:
		return std::make_unique<Fire>(position);

	case ObjectType::WallType:
		return std::make_unique<Wall>(position);

	case ObjectType::ThroneType:
		return std::make_unique<Throne>(position);

	case ObjectType::GateType:
		return std::make_unique<Gate>(position);

	case ObjectType::KeyType:
		return std::make_unique<Key>(position);

	case ObjectType::OrkType:
		return std::make_unique<Ork>(position);

	case ObjectType::GiftType:
		return std::make_unique<Gift>(position);
	}
	return nullptr;
}

//-------------------------------------------------------
//creat teleport - satatic Object
void Board::creatTeleport()
{
	for (auto i = size_t(0); i < m_teleportPostion.size(); ++i)
	{
		auto placeX = m_teleportPostion[i];
		i++;
		auto placeY = m_teleportPostion[i];
		//creat two each time
		setTeleport(placeX, placeY);
		setTeleport(placeY, placeX);
	}
}

//-------------------------------------------------------
//creat teleport - satatic Object
void  Board::setTeleport(sf::Vector2f placeX, sf::Vector2f placeY)
{
	std::unique_ptr<StaticObject> newUnmovable = std::make_unique<Teleport>(placeX, placeY);

	m_static.push_back(std::move(newUnmovable));
}

//-------------------------------------------------------
//handleCollisions - in MovengObject type
void Board::handleCollisions(MovingObject& current, bool& teleport, sf::Vector2f& position)
{
	for (auto& unmovable : m_static)
	{
		if (current.checkCollision(*unmovable))
		{
			current.handleCollision(*unmovable);
			teleport = true; 
			position = unmovable->getlocation(); 
		}
	}
	
	for (auto& player : m_player)
	{
		if (current.checkCollision(*player))
			current.handleCollision(*player);
	} 

	for (auto& enemy : m_enemy)
	{
		if (enemy != NULL)
		{
			if (current.checkCollision(*enemy))
				current.handleCollision(*enemy);
		}
	}

	std::erase_if(m_static, [](auto& unmovable)
		{
			return unmovable->isDisposed();
		});

	//to erase dragon if nedded
	std::erase_if(m_enemy, [](auto& enemy)
		{
			return enemy->isDisposed();
		});
}

//-------------------------------------------------------
//creat teleport - satatic Object
void Board::checkPlayer(Player& current, bool teleport, sf::Vector2f position)
{
	// check if king hes thrown
	if (m_player[m_playerIndex[(int)PLAYER_INDEX::KingIndex]]->getThrone())
		m_lvlOver = true;

	//checks if the dragon tached the king
	if (m_player[m_playerIndex[(int)PLAYER_INDEX::KingIndex]]->dragonCatchKingCheck())
		m_kingKiled = true;
	
	//update king position for dragon move
	ResourceManager::setKingPosition(m_player[m_playerIndex[(int)PLAYER_INDEX::KingIndex]]->getPosition());

	//check if warrior nees to creat a key
	if (m_player[m_playerIndex[(int)PLAYER_INDEX::WarriorIndex]]->creatKey())
		m_static.push_back(std::make_unique<Key>(position));

	//checks if player needs to do teleport
	if (teleport == false)
		current.SetInTeleort(false);
}

//-------------------------------------------------------
//creat new fire
void Board::checkEnemy(Enemy& current)
{
	sf::Vector2f place;

	if (current.creatDragonFire(place))
		m_static.push_back(std::make_unique<Fire>(place));
}

//-------------------------------------------------------
//move and handell all player and enmy Object
void Board::MoveObj(const sf::Time& delta, int current)
{
	bool teleport = false; // flag for teleport

	sf::Vector2f position = STOP; // creat key location

	m_player[current]->move(delta); //Player move

	//Player handle Collisions 
	handleCollisions(*m_player[current], teleport, position);

	//Player chacks
	checkPlayer(*m_player[current], teleport, position);

	for (auto& enemy : m_enemy)
	{
		if (enemy != NULL)
		{
			enemy->move(delta); 
			handleCollisions(*enemy, teleport, position); //all enmmys
			checkEnemy(*enemy);
		}
	}

}

//-------------------------------------------------------
//draw player, enemy and static on screen
void Board::drawBoard(sf::RenderWindow& window, int current)
{
	window.clear(WINDOW_COLOR);
	m_currentChar.setPosition(m_player[current]->getPosition());

	for (auto i = size_t(0); i < m_static.size(); ++i)
	{
		m_static[i]->draw(window);
	}

	for (auto i = size_t(0); i < m_player.size(); ++i)
	{
		m_player[i]->draw(window);
	}
	
	for (auto& enemy : m_enemy)
	{
		if(enemy!= NULL)
			enemy->draw(window);
	}

	window.draw(m_currentChar);
}

//-------------------------------------------------------
void Board::changeMovingTexture(int current, sf::Vector2f(direction)){
	m_player[current]->setDirection(direction);
}

//-------------------------------------------------------
bool Board::thiefHasKey(){
	return (m_player[m_playerIndex[(int)PLAYER_INDEX::ThiefIndex]]->hasKey());
}

//-------------------------------------------------------
bool Board::getlvlOver(){
	return m_lvlOver;
}

//-------------------------------------------------------
bool Board::getKingKiled(){
	return m_kingKiled;
}

//-------------------------------------------------------
int Board::getlvlTime(){
	return m_lvlTime;
}

//-------------------------------------------------------
// check if need to make Collosion sound
bool Board::hadCollisionCheck(int current){
	return m_player[current]->hadCollosion();
}

//-------------------------------------------------------
// check if need to make Collosion sound
bool Board::hadBonusCheck(int current){
	return  m_player[current]->getHadBonus();
}

//-------------------------------------------------------
// calc the gift and send back result as int
int Board::calcGift(int current)
{
	int time = NO_GIFT;

	if (m_player[current]->getGift())
	{
		if (m_lvlTime == NO_TIME)
		{
			KillDwarfs();
			return time = KILL_DWARFS;
		}

		switch (rand() % 3)	
		{
		case 0:
			time = rand() % 60 + 1; //add time
			break;
		case 1:
			time = ((rand() % 60) + 1) * -1; //reduce time
			break;
		case 2:
			KillDwarfs(); 
			time = KILL_DWARFS;
			break;
		}		
	}
	
	return time; //if there is no gift
}

//-------------------------------------------------------
// calc the gift and send back result as int
void Board::KillDwarfs()
{
	for (auto& enemy : m_enemy)
	{
		if (enemy != NULL)
			enemy->killDwarf();
	}

	std::erase_if(m_enemy, [](auto& enemy)
		{
			return enemy->isDisposed();
		});

}

//-------------------------------------------------------
// sets player to a num that canot be an index
void Board::resetPlayerIndex()
{
	for (int i = 0; i < MOVING_TEXTURES; i++)
		m_playerIndex[i] = NOT_INDEX;

}

//-------------------------------------------------------
//save each player index in the right arry position of the player index in m_Player
void Board::savePlayerIndex(int player)
{
	int place = 0;

	for (int i = 0; i < MOVING_TEXTURES; i++)
	{
		if (m_playerIndex[i] != NOT_INDEX)
			place++; //the amount of the index in m_Player
	}
	m_playerIndex[player] = place; //sets in the PlayerIndex
}