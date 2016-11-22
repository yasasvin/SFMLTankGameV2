#include "projectile.h"
#include "player.h"

projectile::projectile()
{
	shape.setRadius(4);
	shape.setOrigin(2, 2);
	shape.setFillColor(sf::Color::Yellow);

}

enemyProjectile::enemyProjectile()
{
	shape2.setRadius(4);
	shape2.setOrigin(2, 2);
	shape2.setFillColor(sf::Color::Red);

}

void projectile::updateProjectile()
{
	shape.move(Pspeed * cos(shape.getRotation() * RMB), Pspeed * sin(shape.getRotation() * RMB));
}

void enemyProjectile::updateEnemyProjectile()
{
	shape2.move(Pspeed * cos(shape2.getRotation() * RMB), Pspeed * sin(shape2.getRotation() * RMB));
}