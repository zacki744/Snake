#include "../include/Entety.hpp"
using namespace std;
using namespace sf;

Snake::Snake(sf::RenderWindow& window, int sSize, int sSpeed, string Color) : mWindow(window), mSize(sSize), mSpeed(sSpeed), color(Color)
{ 
    snake_direction, new_direction = Direction::RIGHT;
    AddCase();
    AddCase();

    srand(std::time(0));
    mTimeToUpdate = 250; // 1/4 second
    mCurrentTime = 0.0f;
    sf::Clock mClock;
    
}

void Snake::AddCase() 
{
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(32, 32));
    rect.setOutlineColor(sf::Color::Black);
    rect.setOutlineThickness(1.0f);

    if (mSnakes.empty())
    {
        rect.setFillColor(sf::Color::Red);
        rect.setPosition(320, 256);
    }
    else
    {
        if (this->color == "Yellow")
        {
            rect.setFillColor(sf::Color::Yellow);
            rect.setPosition(mSnakes[mSnakes.size() - 1].getPosition().x - rect.getSize().x, mSnakes[mSnakes.size() - 1].getPosition().y);
        }
        else if (this->color == "Green")
        {
            rect.setFillColor(sf::Color::Green);
            rect.setPosition(mSnakes[mSnakes.size() - 1].getPosition().x - rect.getSize().x, mSnakes[mSnakes.size() - 1].getPosition().y);
        }
        else if(this->color == "Red")
        {
            rect.setFillColor(sf::Color::Red);
            rect.setPosition(mSnakes[mSnakes.size() - 1].getPosition().x - rect.getSize().x, mSnakes[mSnakes.size() - 1].getPosition().y);
        }
    }

    mSnakes.push_back(rect);
}

void Snake::changeColor(string newColor)
{
    this->color = newColor;
}

void Snake::Move() // Move the snake every 250 ms and check collision
{
    if (mCurrentTime < mTimeToUpdate)
    {
        mCurrentTime += mClock.restart().asMilliseconds();
    }
    else
    {
        mCurrentTime = 0.0f;

        if (mSnakes.size() > 1)
        {
            for (unsigned int i = mSnakes.size() - 1; i > 0; i--)
            {
                mSnakes[i].setPosition(sf::Vector2f(mSnakes[i - 1].getPosition().x, mSnakes[i - 1].getPosition().y));
            }
        }

        switch (new_direction)
        {
        case Direction::UP:
            mSnakes[0].move(0, -mSpeed);
            break;
        case Direction::DOWN:
            mSnakes[0].move(0, mSpeed);
            break;
        case Direction::LEFT:
            mSnakes[0].move(-mSpeed, 0);
            break;
        case Direction::RIGHT:
            mSnakes[0].move(mSpeed, 0);
            break;

        }
        snake_direction = new_direction;
    }
}

void Snake::Update(Event& event) // Check key input
{
    if (event.type == sf::Event::KeyPressed)
    {
        switch (event.key.code)
        {
        case sf::Keyboard::Left:
            if (mSnakes[0].getPosition().x - mSnakes[0].getSize().x != mSnakes[1].getPosition().x)
            {
                if (snake_direction != Direction::RIGHT)
                {
                    new_direction = Direction::LEFT;
                }
            }
            break;
        case sf::Keyboard::Right:
            if (mSnakes[0].getPosition().x + mSnakes[0].getSize().x != mSnakes[1].getPosition().x)
            {
                if (snake_direction != Direction::LEFT)
                {
                    new_direction = Direction::RIGHT;
                }
            }
            break;


        case sf::Keyboard::Up:

            if (mSnakes[0].getPosition().y - mSnakes[0].getSize().x != mSnakes[1].getPosition().y)
            {
                if (snake_direction != Direction::DOWN)
                {
                    new_direction = Direction::UP;
                }
            }
            break;

        case sf::Keyboard::Down:

            if (mSnakes[0].getPosition().y + mSnakes[0].getSize().x != mSnakes[1].getPosition().y)
            {
                if (snake_direction != Direction::UP)
                {
                    new_direction = Direction::DOWN;
                }
            }
            break;

        }
    }
}

void Snake::Draw()
{  
    for (unsigned int i = 0; i < mSnakes.size(); i++)
        mWindow.draw(mSnakes[i]);
}


std::vector<sf::RectangleShape> Snake::getSnakepos()
{
    return this->mSnakes;
}

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
    for (unsigned int i = 2; i < mSnakes.size(); i++) // Snake's boxes
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
