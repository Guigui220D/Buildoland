#include "stdafx.h"
#include "BlockEntity.h"


BlockEntity::BlockEntity(World* world, sf::Vector2u tile, unsigned short blockId)
{
	setFillColor(sf::Color(0, 0, 0, 0));
	setSize(sf::Vector2f(StateGame::TILE_SIZE, StateGame::TILE_SIZE));
	setOrigin(sf::Vector2f(0.5f * StateGame::TILE_SIZE, 0.5f * StateGame::TILE_SIZE));
	blockPosition = tile;
	setPosition(sf::Vector2f(tile.x * StateGame::TILE_SIZE, tile.y * StateGame::TILE_SIZE));
	id = blockId;
}


BlockEntity::~BlockEntity()
{
}

void BlockEntity::OnInteract()
{
}