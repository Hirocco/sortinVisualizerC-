#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class Kolumna
{
public:
	float dlugosc, szerokosc;
	float x, y;
	sf::Color kolor = sf::Color::White;		///ustawienie koloru
	sf::RectangleShape Rysuj()		//funkcja zwracajaca kolumne
	{
		sf::RectangleShape kol(sf::Vector2f(dlugosc, szerokosc));		//okreslenie rozmiaru kolumny
		kol.setPosition(sf::Vector2f(x, y));		//ustawienie kolumn
		kol.setFillColor(kolor);
		return kol;
	}
};

