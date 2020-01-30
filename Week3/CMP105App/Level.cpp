#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	//Initialise game objects.
	circle.setRadius(25);
	circle.setPosition(300, 300);
	circle.setFillColor(sf::Color::Magenta);
	circle.setOutlineColor(sf::Color::Red);
	circle.setOutlineThickness(2.f);

	kerchow = 200.f;

	surkle.setRadius(25);
	surkle.setPosition(300, 300);
	surkle.setFillColor(sf::Color::Cyan);
	surkle.setOutlineColor(sf::Color::White);
	surkle.setOutlineThickness(2.f);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	sf::Vector2u pos = window->getSize(); //Get the size of the window.
	sf::Vector2f trespos = surkle.getPosition();

	if (input->isKeyDown(sf::Keyboard::Up) == true && trespos.y >= 0)
	{
		//input->setKeyUp(sf::Keyboard::Up);
		surkle.move(0, -200 * dt);
	}

	else if (input->isKeyDown(sf::Keyboard::Down) == true && trespos.y <= (pos.y - 50))
	{ surkle.move(0, 200 * dt); }

	else if (input->isKeyDown(sf::Keyboard::Left) == true && trespos.x >= 0)
	{ surkle.move(-200 * dt, 0); }

	else if (input->isKeyDown(sf::Keyboard::Right) == true && trespos.x <= (pos.x - 50))
	{ surkle.move(200 * dt, 0); }

}

// Update game objects
void Level::update(float dt)
{
	sf::Vector2u pos = window->getSize(); //Get the size of the window.
	sf::Vector2f dospos = circle.getPosition();

	if (dospos.y <= 0) { dirY = 1; }
	else if (dospos.x >= (pos.x - 50)) { dirX = -1; }
	else if (dospos.y >= (pos.y - 50)) { dirY = -1; }
	else if (dospos.x <= 0) { dirX = 1; }

	//Update/move circle xoxo
	circle.move(dirX * kerchow * dt, dirY * kerchow * dt); //offsetX and offsetY
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(circle);
	window->draw(surkle);
	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}