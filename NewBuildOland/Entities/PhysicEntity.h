#pragma once
#include "Entities.h"

class PhysicEntity : public Entities
{
public:
	PhysicEntity();
	~PhysicEntity();
	virtual void update(double delta) override;
	int touchesBlock();
protected:
	//The height of the hitbox (1 means equals to the rectangleshape size)
	//It starts from the middle of the rectangle
	float hitboxHeight = 1;
	//The width of the hitbox, always centered on the horizontal middle
	float hitboxWidth = 1;
};

