#include "enemy.h"
#include "entity.h"

void enemy::updateEnemy()
{
	enemyTurret.setOrigin(sf::Vector2f(22, 20));
	enemyTurret.setPosition(300, 300);

	trigger.setRadius(300);
	trigger.setFillColor(sf::Color::Transparent);
	trigger.setOutlineColor(sf::Color::Magenta);
	trigger.setOutlineThickness(2);
	trigger.setOrigin(300, 300);

	trigger.setPosition(static_cast<sf::Vector2f>(enemyTurret.getPosition()));
}

void enemy::updateEnemyTurretRotation()
{
	sf::Vector2f playerCurrentPosition = tankTurret.getPosition();
	sf::Vector2f enemyCurrentPosition = enemyTurret.getPosition();
	enemyTurret.setRotation(atan2(playerCurrentPosition.y - enemyCurrentPosition.y, playerCurrentPosition.x - enemyCurrentPosition.x) * R);
}

void enemy::updateEnemyProjectile()
{
	shape.move(Pspeed * cos(shape.getRotation() * RMB), Pspeed * sin(shape.getRotation() * RMB));
}