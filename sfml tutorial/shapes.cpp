#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <algorithm>
int main() {


	sf::RenderWindow window(sf::VideoMode({ 400, 400 }), "Hello there", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);        // constructor for our window


	float half = 200.f;
	float  half2= 100.f;
	float point3 = 400.f;

	sf::ConvexShape shape;
	
	shape.setOutlineColor(sf::Color(38, 37, 166));
	//shape.setOutlineThickness(100.f);
	shape.setPointCount(3);


	//this also worked when i didnt set the position and manually filled the points relative to the window

	//shape.setOrigin({ half,half });
	shape.setPosition({ 200.f, 200.f });// means move the origin of the shape to the points specified


	//the setposition has set the origin 
	shape.setPoint(0, { -half/2.f, 0.f});
	shape.setPoint(1, { half/2,0.f });
	shape.setPoint(2, { 0.f,-half }); 
	//std::cout << shape.getLocalBounds() << std::endl << shape.getPosition().y;




	while (window.isOpen()) {




		/*float window_w = static_cast<float>(window.getSize().x);
		float window_h = static_cast<float>(window.getSize().y);

		float size = window_h / n;
		float resize = 0.6 * window_h / n;

		float scale = window_w / max;
		float rescale = 0.9 * window_w / max;*/




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
		window.draw(shape);



		

		window.display();






	}





}

