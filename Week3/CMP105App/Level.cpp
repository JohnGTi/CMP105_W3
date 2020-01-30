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

	// Render text
	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error Loading Font\n";
	}

	sweetMesg.setFont(font);
	sweetMesg.setString("Kerchow is " + std::to_string(kerchow) + " kerchows.");
	sweetMesg.setCharacterSize(16);
	sweetMesg.setFillColor(sf::Color::Red);
	//sweetMesg.setStyle(sf::Text::Bold);
	sweetMesg.setPosition(5, 5);

}

Level::~Level()
{
	//input = nullptr;
}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Down) == true)
	{
		//input->setKeyUp(sf::Keyboard::Down);
		kerchow = 100.f;
	}
	else if (input->isKeyDown(sf::Keyboard::Up) == true)
	{
		//input->setKeyUp(sf::Keyboard::Up);
		//std::cout << "bleh.\n";
		kerchow = 500.f;
	}
	else { kerchow = 200.f; }
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

	sweetMesg.setString("Kerchow is " + std::to_string(kerchow) + " kerchows.");
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(circle);
	window->draw(sweetMesg);
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