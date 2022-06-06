#pragma once
#include <SFML/Graphics.hpp>

class Przycisk
{
public:
	Przycisk(std::string t,sf::Vector2f size,sf::Color bgcolor,sf::Color tekst_color);		//konstruktor
	//destruktor jest ustawiony domyœlny

	void setFont(sf::Font& font);

	void setBackgColor(sf::Color color);

	void setTextColor(sf::Color color);

	void setTextPosition(sf::Vector2f pos);

	void setBtnPosition(sf::Vector2f pos);

	void DrawTo(sf::RenderWindow& window);

	bool IsMoveOver(sf::RenderWindow& window);

private:
	sf::RectangleShape przycisk;
	sf::Text tekst;
};

