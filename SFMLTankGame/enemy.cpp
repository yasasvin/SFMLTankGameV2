#include "enemy.h"
#include "entity.h"

void enemy::updateEnemy()
{
	enemyTurret.setOrigin(sf::Vector2f(22, 20));

	turretBase.setRadius(30);
	turretBase.setOrigin(30, 30);
	turretBase.setFillColor(sf::Color(101, 104, 13));
	turretBase.setPosition(static_cast<sf::Vector2f>(enemyTurret.getPosition()));

	trigger.setRadius(300);
	trigger.setFillColor(sf::Color::Transparent);
	trigger.setOutlineColor(sf::Color::Magenta);
	trigger.setOutlineThickness(2);
	trigger.setOrigin(300, 300);

	trigger.setPosition(static_cast<sf::Vector2f>(enemyTurret.getPosition()));
}

void enemy::updateEnemyProjectile()
{
	shape.move(Pspeed * cos(shape.getRotation() * RMB), Pspeed * sin(shape.getRotation() * RMB));
}

textDisplay::textDisplay()
{
	text.setColor(sf::Color::Red);
	text.setCharacterSize(50);
}

void textDisplay::textUpdate()
{

}