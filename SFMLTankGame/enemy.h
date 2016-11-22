#pragma once

#include "entity.h"

class enemy : public entity
{
public:

	//enemy();
	void updateEnemy();
	void updateEnemyProjectile();

	int hp = 5;
	bool alive = true;
};

class textDisplay : public entity
{
public:

	string textString = "0000";

	textDisplay();
	void textUpdate();
};