#pragma once

#include "entity.h"

class projectile : public entity
{
public:

	projectile();
	void updateProjectile();
	bool destroyProjectile = false;

};

class enemyProjectile : public entity
{
public:

	enemyProjectile();
	void updateEnemyProjectile();

};