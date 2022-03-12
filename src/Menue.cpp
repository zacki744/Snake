#pragma once

#include "Menue.hpp"

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
	text[1].setPosition(sf::Vector2f(SCREEN_WIDTH / 3, SCREEN_HEIGHT / 4));

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