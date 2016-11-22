#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <sstream>
#include <iostream>

using namespace std;

const int windowWidth = 800;
const int windowHeight = 800;

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
	sf::CircleShape shape;
	sf::CircleShape target;
	sf::RectangleShape line;

	//enemy stuff
	sf::CircleShape trigger;
	sf::Sprite enemyTurret;

};
