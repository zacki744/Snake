#ifndef SETTINGS_H
#define SETTINGS_H
#pragma once

#include "Menue.hpp"
class Setings : public Menu
{
public:
	Setings();
	void Draw(sf::RenderWindow& mWindow);
	void Draw2(sf::RenderWindow& mWindow);
	void MoveUpp();
	void MoveDown();
	int getIndex();
	void CMoveUpp();
	void CMoveDown();
	int CgetIndex();


private:
	sf::Text text[3];
	std::string results;
	sf::Font font;
	sf::Text color[3];

	int selectetIndex;
	int CselectetIndex;
};
#endif