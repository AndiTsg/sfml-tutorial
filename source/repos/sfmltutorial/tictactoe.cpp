
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>



int main() {


	sf::RenderWindow window(sf::VideoMode({ 1000, 1000 }), "Hello there", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);        // constructor for our window

	sf::RectangleShape line;
	sf::CircleShape circle({ 10.f });

	bool winner = false;
	char turn = 'x';
	char win_type = 0;
	int win_code = 0;
	float angle;
	char array[3][3] = {' ', ' ', ' ',
						' ', ' ', ' ', 
						' ', ' ', ' '};
	line.setOutlineThickness({ 0.f });

	line.setFillColor(sf::Color(250, 0, 0));
	line.setSize({ 300.f, 10.f });
	line.setOrigin(line.getGeometricCenter());
	line.setPosition({500.f, 500.f});
	line.setRotation(sf::degrees(45.f ));

	float window_width = 1000.f;
	float window_height = 1000.f;
	float radius_true = 0.8*(window_width / 3) / 2;
	float diameter_true = 2 * radius_true;
	float radius = (window_width/3)/2;
	float diameter = 2 * radius;

	int cursor_x = 1;
	int cursor_y = 1;



	auto drawcursor = [&](int i, int j) {
		line.setOutlineThickness({ -20.f });
		line.setOutlineColor(sf::Color::White);
		line.setFillColor(sf::Color::Transparent);
		line.setSize({ window_width / 3, window_height / 3 });
		line.setOrigin(line.getGeometricCenter());
		line.setRotation(sf::degrees(0.f));
		line.setPosition({ (window_width / 3) / 2 + diameter * i , (window_height / 3) / 2 + j * diameter });
		window.draw(line);
		};
    


	auto circledraw = [&](int i, int j) {

		circle.setRadius({ radius_true });
		circle.setOutlineThickness({ -10.f });
		circle.setFillColor(sf::Color::Transparent);
		circle.setOrigin(circle.getGeometricCenter());
		circle.setPosition({ (window_width / 3) / 2 + diameter * i , (window_height / 3) / 2 + j * diameter });
		window.draw(circle);
		};




	auto linedraw = [&](int i, int j) {

		line.setOutlineThickness({ 0.f });
		line.setFillColor(sf::Color(0, 0, 250));
		line.setSize({ 400.f, 10.f });
		line.setOrigin(line.getGeometricCenter());
		line.setPosition({ (window_width / 3) / 2 + diameter * i , (window_height / 3) / 2 + j * diameter });
		line.setRotation(sf::degrees(45.f));
		window.draw(line);

		line.setOutlineThickness({ 0.f });
		line.setFillColor(sf::Color(0, 0, 250));
		line.setSize({ 400.f, 10.f });
		line.setOrigin(line.getGeometricCenter());
		line.setPosition({ (window_width / 3) / 2 + diameter * i , (window_height / 3) / 2 + j * diameter });
		line.setRotation(sf::degrees(-45.f));
		window.draw(line);



		};

	auto wincheck = [&]() {



		//for col
		for (int r = 0; r < 3;r++) {
			if (array[0][r] != ' ' and (array[0][r] == array[1][r]) and (array[1][r] == array[2][r])) {
				winner = true;
				win_type ='c';
				win_code = r;
			}


		}


		//for row
		for (int r = 0; r < 3;r++) {
			if (array[r][0]!=' ' and (array[r][0] == array[r][1]) and (array[r][1] == array[r][2])) {
				winner = true;
				win_type = 'r';
				win_code = r;
			}
		}


		//for dia
		 if (array[0][0] != ' ' and (array[0][0] == array[1][1]) and (array[1][1] == array[2][2])){
			winner = true;
			win_type = 'd';
			win_code = 1;
			}

		else if (array[0][2] != ' ' and (array[0][2] == array[1][1]) and (array[1][1] == array[2][0])) {
			winner = true;
			win_type = 'd';
			win_code = 2;

		}


		};

	auto windraw = [&]() {

		line.setOutlineThickness({ 0.f });
		line.setFillColor(sf::Color(0, 0, 250));
		line.setSize({ 1000.f, 10.f });
		line.setOrigin(line.getGeometricCenter());

		if (win_type == 'c') {
			angle = 90.f;
			line.setPosition({ (window_width / 3) / 2 + diameter * win_code , (window_height / 3) / 2 + diameter });//j1
			line.setRotation(sf::degrees(angle));
			window.draw(line);
			winner = true;
		}

		//for row
		else if (win_type == 'r') {
			angle = 0.f;
			line.setPosition({ (window_width/ 2 ), (window_height / 3) / 2 + diameter* win_code });//j1
			line.setRotation(sf::degrees(angle));
			window.draw(line);
			winner = true;
		}

		//for dia
		else if (win_type == 'd' and win_code == 1) {
			float angle = 45.f;
			line.setPosition({ (window_width / 3) / 2 + diameter  , (window_height / 3) / 2 + diameter });
			line.setRotation(sf::degrees(angle));
			window.draw(line);
			winner = true;

		}

		else if (win_type == 'd' and win_code == 2) {
			float angle = -45.f;
			line.setPosition({ (window_width / 3) / 2 + diameter  , (window_height / 3) / 2 + diameter });
			line.setRotation(sf::degrees(angle));
			window.draw(line);
			winner = true;

		}
		};
	

	
	
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
				sf::View view1({ 500.0f ,500.0f }, sf::Vector2f(window.getSize()));
				window.setView(view1);
			}

			else if (auto* key = event->getIf<sf::Event::KeyPressed>()) {

				if ((key->scancode == sf::Keyboard::Scancode::Left) and cursor_x > 0) {
					cursor_x--;
				}
				else if ((key->scancode == sf::Keyboard::Scancode::Right) and cursor_x < 2) {
					cursor_x++;
				}
				else if ((key->scancode == sf::Keyboard::Scancode::Up) and cursor_y > 0) {
					cursor_y--;
				}
				else if ((key->scancode == sf::Keyboard::Scancode::Down) and cursor_y < 2) {
					cursor_y++;
				}
				else if ((key->scancode == sf::Keyboard::Scancode::X) and (array[cursor_x][cursor_y] == ' ')
					and (winner == false) and turn == 'x') {
					array[cursor_x][cursor_y] = 'x';
					turn = 'o';
				}
				else if ((key->scancode == sf::Keyboard::Scancode::O) and (array[cursor_x][cursor_y] == ' ')
					and (winner == false) and turn == 'o') {
					array[cursor_x][cursor_y] = 'o';
					turn = 'x';
				}


			}


		}


