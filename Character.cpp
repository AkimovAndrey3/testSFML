#include "Character.h"

Character::Character(sf::String F, int x, int y, int w, int h, Map* map):map(map) 
{
	this->x = x;
	this->y = y;
	//W = w;
	//H = h;
	image.loadFromFile(F);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(w, h, w, h));
	state = stay;
}

void Character::Life()
{
	CharacterAnimation();
	
	switch (state)						
	{
	case right:
		dx = speed;
		break;
	case left:
		dx = -speed;
		break;
	case up:

		break;
	case down:

		break;
	case jump:

		break;
	}

	x += dx * time;																		//скорость изменени€ X
	CollusionWithMap(map->getArr(), dx, 0);
	y += dy * time;																		//скорость изменени€ Y
	CollusionWithMap(map->getArr(), 0, dy);
	
	if (!onGround) {																	//реализаци€ гравитации
		dy = dy + 0.0015f*time;		
	}

	if (y > GROUND) {																	//нижн€€ граница(временна€, тк будут добавл€тьс€ платформы)
		y = GROUND;
		onGround = true;
	}

	speed = 0;
	sprite.setPosition(x, y);			
	std::cout << x << '\t' << y << std::endl;										//отображение координат(потом уберетс€)
}


void Character::timeGame()
{
	time = clock.getElapsedTime().asMicroseconds();										//вычисление времени в мс.
	clock.restart();
	time = time / 800;
}

void Character::CharacterAnimation()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		state = left;
		speed = SPEED;
		frame += FRAME_TIME * time;
		if (frame > 3)																	//счетчик фреймов
			frame -= 3.f;
		sprite.setTextureRect(sf::IntRect(96 * int(frame), 96, 96, 96));				//отображение спрайта
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		state = right;
		speed = SPEED;
		frame += FRAME_TIME * time;
		if (frame > 3)
			frame -= 3.f;
		sprite.setTextureRect(sf::IntRect(96 * int(frame), 192, 96, 96));
	}

	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		state = down;
		speed = SPEED;
		frame += FRAME_TIME * time;
		if (frame > 3)
			frame -= 3.f;
		sprite.setTextureRect(sf::IntRect(96 * int(frame), 0, 96, 96));
	}*/

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && (onGround)) {
		state = jump;
		dy = -0.6f;
		onGround = false;
		/*frame += FRAME_TIME * time;
		if (frame > 3)
			frame -= 3.f;
		sprite.setTextureRect(sf::IntRect(96 * int(frame), 288, 96, 96));*/
	}
}

void Character::CollusionWithMap(sf::String GameMap[HEIGHT], float Dx, float Dy)
{
	for (int i = y / 32; i < (y + H) / 32; ++i) {
		for (int j = x / 32; j < (x + W) / 32; ++j) {
			if (GameMap[i][j] == '0') {
				if (Dy > 0) {
					y = i * 32 - H;
					dy = 0;
					onGround = true;
				}
				if (Dy < 0) {
					y = i * 32 + 32;
					dy = 0;
				}
				if (Dx > 0) {
					x = j * 32 - W;
					dx = 0;
				}
				if (Dx < 0) {
					x = j * 32 + 32;
					dx = 0;
				}
			}
		}
	}
}
