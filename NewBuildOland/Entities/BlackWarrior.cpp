#include <cmath>
#include "BlackWarrior.h"

BlackWarrior::BlackWarrior(World *world, unsigned id)
        : LivingEntity(world, id,
                       20, //Health
                       9)  //Inventory size
{
    EntitySpeed = 150;
}

void BlackWarrior::updateMovement(float dt) {
    //Simple AI where the entity moves towards a direction until it finds a block
    //where it changes the direction again

    //Direction : 0 EAST, 1 SOUTH, 2 WEST, 3 NORTH

    sf::Vector2f position = getWorldPos();
    Block *eastBlock = currentWorld->getBlockAt(sf::Vector2i(round(position.x - 0.5) + 1, round(position.y)), false);
    Block *southBlock = currentWorld->getBlockAt(sf::Vector2i(round(position.x), round(position.y - 0.5) + 1), false);
    Block *westBlock = currentWorld->getBlockAt(sf::Vector2i(round(position.x + 0.5) - 1, round(position.y)), false);
    Block *northBlock = currentWorld->getBlockAt(sf::Vector2i(round(position.x), round(position.y + 0.5) - 1), false);

    if (direction == 0 && !eastBlock->hasHitbox()) {
        moveEast(dt);
        return;
    }
    if (direction == 1 && !southBlock->hasHitbox()) {
        moveSouth(dt);
        return;
    }
    if (direction == 2 && !westBlock->hasHitbox()) {
        moveWest(dt);
        return;
    }
    if (direction == 3 && !northBlock->hasHitbox()) {
        moveNorth(dt);
        return;
    }
    prevDir = direction;

    if (!isInverse) {
        if (!eastBlock->hasHitbox()) {
            direction = 0;
        } else if (!southBlock->hasHitbox()) {
            direction = 1;
        } else if (!westBlock->hasHitbox()) {
            direction = 2;
        } else {
            direction = 3;
        }
    } else {
        if (!northBlock->hasHitbox()) {
            direction = 3;
        } else if (!westBlock->hasHitbox()) {
            direction = 2;
        } else if (!southBlock->hasHitbox()) {
            direction = 1;
        } else {
            direction = 0;
        }
    }

    //To prevent the entity to walk in loops
    if(direction + prevDir == 2 || direction + prevDir == 4) {
        isInverse = !isInverse;

        if (!isInverse) {
            if (!eastBlock->hasHitbox()) {
                direction = 0;
            } else if (!southBlock->hasHitbox()) {
                direction = 1;
            } else if (!westBlock->hasHitbox()) {
                direction = 2;
            } else {
                direction = 3;
            }
        } else {
            if (!northBlock->hasHitbox()) {
                direction = 3;
            } else if (!westBlock->hasHitbox()) {
                direction = 2;
            } else if (!southBlock->hasHitbox()) {
                direction = 1;
            } else {
                direction = 0;
            }
        }
    }
}


std::string BlackWarrior::getTextureName() {
    return "CHARACTERS_SHEET_2";
}
std::vector<sf::IntRect> BlackWarrior::getIdleAnim() {
    std::vector<sf::IntRect> idleAnim = std::vector<sf::IntRect>();
    idleAnim.push_back(sf::IntRect(336, 0, 48, 48));

    return idleAnim;
}
std::vector<sf::IntRect> BlackWarrior::getNorthWalkAnim() {
    std::vector<sf::IntRect> walkingAnim = std::vector<sf::IntRect>();
    //Walking to north
    walkingAnim.push_back(sf::IntRect(288, 144, 48, 48));
    walkingAnim.push_back(sf::IntRect(336, 144, 48, 48));
    walkingAnim.push_back(sf::IntRect(384, 144, 48, 48));
    walkingAnim.push_back(sf::IntRect(336, 144, 48, 48));

    return walkingAnim;
}
std::vector<sf::IntRect> BlackWarrior::getSouthWalkAnim() {
    std::vector<sf::IntRect> walkingAnim = std::vector<sf::IntRect>();
    walkingAnim.push_back(sf::IntRect(288, 0, 48, 48));
    walkingAnim.push_back(sf::IntRect(336, 0, 48, 48));
    walkingAnim.push_back(sf::IntRect(384, 0, 48, 48));
    walkingAnim.push_back(sf::IntRect(336, 0, 48, 48));

    return walkingAnim;
}
std::vector<sf::IntRect> BlackWarrior::getEastWalkAnim() {
    std::vector<sf::IntRect> walkingAnim = std::vector<sf::IntRect>();
    walkingAnim.push_back(sf::IntRect(288, 96, 48, 48));
    walkingAnim.push_back(sf::IntRect(336, 96, 48, 48));
    walkingAnim.push_back(sf::IntRect(384, 96, 48, 48));
    walkingAnim.push_back(sf::IntRect(336, 96, 48, 48));

    return walkingAnim;
}
std::vector<sf::IntRect> BlackWarrior::getWestWalkAnim() {
    std::vector<sf::IntRect> walkingAnim = std::vector<sf::IntRect>();
    walkingAnim.push_back(sf::IntRect(288, 48, 48, 48));
    walkingAnim.push_back(sf::IntRect(336, 48, 48, 48));
    walkingAnim.push_back(sf::IntRect(384, 48, 48, 48));
    walkingAnim.push_back(sf::IntRect(336, 48, 48, 48));

    return walkingAnim;
}
