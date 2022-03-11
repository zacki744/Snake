#include "../include/state.hpp"
#include "../include/Collision.hpp"


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
	{
		sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_WIDTH), "Snake game");
		sf::String playerInput;
		sf::Text playerText;
		window.setFramerateLimit(120);
		window.setKeyRepeatEnabled(false);

		Menu menue;
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
						window.close();
						this->GameLoop();
						break;
					case 1:
						window.close();
						settings();
						break;
					case 2:
						menue.higscore();
						break;

					case 3:
						window.close();
						break;
					}
				}
				if (event.type == sf::Event::TextEntered)
				{
					playerInput += event.text.unicode;
					playerText.setString(playerInput);
				}


				window.draw(playerText);
			}
			window.clear(sf::Color(0, 0, 0));
			menue.Draw(window);
			window.display();
		}
		window.close();

	}
}


// this is the main game loop. in this loop the game is generated with the help of the diferernt classes
void Game::GameLoop()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_WIDTH), "Snake game");
	window.setFramerateLimit(120);
	window.setKeyRepeatEnabled(false);

	Snake snake(window, 32, 32, this->snakeColor);
	snake.changeColor(this->snakeColor);
	Food food(window, 32);
	collision check(window, 32);

	while (window.isOpen())
	{
		STATE state = check.colisioncheck(snake.getSnakepos(), food.getfoodPos());
		if (!gamePause)
		{
			snake.Move();
		}

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
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
			window.close();
			menueLoop();

		}
		if (state == STATE::EAT)
		{
			STATE temp = STATE::ALIVE;
			
			snake.AddCase();
			food.GenerateFood(snake.getSnakepos());
			check.changeState(temp);
		}

		window.clear(sf::Color(0, 0, 0));
		snake.Draw();
		food.draw();
		check.draw();
		window.display();
	}
	window.close();

}

// the options menue
void Game::settings()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_WIDTH), "Snake game");

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
					window.close();
					this->menueLoop();
					break;
				case 1:// change snake color
					window.close();
					settingsSColor();
					break;
				case 2://quit
					window.close();
					break;
				}
			}
		}
		window.clear(sf::Color(0, 0, 0));
		menue.Draw(window);
		window.display();
	}
	window.close();

}




void Game::ChengecolorS(std::string newColor)
{
	this->snakeColor = newColor;
}

void Game::settingsSColor()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_WIDTH), "Snake game");

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
					window.close();
					settings();
					break;
				case 1:
					this->ChengecolorS("Red");
					window.close();
					settings();
					break;
				case 2:
					this->ChengecolorS("Green");
					window.close();
					settings();
					break;
				}
			}
		}
		window.clear(sf::Color(0, 0, 0));
		menue.Draw2(window);
		window.display();

	}
}

Menu::Menu()
{
	this->selectetIndex = 0;


	if (!this->font.loadFromFile("../../../arial.ttf"))
	{
		//handle Error
	}
	float temp = 1.8;

	// select the font
	this->text[0].setFont(font);
	text[0].setFillColor(sf::Color::Red);
	text[0].setString("Play");
	text[0].setPosition(sf::Vector2f(SCREEN_WIDTH / 3, SCREEN_HEIGHT / 8));

	this->text[1].setFont(font);
	text[1].setFillColor(sf::Color::White);
	text[1].setString("Options");
	text[1].setPosition(sf::Vector2f(SCREEN_WIDTH / 3, SCREEN_HEIGHT / 4 ));

	this->text[2].setFont(font);
	text[2].setFillColor(sf::Color::White);
	text[2].setString("Higscore");
	text[2].setPosition(sf::Vector2f(SCREEN_WIDTH / 3, SCREEN_HEIGHT / 2.5));

	this->text[3].setFont(font);
	text[3].setFillColor(sf::Color::White);
	text[3].setString("Quit");
	text[3].setPosition(sf::Vector2f(SCREEN_WIDTH / 3, SCREEN_HEIGHT / temp));
}



void Menu::Draw(sf::RenderWindow& mWindow)
{
	for (int i = 0; i < 4; i++)
	{
		mWindow.draw(this->text[i]);
	}
}

