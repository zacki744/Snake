#include "../include/Collision.hpp"


collision::collision(sf::RenderWindow& Window, int mSize): mWindow(Window), mSize(mSize)
{
    this->font.loadFromFile("../../../arial.ttf");
    // select the font
    this->text.setFont(font); // font is a sf::Font
    // set the string to display
    text.setString("Hello world");
    // set the character size
    text.setCharacterSize(24); // in pixels, not points!
    // set the color
    text.setFillColor(sf::Color::White);
    this->state = STATE::ALIVE;
    score = 0;

}

void collision::draw()
{
    results = "Score: " + to_string(score);
    // set the string to display
    this->text.setString(results);
    mWindow.draw(text);
}

STATE collision::colisioncheck(std::vector<sf::RectangleShape>& mSnakes, sf::CircleShape mFood)
{
    for ( int i = 2; i < mSnakes.size(); i++) // Snake's boxes
    {
        if (mSnakes[0].getPosition().x == mSnakes[i].getPosition().x
            && mSnakes[0].getPosition().y == mSnakes[i].getPosition().y)
        {
            this->state = STATE::DEAD;
        }
    }

    if (mSnakes[0].getPosition().x < 0 || mSnakes[0].getPosition().x + mSnakes[0].getSize().x > mWindow.getSize().x // Window collision
        || mSnakes[0].getPosition().y < 0 || mSnakes[0].getPosition().y + mSnakes[0].getSize().y > mWindow.getSize().y)
    {
        this->state = STATE::DEAD;
    }

    if (mSnakes[0].getPosition().x == mFood.getPosition().x // Food collision
        && mSnakes[0].getPosition().y == mFood.getPosition().y)
    {
        score += SCUPP;
        this->state = STATE::EAT;
        draw();
    }
    return this->state;
    
}

int collision::getScore()
{
    return this->score;
}

void collision::changeState(STATE temp)
{
    this->state = temp;
}
