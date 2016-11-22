#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <sstream>
#include <iostream>

using namespace std;

const int windowWidth = 1000;
const int windowHeight = 1000;

const float R = 180 / 3.14159265;

const float Pspeed = 20;
const float RMB = 3.14159265 / 180;

class entity
{
public:

	sf::Mouse mouse;
	sf::Text text;

	//player stuff
	sf::Sprite tankHull;
	sf::Sprite tankTurret;
	sf::CircleShape target;
	sf::CircleShape target2;
	sf::CircleShape shape;
	sf::RectangleShape line;
	sf::RectangleShape hullHit;
	sf::RectangleShape hullHit2;

	//neutral stuff
	sf::Clock clock;
	sf::Clock clock2;

	//sf::Font font;

	//enemy stuff
	sf::CircleShape trigger;
	sf::Sprite enemyTurret;
	sf::CircleShape shape2;
	sf::CircleShape turretBase;

};
