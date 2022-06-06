#include "Przycisk.h"

Przycisk::Przycisk(std::string t, sf::Vector2f size, sf::Color bgcolor, sf::Color tekst_color)
{
	tekst.setString(t);
	tekst.setOutlineColor(tekst_color);
	tekst.setCharacterSize(20);

	przycisk.setSize(size);
	przycisk.setFillColor(bgcolor);
}

void Przycisk::setFont(sf::Font& font)
{
	tekst.setFont(font);
}

void Przycisk::setBackgColor(sf::Color color)
{
	przycisk.setFillColor(color);
}

void Przycisk::setTextColor(sf::Color color)
{
	tekst.setOutlineColor(color);
}

void Przycisk::setTextPosition(sf::Vector2f pos)
{
	float PosX = (pos.x + przycisk.getLocalBounds().width ) - tekst.getLocalBounds().width ;
	float PosY = (pos.y + przycisk.getLocalBounds().height ) - tekst.getLocalBounds().height ;

	tekst.setPosition(PosX, PosY);
}

void Przycisk::setBtnPosition(sf::Vector2f pos)
{
	float PosX = pos.x+przycisk.getLocalBounds().width;
	float PosY = pos.y + przycisk.getLocalBounds().height;

	przycisk.setPosition(PosX, PosY);
}

void Przycisk::DrawTo(sf::RenderWindow& window)
{
	window.draw(przycisk);
	window.draw(tekst);
}

bool Przycisk::IsMoveOver(sf::RenderWindow& window)
{
	float MouseX = sf::Mouse::getPosition(window).x;
	float MouseY = sf::Mouse::getPosition(window).y;

	float BtnX = przycisk.getPosition().x;
	float BtnY = przycisk.getPosition().y;

	float BtnPosWidth = BtnX + przycisk.getLocalBounds().width;
	float BtnPosHeight = BtnY + przycisk.getLocalBounds().height;

	if (MouseX > BtnX && MouseX < BtnPosWidth && MouseY > BtnY && MouseY < BtnPosHeight)
		return true;
	else return false;

}
