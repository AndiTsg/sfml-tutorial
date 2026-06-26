
//this didnt take long haha mainly bc it only needed to be modified
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

		float size = window_w / n;
		float resize = 0.6 * window_w / n;  

		float scale = window_h / max;
		float rescale = 0.9 * window_h / max;




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
			bar.setOrigin({ resize/2, data[i] * rescale });
			bar.setPosition({ (size * i)+(size/2),window_h });
			bar.setSize({ resize ,data[i] * rescale });
			bar.setFillColor(sf::Color(0, 0, 255));
			window.draw(bar);
		}



		window.display();






		}






	}



	*/