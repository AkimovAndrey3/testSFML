#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Character.h"


using namespace sf;



int main() {
	RenderWindow window(VideoMode(1000, 500), "testSFML");

	Map map("images/map.png", &window);
	Character player("images/hero.png", 400, 400, 96, 96, &map);										//главный персонаж
	

	while (window.isOpen()) {	
		player.timeGame();

		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}
		//player.CharacterAnimation();
		player.Life();

		window.clear();

		map.PrintMap();

		window.draw(player.getSprite());
		window.display();
	}
}
