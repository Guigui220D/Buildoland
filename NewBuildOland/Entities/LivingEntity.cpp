#include <math.h>
#include "LivingEntity.h"
#include "../States/StateGame.h"
#include "../Events/EventManager.h"

LivingEntity::LivingEntity(World *world, unsigned id, unsigned short maxHealth, unsigned short inventorySize)
    : PhysicEntity(world, id)
    , inventory(inventorySize)
    , health(maxHealth)
{

}
void LivingEntity::init(float posX, float posY) {
    setSize(sf::Vector2f(80, 80));
    setFillColor(sf::Color::White);
    setOrigin(getSize().x / 2, getSize().y / 2);
    setOnMapColor(sf::Color(0, 255, 0));

    setPosition(sf::Vector2f(posX * StateGame::TILE_SIZE, posY * StateGame::TILE_SIZE));

    sf::Texture* t = game->getAssetManager()->getTexture(getTextureName());
    setTexture(t);

    hitboxWidth = 0.75f;
    hitboxHeightBottom = -0.8f;
    hitboxHeightTop = 1.1f;

    initAnimations();
}

float LivingEntity::animInterval() {
    return 0.12;
}
void LivingEntity::initAnimations() {
    animations = Animation();
    animations.setInterval(animInterval());

    //add all the animations
    animations.addAnimation(getIdleAnim());
    animations.addAnimation(getNorthWalkAnim());
    animations.addAnimation(getSouthWalkAnim());
    animations.addAnimation(getEastWalkAnim());
    animations.addAnimation(getWestWalkAnim());
}

void LivingEntity::update(float dt) {
    //The movement byte is used as a flag to choose the right animation
    movement = 0;

    //Let the children classes
    updateMovement(dt);

    //Select the appropriate animation and set it as texture displayed
    selectAnimation();
    setTextureRect(animations.getRect());

    if (health <= 0)
        mustBeRemoved = true;
}

void LivingEntity::selectAnimation() {
    //Choice of animation
    int anim = 0;
    if (movement & 0b1000)
        anim = 4;
    if (movement & 0b0100)
        anim = 3;
    if (movement & 0b0010)
        anim = 2;
    if (movement & 0b0001)
        anim = 1;
    animations.selectAnimation(anim);
}

void LivingEntity::moveNorth(float dt) {
    sf::Vector2f oldpos = getPosition();
    setPosition(sf::Vector2f(oldpos.x, oldpos.y - EntitySpeed * dt));

    movement += 1 << 0;

    //Reset move if it touches block
    if (touchesBlock())
        setPosition(oldpos);
}
void LivingEntity::moveSouth(float dt) {
    sf::Vector2f oldpos = getPosition();
    setPosition(sf::Vector2f(oldpos.x, oldpos.y + EntitySpeed * dt));

    movement += 1 << 1;

    //Reset move if it touches block
    if (touchesBlock())
        setPosition(oldpos);
}
void LivingEntity::moveEast(float dt) {
    sf::Vector2f oldpos = getPosition();
    setPosition(sf::Vector2f(oldpos.x + EntitySpeed * dt, oldpos.y));

    movement += 1 << 2;

    //Reset move if it touches block
    if (touchesBlock())
        setPosition(oldpos);
}
void LivingEntity::moveWest(float dt) {
    sf::Vector2f oldpos = getPosition();
    setPosition(sf::Vector2f(oldpos.x - EntitySpeed * dt, oldpos.y));

    movement += 1 << 3;

    //Reset move if it touches block
    if (touchesBlock())
        setPosition(oldpos);
}

Inventory* LivingEntity::getInventory() {
    return &inventory;
}
