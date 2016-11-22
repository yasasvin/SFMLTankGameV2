#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Map
{
public:
	static const int ROW_COUNT = 64;
	static const int COLUMN_COUNT = 96;

	enum Tile {
		TileOut = -1,
		TileEmpty = 0,
		TileWall = 1,
		TileGate = 2,
		TileDot = 3,
		TileEnergizer = 4,
		TileRed = 6,
		TileCyan = 7,
		TilePink = 8,
		TileOrange = 9,
		TileIntersection = 10
	};

	Tile getTile(int row, int column);
	bool isCollision(int row, int column);
	sf::Sprite getSprite();
	Map();
	~Map();

private:
	sf::Texture texture;
	sf::Sprite sprite;
	static const int Map::DEFAULT_MAP[Map::ROW_COUNT][COLUMN_COUNT];
};

