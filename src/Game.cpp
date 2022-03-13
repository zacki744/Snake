#pragma once
#include "Game.hpp"
#include "Menue.cpp"
#include "Snake.cpp"
#include "Food.cpp"
#include "settings.cpp"
#include "Collision.cpp"

Game::Game()
{
	this->gamePause = false;

	this->font.loadFromFile("../../../arial.ttf");

	// select the font
	this->text.setFont(font); // font is a sf::Font

	// set the string to display
	text.setString("score: ");

	// set the character size
	text.setCharacterSize(24); // in pixels, not points!

	// set the color
	text.setFillColor(sf::Color::White);
	this->snakeColor = "Yellow";
}

// this is the menue loop. this is the first thing the player sees.
void Game::menueLoop()
{
	sf::RenderWindow Window(sf::VideoMode(SCREEN_WIDTH, SCREEN_WIDTH), "Snake game");
	sf::String playerInput;
	sf::Text playerText;
	Window.setFramerateLimit(120);
	Window.setKeyRepeatEnabled(false);

	Menu menue;
	menue.Draw(Window);

	while (Window.isOpen())
	{
		sf::Event event;
		while (Window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				Window.close();
			}

			if ((event.type == sf::Event::KeyReleased) && (event.key.code == sf::Keyboard::Up))
			{
				menue.MoveUpp();

			}
			if ((event.type == sf::Event::KeyReleased) && (event.key.code == sf::Keyboard::Down))
			{
				menue.MoveDown();
			}
			if ((event.type == sf::Event::KeyReleased) && (event.key.code == sf::Keyboard::Return))
			{
				int index = menue.getIndex();
				switch (index)
				{
				case 0:
					this->GameLoop(Window);
					break;
				case 1:
					//window.close();
					settings(Window);
					break;
				case 2:
					menue.higscore();
					break;

				case 3:
					Window.close();
					break;
				}
			}
			if (event.type == sf::Event::TextEntered)
			{
				playerInput += event.text.unicode;
				playerText.setString(playerInput);
			}


			Window.draw(playerText);
		}
		Window.clear(sf::Color(0, 0, 0));
		menue.Draw(Window);
		Window.display();
	}
}



// this is the main game loop. in this loop the game is generated with the help of the diferernt classes
void Game::GameLoop(sf::RenderWindow& Window)
{
	Window.setFramerateLimit(120);
	Window.setKeyRepeatEnabled(false);

	Snake snake(Window, 32, 32, this->snakeColor);
	snake.changeColor(this->snakeColor);
	Food food(Window, 32);
	collision check(Window, 32);

	while (Window.isOpen())
	{
		STATE state = check.colisioncheck(snake.getSnakepos(), food.getfoodPos());
		if (!gamePause)
		{
			snake.Move();
		}

		sf::Event event;
		while (Window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				Window.close();
			}

			if ((event.type == sf::Event::KeyReleased) && (event.key.code == sf::Keyboard::P))
			{
				if (gamePause) {
					gamePause = false;
				}
				else
				{
					gamePause = true;
				}
			}

			if (!gamePause)
			{
				snake.Update(event);
			}

			if ((event.type == sf::Event::KeyReleased) && (event.key.code == sf::Keyboard::Q))
			{
				state = STATE::DEAD;
			}
		}


		if (state == STATE::DEAD)
		{
			fstream myfile;
			myfile.open("c:/snake/score.txt", ios::app);
			if (!myfile)
			{
				std::cout << "canot open" << endl;
			}
			int score = check.getScore();
			myfile << score << std::endl;
			std::cout << "Your score was: " << score << endl;
			myfile.close();
			menueLoop();

		}
		if (state == STATE::EAT)
		{
			STATE temp = STATE::ALIVE;

			snake.AddCase();
			food.GenerateFood(snake.getSnakepos());
			check.changeState(temp);
		}

		Window.clear(sf::Color(0, 0, 0));
		snake.Draw();
		food.draw();
		check.draw();
		Window.display();
	}
}

// the options menue
void Game::settings(sf::RenderWindow& Window)
{
	//sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_WIDTH), "Snake game");
	Window.setFramerateLimit(120);
	Window.setKeyRepeatEnabled(false);

	Setings menue;
	menue.Draw(Window);
	bool inSettings = true;

	while (inSettings)
	{
		sf::Event event;
		while (Window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				Window.close();
			}

			if ((event.type == sf::Event::KeyReleased) && (event.key.code == sf::Keyboard::Up))
			{
				menue.MoveUpp();

			}
			if ((event.type == sf::Event::KeyReleased) && (event.key.code == sf::Keyboard::Down))
			{
				menue.MoveDown();
			}
			if ((event.type == sf::Event::KeyReleased) && (event.key.code == sf::Keyboard::Return))
			{
				int index = menue.getIndex();
				switch (index)
				{
				case 0: // return
					inSettings = false;
					this->menueLoop();
					break;
				case 1:// change snake color
					inSettings = false;
					settingsSColor(Window);
					break;
				case 2://quit
					inSettings = false;
					Window.close();
					break;
				}
			}
		}
		Window.clear(sf::Color(0, 0, 0));
		menue.Draw(Window);
		Window.display();
	}
}




void Game::ChengecolorS(std::string newColor)
{
	this->snakeColor = newColor;
}

void Game::settingsSColor(sf::RenderWindow& window)
{
	bool change_colorSnake = false;


	window.setFramerateLimit(120);
	window.setKeyRepeatEnabled(false);

	Setings menue;
	menue.Draw(window);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			if ((event.type == sf::Event::KeyReleased) && (event.key.code == sf::Keyboard::Up))
			{
				menue.CMoveUpp();

			}
			if ((event.type == sf::Event::KeyReleased) && (event.key.code == sf::Keyboard::Down))
			{
				menue.CMoveDown();
			}
			if ((event.type == sf::Event::KeyReleased) && (event.key.code == sf::Keyboard::Return))
			{
				int index = menue.CgetIndex();
				switch (index)
				{
				case 0:
					this->ChengecolorS("Yellow");
					settings(window);
					break;
				case 1:
					this->ChengecolorS("Red");
					settings(window);
					break;
				case 2:
					this->ChengecolorS("Green");
					settings(window);
					break;
				}
			}
		}
		window.clear(sf::Color(0, 0, 0));
		menue.Draw2(window);
		window.display();

	}
}