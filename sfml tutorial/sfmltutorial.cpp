

/*
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
int main() {


	sf::RenderWindow window(sf::VideoMode({ 500, 500 }), "Hello there", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);        // constructor for our window

	sf::RectangleShape topleft({ 200.f, 100.f });
	sf::RectangleShape topright({ 200.f, 100.f });
	sf::RectangleShape bottomleft({ 200.f, 100.f });
	sf::RectangleShape bottomright({ 200.f, 100.f });



	topright.setOrigin({ 200.f,0.f });    //relative to itself
	topleft.setOrigin({ 0.f,0.f });
	bottomright.setOrigin({ 200.f,100.f });
	bottomleft.setOrigin({ 0.f, 100.f });


	sf::CircleShape circle({ 10.f });  //its radius
	circle.setFillColor(sf::Color(0, 255, 0));
	circle.setOrigin({ 10.0f ,10.0f });

	sf::RectangleShape bar;





	while (window.isOpen()) {




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




		topright.setPosition({ static_cast<float>(window.getSize().x) ,0.f });
		topleft.setPosition({ 0.f ,0.f });
		bottomright.setPosition({ static_cast<float>(window.getSize().x) ,static_cast<float>(window.getSize().y) });
		bottomleft.setPosition({ 0.f, static_cast<float>(window.getSize().y) });
		circle.setPosition({ 250.f , 250.f });

		window.clear(sf::Color(127, 0, 0));


		window.draw(bottomleft);
		window.draw(bottomright);
		window.draw(topright);
		window.draw(topleft);

		window.draw(circle);


		window.display();


	}


}
	
	// sf::View view({ 100.0f ,100.0f }, sf::Vector2f(window.getSize())); center it at 100

		





/*
sf::View view({256.0f ,256.0f}, sf::Vector2f(window.getSize()));    cameraye is centered at coordinates 256 256  this is centered view  , for dynamic player , the camera follows around wherever the player is going
sf::View view(sf::FloatRect({ 0.f, 0.f }, sf::Vector2f(window.getSize())));   camera's position is placed right in the corner
																			 that is the top left of my camera is at top left of the window  , for menu and stuff
																			when you resize the window u r basically minimizing the field of the camera but u r still positioning it at top left 
																			its like the camera is a box at top left no matter how u change the window 









*/