
/*


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <algorithm>
#include<cmath>


int main() {


	int data[5] = { 56, 270, 150, 342, 260 };
	int n = sizeof(data) / sizeof(data[0]);
	int max = *std::max_element(data, data + n);
	sf::RenderWindow window(sf::VideoMode({ 500, 500 }), "Hello there", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);        // constructor for our window


	sf::CircleShape dot;
	sf::RectangleShape line;


	float xc[5];
	float yc[5];





	while (window.isOpen()) {




		float window_w = static_cast<float>(window.getSize().x);
		float window_h = static_cast<float>(window.getSize().y);

		float size = window_w / n;
		float resize = 0.6 * window_w / n;

		float scale = window_h / max;
		float rescale = 0.9 * window_h / max;


		float window_min = std::min(window_h, window_w);
		float radius = 0.02f * window_min;



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


		window.clear(sf::Color(0, 0, 255));



		for (int i = 0; i < n;i++) {
			float x = (size * i) + (size / 2);
			float y = window_h - data[i] * rescale;
			xc[i] = x;
			yc[i] = y;
			dot.setRadius(radius);
			dot.setOrigin({ radius,radius });
			dot.setPosition({ x,y });
			dot.setFillColor(sf::Color(255, 0, 0));
			window.draw(dot);



			if (i > 0 ) {

				float dx = xc[i] - xc[i - 1];
				float dy = yc[i] - yc[i - 1];
				float hyp = {};
				float angle = std::atan2(dy, dx);
				float length = std::sqrt(dy * dy+ dx * dx);
				line.setRotation(sf::radians(angle));
				line.setSize({ length, radius/2 });
				line.setOrigin({ 0.f,5.f });//kelaynu antsar
				line.setPosition({ xc[i-1],yc[i-1] });

				line.setFillColor(sf::Color(255, 0, 0));
				window.draw(dot);
				window.draw(line);

			}
		}


		



		window.display();






	}






}




*/