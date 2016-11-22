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
				block.setPosition(row * 80, col * 80);
				block.setSize(sf::Vector2f(75, 75));

				block.setFillColor(sf::Color::Red);

				window.draw(block);
			}
		}

	}
}

int main()
{
	bool drawGridCells = true;
	bool drawEmptyPath = true;

	int counter1 = 0;
	int counter2 = 0;

	sf::ContextSettings settings;
	sf::RenderWindow window (sf::VideoMode(windowWidth, windowHeight), "SFML TANKS", sf::Style::Default, settings);
	settings.antialiasingLevel = 8;
	window.setFramerateLimit(60);
	window.setMouseCursorVisible(false);
	
	Map map;

	sf::Event event;

	sf::View mainView(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));

	//hull texture
	sf::Texture hull;
	hull.loadFromFile("Hull.png");

	//turret texture
	sf::Texture turret;
	turret.loadFromFile("Turret.png");


	//turret texture
	sf::Texture enemyTurret;
	enemyTurret.loadFromFile("enemyTurret.png");

	class entity entity1;

	//shell iterator
	vector<projectile>::const_iterator iter;
	vector<projectile> projectileArray;
	class projectile projectile1;

	//enemy iterator
	vector<enemy>::const_iterator iter2;
	vector<enemy> enemyArray;
	class enemy enemy1;
	enemy1.enemyTurret.setTexture(enemyTurret);
	enemy1.enemyTurret.setPosition(300, 300);
	enemy1.enemyTurret.setOrigin(sf::Vector2f(22, 20));
	enemy1.trigger.setPosition(300, 300);
	enemyArray.push_back(enemy1);

	//enemy shell iterator
	vector<enemyProjectile>::const_iterator iter3;
	vector<enemyProjectile> enemyProjectileArray;
	class enemyProjectile projectile2;

	//player iterator
	vector<player>::const_iterator iter4;
	vector<player> playerArray;
	class  player player1;
	player1.tankHull.setTexture(hull);
	player1.tankHull.setPosition(400, 400);
	player1.tankTurret.setTexture(turret);
	player1.target.setOrigin(sf::Vector2f(19, 4));
	player1.target.setPosition(400, 400);
	playerArray.push_back(player1);

	//text iterator
	vector<textDisplay>::const_iterator iter5;
	vector<textDisplay> textArray;
	class textDisplay text1;
	//text1.text.setFont(font);
	textArray.push_back(text1);

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
					block.setPosition(row *80,col * 80);
					block.setSize(sf::Vector2f(75, 75));

					block.setFillColor(sf::Color::Blue);

					//collision detection

					if (block.getGlobalBounds().intersects( player1.hullHit2.getGlobalBounds()))
					{
						std::cout << "impact" << std::endl;
						player1.tankHull.move(speed* -cos(player1.tankHull.getRotation()* RM), speed * -sin(player1.tankHull.getRotation() * RM));
					}
					if (block.getGlobalBounds().intersects(player1.hullHit.getGlobalBounds()))
					{
						std::cout << "impact" << std::endl;
						player1.tankHull.move(speed* cos(player1.tankHull.getRotation()* RM), speed * sin(player1.tankHull.getRotation() * RM));
					}

				}

			}

		}
		window.clear();

		//making projectile shoot once 
		sf::Time elapsedTime = entity1.clock.getElapsedTime();

		if (elapsedTime.asSeconds() >= 0.65)
		{
			player1.target.setFillColor(sf::Color::Green);
			player1.target2.setOutlineColor(sf::Color::Green);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				projectile1.shape.setPosition(player1.tankHull.getPosition());
				projectileArray.push_back(projectile1);
				player1.target.setFillColor(sf::Color::Red);
				player1.target2.setOutlineColor(sf::Color::Red);



				entity1.clock.restart();
			}
		}

		//setting up fire direction based on mouse position
		sf::Vector2f currentPosition = player1.tankTurret.getPosition();
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
		projectile1.shape.setRotation(atan2(mousePosition.y - currentPosition.y, mousePosition.x - currentPosition.x) * R);


		//updating turret rotation
		player1.tankTurret.setRotation(atan2(mousePosition.y - currentPosition.y, mousePosition.x - currentPosition.x) * R);

		//crosshair
		player1.target.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
		player1.target2.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));

		//tank hitboxes lock
		player1.hullHit.setPosition(static_cast<sf::Vector2f>(player1.tankHull.getPosition()));
		player1.hullHit2.setPosition(static_cast<sf::Vector2f>(player1.tankHull.getPosition()));

		//text lock
		text1.text.setPosition(static_cast<sf::Vector2f>(enemy1.tankTurret.getPosition()));

		// get angle at where enemy located
		sf::Vector2f playerCurrentPosition = player1.tankHull.getPosition();
		sf::Vector2f enemyCurrentPosition = enemy1.enemyTurret.getPosition();

		// enemy shoot at player
		counter1 = 0;
		sf::Time elapsedTime2 = entity1.clock2.getElapsedTime(); // limiting enemy fire rate
		for (iter2 = enemyArray.begin(); iter2 != enemyArray.end(); iter2++)
		{
			enemyArray[counter1].updateEnemy();

			if (player1.tankHull.getGlobalBounds().intersects(enemyArray[counter1].trigger.getLocalBounds())) // if player enters the view range (circle) 
			{
				enemyArray[counter1].enemyTurret.setRotation(atan2(playerCurrentPosition.y - enemyCurrentPosition.y, playerCurrentPosition.x - enemyCurrentPosition.x) * R);

				if (elapsedTime2.asSeconds() >= 1) // counting timer
				{
					projectile2.shape2.setRotation(atan2(playerCurrentPosition.y - enemyCurrentPosition.y, playerCurrentPosition.x - enemyCurrentPosition.x) * R); // projectile face player

					projectile2.shape2.setPosition(enemy1.enemyTurret.getPosition()); // shoot from enemy turret
					enemyProjectileArray.push_back(projectile2);

					entity1.clock2.restart();
				}
			}


			window.draw(enemyArray[counter1].turretBase);
			window.draw(enemyArray[counter1].enemyTurret);
			window.draw(enemyArray[counter1].trigger);

			counter1++;
		}

		//if projectile collides
		counter1 = 0;
		for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
		{
			counter2 = 0;
			for (iter2 = enemyArray.begin(); iter2 != enemyArray.end(); iter2++)
			{
				if (projectileArray[counter1].shape.getGlobalBounds().intersects(enemyArray[counter2].enemyTurret.getGlobalBounds()))
				{
					enemyArray[counter2].hp--;
					projectileArray[counter1].destroyProjectile = true;

					if (enemyArray[counter2].hp <= 0)
					{
						enemyArray[counter2].alive = false;
					}
				}
				counter2++;
				/*if (projectileArray[counter1].shape.getGlobalBounds().intersects(block.getGlobalBounds()))
				{
				}*/
			}
			counter1++;
		}
		//delete enemy
		counter1 = 0;
		for (iter2 = enemyArray.begin(); iter2 != enemyArray.end(); iter2++)
		{
			if (enemyArray[counter1].alive == false)
			{
				enemyArray.erase(iter2);
				break;
			}
			counter1++;
		}
		//delete projectile
		counter1 = 0;
		for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
		{
			if (projectileArray[counter1].destroyProjectile == true)
			{
				projectileArray.erase(iter);
				break;
			}
		}

		//update player
		player1.update();
		player1.updateMovement();

		//draw sprites
		window.draw(player1.tankHull);

		// draw player projectiles
		counter1 = 0;
		for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
		{
			projectileArray[counter1].updateProjectile();
			window.draw(projectileArray[counter1].shape);
			counter1++;
		}
		// draw enemy projectiles
		counter1 = 0;
		for (iter3 = enemyProjectileArray.begin(); iter3 != enemyProjectileArray.end(); iter3++)
		{
			enemyProjectileArray[counter1].updateEnemyProjectile();
			window.draw(enemyProjectileArray[counter1].shape2);
			counter1++;
		}
		//draw text
		counter1 = 0;
		for (iter5 = textArray.begin(); iter5 != textArray.end(); iter5++)
		{
			window.draw(textArray[counter1].text);
				counter1++;
		}

		window.draw(player1.tankTurret);
		window.draw(player1.target);
		window.draw(player1.target2);

		//window.draw(player1.hullHit);
		//window.draw(player1.hullHit2);

		//window.draw(enemy1.trigger);
		//window.draw(enemy1.enemyTurret);

		//enemy1.updateEnemy();

		window.setView(mainView); // mouse view
		mainView.setCenter(player1.tankHull.getPosition());

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