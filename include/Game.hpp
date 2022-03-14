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
	void initWindow();
	void menueLoop(sf::RenderWindow& Window);
	void GameLoop(sf::RenderWindow& Window);
	void settings(sf::RenderWindow& Window);
	void ChengecolorS(std::string newColor);
	void settingsSColor(sf::RenderWindow& window);

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