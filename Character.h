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
	float x = 0.f;												//���������� x
	float y = 0.f;												//���������� y
	int W = 0;
	int H = 0;
	float dx = 0.f;												//�������� �� y
	float dy = 0.f;												//�������� �� x
	float frame = 0.f;											//���-�� ������ �������
	float speed = 0.f;											//����� ��������
	float time = 0.f;											//����� SFML
	enum state { left, right, up, down, jump, stay } state;		//��������� ���������
	bool onGround = false;										// �����/������
	sf::Clock clock;
	sf::String File;
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;
	Map* map;

public:

	Character(sf::String F, int x, int y, int w, int h, Map* map);		//�����������

	sf::Sprite& getSprite() {
		return sprite;
	}

	float getFrame() {
		return frame;
	}

	float getTime() {
		return time;
	}

	void Life();												//��������� ���������(����� ����������)
	void timeGame();											//�������� � ������� SFML, � �� � ����������
	void CharacterAnimation();									//������������ � �������� ���������
	void CollusionWithMap(sf::String GameMap[HEIGHT],float Dx,float Dy);
};


