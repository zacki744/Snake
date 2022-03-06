#pragma once
#include "../include/Entety.hpp"
#include "Entety.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

using namespace std;


class Game
{
public:
	#define SCREEN_WIDTH 800
	#define SCREEN_HEIGHT 640
	Game();
	void menueLoop();
	void GameLoop();
	void settings();
	void ChengecolorS(std::string newColor);
	void settingsSColor();

private:
	//main game settings

	bool gamePause;

	sf::Text text;
	std::string results;
	sf::Font font;

	//setings for snake game
	std::string snakeColor;
	
};

class Menu : public Game
{
public:
	Menu();

	virtual void Draw(sf::RenderWindow& mWindow);
	virtual void MoveUpp();
	virtual void MoveDown();
	virtual int getIndex();

	void higscore();

private:
	sf::Text text[4];
	std::string results;
	sf::Font font;

	int selectetIndex;

};

class Setings : public Menu
{
public:
	Setings();
	void Draw(sf::RenderWindow& mWindow);
	void Draw2(sf::RenderWindow& mWindow);
	void MoveUpp();
	void MoveDown();
	int getIndex();
	virtual void CMoveUpp();
	virtual void CMoveDown();
	virtual int CgetIndex();


private:
	sf::Text text[3];
	std::string results;
	sf::Font font;
	sf::Text color[3];

	int selectetIndex;
	int CselectetIndex;
};