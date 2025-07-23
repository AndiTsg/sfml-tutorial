/*


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

int main() {



	sf::ContextSettings settings;
	settings.antiAliasingLevel = 4;

	sf::RenderWindow window(sf::VideoMode({ 500 ,500 }), "circle"  ,  sf::State::Windowed, settings);

	sf::CircleShape circle(20.f, 7);

	circle.setFillColor(sf::Color(255, 0, 0));
	circle.setOrigin({ 20.f, 20.f });
	circle.setPosition({ 250.f, 250.f });
	//circle.setScale({ 1.5f,1.5f });
	while (window.isOpen())
	{



		while (std::optional event = window.pollEvent())
		{

			if (event->is<sf::Event::Closed>())
			{
				window.close();

			}

			else if (event->is<sf::Event::Resized>())
			{

				sf::View view(sf::FloatRect({ 0.f, 0.f }, sf::Vector2f(window.getSize())));
				window.setView(view);

			}
			circle.setPosition({ static_cast<float>(window.getSize().x/2),static_cast<float>(window.getSize().y/2)});

			window.clear(sf::Color(255, 255, 0));
			window.draw(circle);
			window.display();
		}

		}
	}
	

	*/