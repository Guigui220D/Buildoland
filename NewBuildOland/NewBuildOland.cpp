// NewBuildOland.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works !");
	
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear();
		window.display();
	}

	std::cout << "Hello world!" << std::endl;

    return 0;
}

