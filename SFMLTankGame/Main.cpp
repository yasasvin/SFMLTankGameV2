#include <SFML/Graphics.hpp>
using namespace std;
#include <iostream>

#include "player.h"
#include "entity.h"
#include "projectile.h"
#include "enemy.h" 
#include "map.h"

void drawEmptyTiles(Map &map, sf::RenderWindow &window)
{
	for (int row = 0; row < map.COLUMN_COUNT; row++)
	{
		for (int col = 0; col < map.ROW_COUNT; col++)
		{
			Map::Tile tile = map.getTile(col, row);
			if (tile == Map::Tile::TilePink || tile == Map::Tile::TileCyan || tile == Map::Tile::TileRed || tile == Map::Tile::TileOrange || tile == Map::Tile::TileEmpty || tile == Map::Tile::TileDot || tile == Map::Tile::TileEnergizer)
			{

			}
			else
			{
				sf::RectangleShape block;
				block.setPosition(row * 32, col * 32);
				block.setSize(sf::Vector2f(32,32));

				block.setFillColor(sf::Color::Red);

				window.draw(block);
			}
		}

	}
}

int main()
{
	int counter1 = 0;
	int counter2 = 0;
	int counter3 = 0;

	bool drawGridCells = true;
	bool drawEmptyPath = true;


	sf::ContextSettings settings;
	sf::RenderWindow window (sf::VideoMode(windowWidth, windowHeight), "SFML TANKS", sf::Style::Default, settings);
	settings.antialiasingLevel = 8;
	window.setFramerateLimit(60);
	window.setMouseCursorVisible(false);
	
	Map map;

	sf::Event event;


	sf::Clock clock;
	sf::Clock clock2;

	//sf::View mainView(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));
	//sf::View GUI = window.getDefaultView();

	//hull texture
	sf::Texture hull;
	hull.loadFromFile("Hull.png");

	//turret texture
	sf::Texture turret;
	turret.loadFromFile("Turret.png");
	
	//shell vector
	vector<projectile>::const_iterator iter;
	vector<projectile> projectileArray;


	class  player player1;
	player1.tankHull.setTexture(hull);
	player1.tankHull.setPosition(400, 400);

	player1.tankTurret.setTexture(turret);
	player1.target.setOrigin(sf::Vector2f(19, 4));
	player1.target.setPosition(400, 400);

	class enemy enemy1;
	enemy1.enemyTurret.setTexture(turret);

	class projectile projectile1;
	class projectile projectile2;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}

		//collision mapping

		for (int row = 0; row < map.COLUMN_COUNT; row++)
		{
			for (int col = 0; col < map.ROW_COUNT; col++)
			{
				Map::Tile tile = map.getTile(col, row);
				if (tile == Map::Tile::TilePink || tile == Map::Tile::TileCyan || tile == Map::Tile::TileRed || tile == Map::Tile::TileOrange || tile == Map::Tile::TileEmpty || tile == Map::Tile::TileDot || tile == Map::Tile::TileEnergizer)
				{

				}
				else
				{
					sf::RectangleShape block;

					block.setPosition(row * 32, col * 32);
					block.setSize(sf::Vector2f(28, 28));

					block.setFillColor(sf::Color::Blue);

					//collision detection

					if (block.getGlobalBounds().intersects( player1.tankHull.getGlobalBounds()))
					{
						std::cout << "impact" << std::endl;
						player1.tankHull.move(speed* -cos(player1.tankHull.getRotation()* RM), speed * -sin(player1.tankHull.getRotation() * RM));

					}
				}

			}

		}
		window.clear();

		//making projectile shoot once per 1/2 sec
		sf::Time elapsedTime = clock.getElapsedTime();

		if (elapsedTime.asSeconds() >= 0.5)
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				projectile1.shape.setPosition(player1.tankHull.getPosition());
				projectileArray.push_back(projectile1);

				clock.restart();
			}
		}

		//setting up fire direction based on mouse position
		sf::Vector2f currentPosition = player1.tankTurret.getPosition();
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
		projectile1.shape.setRotation(atan2(mousePosition.y - currentPosition.y, mousePosition.x - currentPosition.x) * R);


		// get angle at where enemy located
		sf::Vector2f playerCurrentPosition = player1.tankTurret.getPosition();
		sf::Vector2f enemyCurrentPosition = enemy1.enemyTurret.getPosition();
		
		sf::Time elapsedTime2 = clock2.getElapsedTime(); // limiting enemy fire rate

		if (player1.tankHull.getGlobalBounds().intersects(enemy1.trigger.getGlobalBounds())) // if player enters the view range (circle) 
		{
			enemy1.enemyTurret.setRotation(atan2(playerCurrentPosition.y - enemyCurrentPosition.y, playerCurrentPosition.x - enemyCurrentPosition.x) * R); // rotate to player

			if (elapsedTime2.asSeconds() >= 0.5) // counting timer
			{
				projectile2.shape.setRotation(atan2(playerCurrentPosition.y - enemyCurrentPosition.y, playerCurrentPosition.x - enemyCurrentPosition.x) * R); // projectile face player

				// shoot from enemy turret
				projectile2.shape.setPosition(enemy1.enemyTurret.getPosition());
				projectileArray.push_back(projectile2);

				clock2.restart();
			}
		}

		//updating turret rotation
		player1.tankTurret.setRotation(atan2(mousePosition.y - currentPosition.y, mousePosition.x - currentPosition.x) * R);

		player1.target.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));

		//window.setView(mainView); // main view
		//mainView.setCenter(player1.tankHull.getPosition()); // follow tank

		//update player
		player1.update();
		player1.updateMovement();

		//draw sprites
		window.draw(player1.tankHull);

		// draw projectiles
		counter1 = 0;
		for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
		{
			projectileArray[counter1].updateProjectile();
			window.draw(projectileArray[counter1].shape);
			counter1++;
		}

		window.draw(player1.tankTurret);
		window.draw(player1.target);
		window.draw(enemy1.trigger);
		window.draw(enemy1.enemyTurret);

		enemy1.updateEnemy();
		//enemy1.updateEnemyTurretRotation();

		//window.setView(GUI); // mouse view

		if (drawGridCells)
		{
			if (drawEmptyPath)
			{
				drawEmptyTiles(map, window);
			}

			//drawGrid(window);
		}

		window.display();
	}

	return 0;
}