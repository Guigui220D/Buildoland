#pragma once
//#include "Entities.h"
//#include "PhysicEntity.h"
//#include "../Utils/Animation.h"
//#include "../Utils/Inventory.h"
#include "LivingEntity.h"

class Player : public LivingEntity
{
public:
	Player(World *world, sf::String displayName, unsigned int id);
	~Player();
	void drawMore(sf::RenderWindow& window) override;

	inline void setCurrentWorld(World* newWorld) { currentWorld = newWorld; };

	inline sf::String getDisplayName() { return nameText.getString(); };

private:
	sf::Vector2u lastPos;

	void initInventory(World* currentWorld);

	sf::Font font;

protected:
	std::string getTextureName() override;
	std::vector<IntRect> getIdleAnim() override;
	std::vector<IntRect> getNorthWalkAnim() override;
	std::vector<IntRect> getSouthWalkAnim() override;
	std::vector<IntRect> getEastWalkAnim() override;
	std::vector<IntRect> getWestWalkAnim() override;

	void updateMovement(double dt) override;

	sf::Text nameText; //Display name
};

