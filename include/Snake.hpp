#ifndef SNAKE_H
#define SNAKE_H
#pragma once
#include "Collision.hpp"

class Snake
{
public:
    Snake(sf::RenderWindow& window, int sSize, int sSpeed, string color);
    void Move();
    void Update(sf::Event& event);
    void Draw();
    void AddCase();
    void changeColor(string newColor);
    std::vector<sf::RectangleShape> getSnakepos();

private:
    sf::RenderWindow& mWindow;
    int mSize;
    int mSpeed;
    std::vector<sf::RectangleShape> mSnakes;
    Direction snake_direction;
    Direction new_direction;
    sf::Clock mClock;
    int mTimeToUpdate;
    float mCurrentTime;
    string color;
};

#endif