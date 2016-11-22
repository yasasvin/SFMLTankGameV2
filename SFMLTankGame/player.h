#pragma once

#include "entity.h"

const float speed = 4;
const float rotation = 3.5;
const float RM = 3.14159265 / 180;

const float health = 100;

class player : public entity
{
public:
	
	void update();
	void updateMovement();

	int tankHealth = 25;
	bool tankAlive = true;
};
