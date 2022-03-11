#include "../include/Food.hpp"
#include "../include/Snake.hpp"
#include "../include/Collision.hpp"



Food::Food(sf::RenderWindow& window, int sSize) : mWindow(window), mSize(sSize)
{
    mFood.setRadius(mSize / 2); // Food circle
    mFood.setFillColor(sf::Color::Green);
    Snake snake(window, 32, 32, "Yellow");
    GenerateFood(snake.getSnakepos());
}

void Food::GenerateFood(std::vector<sf::RectangleShape>& mSnakes)
{
    int randomX;
    int randomY;
    int c = 0;
    do
    {
        c = 0;
        randomX = rand() % (mWindow.getSize().x / mSize);
        randomY = rand() % (mWindow.getSize().y / mSize);
        for (unsigned int i = 0; i < mSnakes.size(); i++)
        {
            if ((mSnakes[i].getPosition().x == randomX * mSize) && (mSnakes[i].getPosition().y == randomY * mSize))
            {
                c += 1;
            }
        }

    } while (c != 0);
    this->mFood.setPosition(randomX * mSize, randomY * mSize);
}

void Food::draw()
{
    this->mWindow.draw(this->mFood);
}

sf::CircleShape Food::getfoodPos()
{
    return this->mFood;
}
