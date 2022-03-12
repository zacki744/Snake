#ifndef FOOD_H
#define FOOD_H
#pragma once
#include "Collision.hpp"
class Food
{
public:
    Food(sf::RenderWindow& window, int sSize);//generate a pice of food when initialised
    void GenerateFood(std::vector<sf::RectangleShape>& mSnakes);
    void draw();
    sf::CircleShape getfoodPos();
private:
    sf::CircleShape mFood;
    sf::RenderWindow& mWindow;
    int mSize;

};

#endif