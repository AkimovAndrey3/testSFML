#pragma once

#include <SFML/Graphics.hpp>
#include "Map.h"
#include <iostream>

const float FRAME_TIME = 0.008f;
const float SPEED = 0.1f;
const float GROUND = 250.f;

class Character
{
private:
	float x = 0.f;												//координата x
	float y = 0.f;												//координата y
	int W = 0;
	int H = 0;
	float dx = 0.f;												//скорость по y
	float dy = 0.f;												//скорость по x
	float frame = 0.f;											//кол-во кадров спрайта
	float speed = 0.f;											//общая скорость
	float time = 0.f;											//время SFML
	enum state { left, right, up, down, jump, stay } state;		//состояния персонажа
	bool onGround = false;										// земля/воздух
	sf::Clock clock;
	sf::String File;
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;
	Map* map;

public:

	Character(sf::String F, int x, int y, int w, int h, Map* map);		//конструктор

	sf::Sprite& getSprite() {
		return sprite;
	}

	float getFrame() {
		return frame;
	}

	float getTime() {
		return time;
	}

	void Life();												//оживление персонажа(потом переименую)
	void timeGame();											//привязка к времени SFML, а не к процессору
	void CharacterAnimation();									//передвижение и анимации персонажа
	void CollusionWithMap(sf::String GameMap[HEIGHT],float Dx,float Dy);
};


