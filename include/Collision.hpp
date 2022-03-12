#ifndef COLLISION_H
#define COLLISION_H

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
using namespace std;
enum class Direction { UP, RIGHT, DOWN, LEFT };
enum class STATE { ALIVE, DEAD, EAT };



class collision
{
public:
    collision(sf::RenderWindow& mWindow, int mSize);
    void draw();
    STATE colisioncheck(std::vector<sf::RectangleShape>& mSnakes, sf::CircleShape mFood);
    int getScore();
    void changeState(STATE newState);
private:
    int score;
    const int SCUPP = 50;// amount to uppdate the score
    STATE state;
    sf::RenderWindow& mWindow;
    int mSize;
    std::string results;
    sf::Font font;
    sf::Text text;
};

#endif