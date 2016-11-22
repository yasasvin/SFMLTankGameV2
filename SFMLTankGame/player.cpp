#include "player.h"
#include "projectile.h"

void player::update()
{
	tankHull.setOrigin(sf::Vector2f(42, 35));

	//sf::Texture hull;
	//hull.loadFromFile("Hull.png");

	hullHit.setSize(sf::Vector2f(44, 70));
	hullHit.setOrigin(sf::Vector2f(44, 35));
	hullHit.setFillColor(sf::Color::Transparent);
	hullHit.setOutlineThickness(1);

	hullHit2.setSize(sf::Vector2f(44, 70));
	hullHit2.setOrigin(sf::Vector2f(0, 35));
	hullHit2.setFillColor(sf::Color::Transparent);
	hullHit2.setOutlineColor(sf::Color::Blue);
	hullHit2.setOutlineThickness(1);

	tankTurret.setOrigin(sf::Vector2f(22, 20));
	tankTurret.setPosition(static_cast<sf::Vector2f>(tankHull.getPosition()));

	target2.setRadius(20);
	target2.setOrigin(sf::Vector2f(20, 20));
	target2.setOutlineThickness(1);
	target2.setFillColor(sf::Color::Transparent);

	target.setRadius(8);
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
		hullHit.rotate(-rotation);
		hullHit2.rotate(-rotation);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		tankHull.rotate(rotation);
		hullHit.rotate(rotation);
		hullHit2.rotate(rotation);
	}

}
