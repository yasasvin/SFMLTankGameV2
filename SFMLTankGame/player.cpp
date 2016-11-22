#include "player.h"
#include "projectile.h"

void player::update()
{
	tankHull.setOrigin(sf::Vector2f(42, 35));
	tankTurret.setOrigin(sf::Vector2f(22, 20));
	tankTurret.setPosition(static_cast<sf::Vector2f>(tankHull.getPosition()));

	target.setRadius(8);
	target.setFillColor(sf::Color::Transparent);
	target.setOutlineColor(sf::Color::Red);
	target.setOutlineThickness(1);
	target.setOrigin(sf::Vector2f(8, 8));
}

void player::updateMovement()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		tankHull.move(speed * cos(tankHull.getRotation() * RM), speed * sin(tankHull.getRotation() * RM));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		tankHull.move(speed * -cos(tankHull.getRotation() * RM), speed * -sin(tankHull.getRotation() * RM));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		tankHull.rotate(-rotation);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		tankHull.rotate(rotation);
	}

}
