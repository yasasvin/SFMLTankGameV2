#include "projectile.h"
#include "player.h"

projectile::projectile()
{
	shape.setRadius(4);
	shape.setOrigin(2, 2);
	shape.setFillColor(sf::Color::Red);

}

void projectile::updateProjectile()
{
	shape.move(Pspeed * cos(shape.getRotation() * RMB), Pspeed * sin(shape.getRotation() * RMB));
}