#pragma once

#include "Settings.hpp"

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