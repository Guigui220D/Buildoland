#include "MazeWorld.h"
#include "../States/StateGame.h"

MazeWorld::MazeWorld(StateGame& stateGame)
	: World(stateGame, "mazeworld")
{
	loadWorld();
	playerPos = sf::Vector2u(1, 1);
}


MazeWorld::~MazeWorld()
{
}

void MazeWorld::generateWorld() {
	//Set the world size
	worldSize = sf::Vector2u(25, 25);
	unsigned short const DEFAULT_GROUND = 3;
	unsigned short const DEFAULT_BLOCK = 0;

	for(unsigned int i = 0; i < worldSize.x * worldSize.y; i++) {
		groundIds.push_back(DEFAULT_GROUND);
		blockIds.push_back(DEFAULT_BLOCK);
	}

	for(unsigned int x = 2; x < worldSize.x; x++) {
		for (unsigned int y = 2; y < worldSize.y; y++) {
			if(x % 2 == 0 && y % 2 == 0) {
				setBlockId(x, y, 1);
			}
			if (x % 2 == (y - 1) % 2 && (rand() % 2 == 1) || (x == 2 || x == worldSize.x - 1 || y == 2 || y == worldSize.y - 1)) {
				setBlockId(x, y, 1);
			}
		}
	}
}