window.clear(sf::Color(125, 125,125 ));






auto drawer = [&]() {

				for (int i = 0; i < 3;i++) {
					for (int j = 0; j < 3;j++) {

						if (array[i][j] == 'x') {
							linedraw(i, j);
						}
						else if (array[i][j] == 'o') {
							circledraw(i, j);
						}

						else if (array[i][j] == ' ') {
							
						}
						else {
							std::cout << "error";
						}
					}

				}
				};




			

			
			

			for (int i = 1; i < 3;i++) {
				line.setOutlineThickness({ 0.f });
				line.setFillColor(sf::Color(0, 0, 0));
				line.setSize({ window_width, 10.f });
				line.setOrigin({ window_width / 2 , 0.f});
				line.setRotation(sf::degrees(0.f));
				line.setPosition({ window_width / 2  , (window_height / 3) * i });
				window.draw(line);

			}

			for (int i = 1; i < 3;i++) {
				line.setOutlineThickness({ 0.f });
				line.setFillColor(sf::Color(0, 0, 0));
				line.setSize({ window_width, 10.f });
				line.setOrigin({ window_width / 2 , 0.f });
				line.setRotation(sf::degrees(90.f));
				line.setPosition({  (window_width / 3) * i ,window_height / 2  });
				window.draw(line);

			}
		
			drawcursor(cursor_x, cursor_y);

			drawer();
			wincheck();
			windraw();

		window.display();


	}
	//window is closed

}



	









/*

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>



int main() {


	sf::RenderWindow window(sf::VideoMode({ 1000, 1000 }), "Hello there", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);        // constructor for our window

	sf::RectangleShape line;
	sf::CircleShape circle({ 10.f });





	line.setOutlineThickness({ 0.f });

	line.setFillColor(sf::Color(250, 0, 0));
	line.setSize({ 300.f, 10.f });
	line.setOrigin(line.getGeometricCenter());
	line.setPosition({500.f, 500.f});
	line.setRotation(sf::degrees(45.f ));




	float window_width = 1000.f;
	float window_height = 1000.f;
	float radius = 150.0f;
	float diameter = 2 * radius;







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
				sf::View view1({ 500.0f ,500.0f }, sf::Vector2f(window.getSize()));
				window.setView(view1);
			}



		}


window.clear(sf::Color(127, 0, 0));


			auto circledraw = [&]() {
				for (int i = 0; i < 3;i++) {
					circle.setRadius({ radius });
					circle.setFillColor(sf::Color(250, 0, 0));
					circle.setOrigin(circle.getGeometricCenter());
					circle.setPosition({ (window_width / 3) / 2 + diameter * i , (window_height / 3) / 2 + i * diameter });
					window.draw(circle);
				}
				};




			auto linedraw = [&]() {
				for (int i = 0; i < 3;i++) {
					line.setOutlineThickness({ 0.f });

					line.setFillColor(sf::Color(250, 0, 0));
					line.setSize({ 400.f, 10.f });
					line.setOrigin(line.getGeometricCenter());
					line.setPosition( {(window_width / 3) / 2 + diameter * i , (window_height / 3) / 2 + i * diameter });
					line.setRotation(sf::degrees(45.f));
					window.draw(line);
				}


			};






		circledraw();
		linedraw();




		window.display();


	}
	//window is closed

}











*/