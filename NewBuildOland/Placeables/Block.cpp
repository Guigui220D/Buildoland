#include "Block.h"
#include "../Events/EventManager.h"

Block::Block(sf::IntRect textureRect, std::string name, sf::Color mapColor, bool hasHitbox, bool hasVolume, sf::IntRect side) : Placeable(textureRect, name, mapColor)
, mHasHitbox(hasHitbox), mHasVolume(hasVolume), sideRect(side)
{
}

Block::~Block()
{
}

bool Block::hasHitbox() {
	return mHasHitbox;
}

bool Block::hasVolume()
{
	return mHasVolume;
}

sf::IntRect Block::getSideRect()
{
	return sideRect;
}

sf::Color Block::getSideTint()
{
	if (sideRect == sf::IntRect())
		return sf::Color(127, 127, 127);
	return sf::Color::White;
}


//Event methods
void Block::OnBlockBuild(BlockBuildEvent e) {
	Sound* blockPlaceSound = e.getState()->getSoundManager()->getSound("blockPlace.ogg");
	blockPlaceSound->setVolume(30);
	blockPlaceSound->play();

}
void Block::OnBlockBreak(BlockBreakEvent e) {

}
