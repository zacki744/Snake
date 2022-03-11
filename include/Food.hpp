#include "Collision.hpp"
#include "state.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>

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
