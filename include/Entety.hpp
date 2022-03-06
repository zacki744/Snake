#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED
#include "state.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
using namespace std;
enum class Direction { UP, RIGHT, DOWN, LEFT };
enum class STATE { ALIVE, DEAD, EAT };

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


class Food
{
public:
    Food(sf::RenderWindow& window, int sSize);//generate a pice of food when initialised
    void GenerateFood(std::vector<sf::RectangleShape> &mSnakes);
    void draw();
    sf::CircleShape getfoodPos();
private:
    sf::CircleShape mFood;
    sf::RenderWindow& mWindow;
    int mSize;

};

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

#endif // SNAKE_H_INCLUDED
