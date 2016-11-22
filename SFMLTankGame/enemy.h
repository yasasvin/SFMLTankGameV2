#pragma once

#include "entity.h"

class enemy : public entity
{
public:

	//enemy();
	void updateEnemy();
	void updateEnemyTurretRotation();
	void updateEnemyProjectile();

};