void Menu::MoveUpp()
{
	if (selectetIndex - 1 >= 0)
	{
		text[selectetIndex].setFillColor(sf::Color::White);
		selectetIndex--;
		text[selectetIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectetIndex + 1 < 4)
	{
		text[selectetIndex].setFillColor(sf::Color::White);
		selectetIndex++;
		text[selectetIndex].setFillColor(sf::Color::Red);
	}
}

int Menu::getIndex()
{
	return this->selectetIndex;
}

void Menu::higscore()
{
	ifstream file;
	string line;
	vector<int> text;
	file.open("../../../score.txt", ios::out);
	if (file.is_open())
	{
		while (getline(file, line))
		{
			
			text.push_back(stoi(line));
		}
		file.close();
	}
	sort(text.begin(), text.end(), greater<int>());
	if (text.size() < 10)
	{
		for (auto x : text)
			cout << x << endl;
	}
	else
	{
		cout << " the top 10 " << endl;
		for (int i = 0; i < 10; i++)
		{
			cout << i + 1 << " : " << text[i] << endl;
			
		}
	}
}

Setings::Setings()
{
	this->selectetIndex = 0;
	this->CselectetIndex = 0;

	if (!this->font.loadFromFile("../../../arial.ttf"))
	{
		//handle Error
	}
	float temp = 1.8;

	// select the font
	this->text[0].setFont(font);
	text[0].setFillColor(sf::Color::Red);
	text[0].setString("Return");
	text[0].setPosition(sf::Vector2f(SCREEN_WIDTH / 3, SCREEN_HEIGHT / 8));

	this->text[1].setFont(font);
	text[1].setFillColor(sf::Color::White);
	text[1].setString("Change snake Color");
	text[1].setPosition(sf::Vector2f(SCREEN_WIDTH / 3, SCREEN_HEIGHT / 4));

	this->text[2].setFont(font);
	text[2].setFillColor(sf::Color::White);
	text[2].setString("Quit");
	text[2].setPosition(sf::Vector2f(SCREEN_WIDTH / 3, SCREEN_HEIGHT / 3));


	// color menue
	this->color[0].setFont(font);
	color[0].setFillColor(sf::Color::White);
	color[0].setString("Yellow");
	color[0].setPosition(sf::Vector2f(SCREEN_WIDTH / 3, SCREEN_HEIGHT / 8));

	this->color[1].setFont(font);
	color[1].setFillColor(sf::Color::White);
	color[1].setString("Red");
	color[1].setPosition(sf::Vector2f(SCREEN_WIDTH / 3, SCREEN_HEIGHT / 4));

	this->color[2].setFont(font);
	color[2].setFillColor(sf::Color::White);
	color[2].setString("Green");
	color[2].setPosition(sf::Vector2f(SCREEN_WIDTH / 3, SCREEN_HEIGHT / 3));

}

void Setings::Draw(sf::RenderWindow& mWindow)
{
	for (int i = 0; i < 3; i++)
	{
		mWindow.draw(this->text[i]);
	}
}

void Setings::Draw2(sf::RenderWindow& mWindow)
{
	for (int i = 0; i < 3; i++)
	{
		mWindow.draw(this->color[i]);
	}
}

void Setings::MoveUpp()
{
	if (selectetIndex - 1 >= 0)
	{
		text[selectetIndex].setFillColor(sf::Color::White);
		selectetIndex--;
		text[selectetIndex].setFillColor(sf::Color::Red);
	}
}

void Setings::MoveDown()
{
	if (selectetIndex + 1 < 3)
	{
		text[selectetIndex].setFillColor(sf::Color::White);
		selectetIndex++;
		text[selectetIndex].setFillColor(sf::Color::Red);
	}
}

int Setings::getIndex()
{
	return this->selectetIndex;
}

void Setings::CMoveUpp()
{
	if (CselectetIndex - 1 >= 0)
	{
		color[CselectetIndex].setFillColor(sf::Color::White);
		CselectetIndex--;
		color[CselectetIndex].setFillColor(sf::Color::Red);
	}
}

void Setings::CMoveDown()
{
	if (CselectetIndex + 1 < 3)
	{
		color[CselectetIndex].setFillColor(sf::Color::White);
		CselectetIndex++;
		color[CselectetIndex].setFillColor(sf::Color::Red);
	}
}

int Setings::CgetIndex()
{
	return this->CselectetIndex;
}
