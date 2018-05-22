#include <iostream>
#include "EventManager.h"
#include "../States/StateGame.h"

TileSet* EventManager::tileset;

EventManager::EventManager()
{
}


EventManager::~EventManager()
{
}

void EventManager::OnBlockBreak(BlockBreakEvent e)
{
	//std::cout << "Event : Block " << tileset->getBlockById(e.getOldBlock())->getName() << " broken at " << e.getPosition().x << ", " << e.getPosition().y << "\n";

	//Send event to the block
	tileset->getBlockById(e.getOldBlock())->onBlockBreak(e);
}

void EventManager::OnBlockBuild(BlockBuildEvent e)
{
	//std::cout << "Event : Block " << e.getBlock() << " built at " << e.getPosition().x << ", " << e.getPosition().y << "\n";

	//Send event to the block
    tileset->getBlockById(e.getBlock())->onBlockBuild(e);
}

void EventManager::OnGroundPlace(GroundPlaceEvent e)
{
	//std::cout << "Event : Ground " << e.getNewGround() << " placed at " << e.getPosition().x << ", " << e.getPosition().y << "\n";

	//Send event to the block
//    tileset->getGroundById(e.getNewGround())->OnGroundPlaced(e);
//    tileset->getGroundById(e.getNewGround())->OnGroundRePlaced(e);
}

void EventManager::OnPlaceableEnter(PlaceableEnterEvent e)
{
	//Send event to the block
	tileset->getBlockById(e.getBlockId())->onPlaceableEnter(e);

	//Send event to the ground
	tileset->getGroundById(e.getGroundId())->onPlaceableEnter(e);

}

void EventManager::OnPlaceableLeave(PlaceableLeaveEvent e)
{

}

void EventManager::OnBlockInteract(BlockInteractEvent e)
{
    tileset->getBlockById(e.getBlockId())->onBlockInteract(e);
}
