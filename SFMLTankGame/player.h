#pragma once

#include "entity.h"

const float speed = 4;
const float rotation = 3.5;
const float RM = 3.14159265 / 180;

class player : public entity
{
public:
	
	void update();
	void updateMovement();

};
