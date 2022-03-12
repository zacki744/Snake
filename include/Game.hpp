#pragma once
#ifndef GAME_H
#define GAME_H
#include "Collision.hpp"
class Game
{
public:
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 640
	Game();
	void menueLoop();
	void GameLoop(sf::RenderWindow& Gwindow);
	void settings(sf::RenderWindow& Swindow);
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

#endif