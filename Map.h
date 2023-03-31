#pragma once

#include <SFML/Graphics.hpp>
//#include <string>

const int HEIGHT = 25;
const int WIDTH = 40;


class Map
{
public:
	Map(sf::String F, sf::RenderWindow* window);
	sf::Sprite& getSprite() {
		return sprite_map;
	}

	void PrintMap();

	sf::String* getArr() {
		return &GameMap[HEIGHT];
	}

private:
	sf::String S;
	sf::Image image_map;
	sf::Texture texture_map;
	sf::Sprite sprite_map;
	sf::RenderWindow* window;
public:
	sf::String GameMap[HEIGHT] = {
	"           0                            ",
	"           0                            ",
	"           0                            ",
	"           0                            ",
	"           0                            ",
	"                                        ",
	"                                        ",
	"        0                               ",
	"        0                               ",
	"        0                               ",
	"        0                               ",
	"                                        ",
	"                                        ",
	"      0                                 ",
	"      0                                 ",
	"      0                                 ",
	"      0                                 ",
	"                                        ",
	"                                        ",
	"                                        ",
	"                                        ",
	"                                        ",
	"        0                               ",
	"                                        ",
	"                                        ",
	};
};

