#ifndef MENUE_H
#define MENUE_H
#pragma once

#include "Game.hpp"
class Menu : public Game
{
public:
	Menu();
	void Draw(sf::RenderWindow& mWindow);
	void MoveUpp();
	void MoveDown();
	int getIndex();
	void higscore();

private:
	sf::Text text[4];
	std::string results;
	sf::Font font;
	int selectetIndex;

};
#endif