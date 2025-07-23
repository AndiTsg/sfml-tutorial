
//Finally aaahhhh

/*

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <algorithm>
int main() {


	int data[5] = { 30, 15, 90, 42, 60 };
	int n = sizeof(data) / sizeof(data[0]);
	int max = *std::max_element(data, data + n);
	sf::RenderWindow window(sf::VideoMode({ 500, 500 }), "Hello there", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);        // constructor for our window


	sf::RectangleShape bar;


	
	
	while (window.isOpen()) {




		float window_w = static_cast<float>(window.getSize().x);
		float window_h = static_cast<float>(window.getSize().y);

		float size = window_h / n;
		float resize = 0.6 * window_h / n;
		
		float scale = window_w / max;
		float rescale = 0.9 * window_w / max;




		while (std::optional event = window.pollEvent())
		{

			if (event->is<sf::Event::Closed>())
			{
				window.close();
			}

			else if (event->is<sf::Event::Resized>())
			{
				// update view
				sf::View view1(sf::FloatRect({ 0.f, 0.f }, sf::Vector2f(window.getSize())));
				window.setView(view1);
			}


		}


		window.clear(sf::Color(0, 0, 0));

		 

		for (int i = 0; i < n;i++) {
			bar.setOrigin({ 0.f ,resize/2});   // writing size instead of resize cost me more than an hour
			bar.setPosition({ 0.f, (size * i)+(size/2)});
			bar.setSize({ data[i] * rescale ,resize });
			bar.setFillColor(sf::Color(0, 0, 255));
			window.draw(bar);
		}



		window.draw(bottomleft);
		window.draw(bottomright);
		window.draw(topright);
		window.draw(topleft);
		window.draw(circle);


		window.display();


		



		}



		topright.setPosition({ static_cast<float>(window.getSize().x) ,0.f });
		topleft.setPosition({ 0.f ,0.f });
		bottomright.setPosition({ static_cast<float>(window.getSize().x) ,static_cast<float>(window.getSize().y) });
		bottomleft.setPosition({ 0.f, static_cast<float>(window.getSize().y)});

		circle.setPosition({250.f , 250.f});
	
	
	

	}



	*/