#include "Map.h"

Map::Map(sf::String F, sf::RenderWindow* window):window(window)
{
	image_map.loadFromFile(F);
	texture_map.loadFromImage(image_map);
	sprite_map.setTexture(texture_map);
}

void Map::PrintMap()
{
	for (int i = 0; i < HEIGHT; ++i) {
		for (int j = 0; j < WIDTH; ++j) {
			if (GameMap[i][j] == ' ') {
				sprite_map.setTextureRect(sf::IntRect(0, 0, 32, 32));
			}
			if (GameMap[i][j] == '0') {
				sprite_map.setTextureRect(sf::IntRect(64, 0, 32, 32));
			}
			//sprite_map.setScale(1.25, 1.25);
			sprite_map.setPosition(i * 32, j * 32);
			window->draw(sprite_map);
		}
	}
}
