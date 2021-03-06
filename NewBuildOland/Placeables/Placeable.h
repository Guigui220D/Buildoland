#pragma once
#include <SFML\Graphics.hpp>
#include "Item.h"

class PlaceableEnterEvent;
class PlaceableLeaveEvent;


class Placeable : public Item
{
public:
	Placeable(sf::IntRect textureRect = sf::IntRect(), std::string name = "", sf::Color mapColor = sf::Color(255, 255, 255));
	~Placeable();
	sf::Color getColor();
	sf::IntRect getTextureRect();

    virtual sf::IntRect getItemTextureRect() const override;

	virtual void onPlaceableEnter(PlaceableEnterEvent e);
	virtual void onPlaceableLeave(PlaceableLeaveEvent e);

	bool isPlaceable() override;
	bool isGround() override = 0;

	inline void setTileId(unsigned short identifier) { tileId = identifier; }
	inline unsigned short getTileId() const { return tileId; }

protected:
	//Used to get the right texture from the tileset
	sf::IntRect textureRect;
	sf::Color mapColor;

	unsigned short tileId = 0;
};

