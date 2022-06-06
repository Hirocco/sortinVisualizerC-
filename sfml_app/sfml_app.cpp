#include <iostream>
#include <SFML/Graphics.hpp>
#include "Kolumna.h"
#include "Przycisk.h"

//zmienne globalne
using namespace std;
const int rozm = 100;
int maxwart = 599;

//sortowania
void losowanie(int t[]);

void SortowaniePrzezWstawianie(int t[], int height, float unit);

void SortowanieBombelkowe(int t[], int height, float unit);

void SortowaniePrzezWybor(int t[], int height, float unit);

int main()
{
	/*Tych nie dotykam*/
	int tablica[rozm];
	losowanie(tablica);
	int wysokosc = 1;
	float jednostka = 800 / rozm;		///zlozenie ich na dlugosc okna 
	sf::sleep(sf::microseconds(5));		///niech poczeka przed wykonaniem 

	setlocale(LC_CTYPE, "Polish");			//polskie znaki
	/* do tego momentu nie tykam */
	
	sf::RenderWindow window(sf::VideoMode(800, 600), "Menu");

	sf::Font Exclusive;
	Exclusive.loadFromFile("Exclusive-Serif.ttf");

	Przycisk p1("Sortowanie przez wybór", {300,100},sf::Color::Cyan,sf::Color::White);
	p1.setTextPosition({ 0,-75 });
	p1.setBtnPosition({ -50,-100 });
	p1.setFont(Exclusive);

	Przycisk p2("Sortowanie bąbelkowe", {300,100}, sf::Color::Green, sf::Color::White);
	p2.setBtnPosition({ -50,50 });
	p2.setTextPosition({ 0,85 });
	p2.setFont(Exclusive);

	Przycisk p3("Sortowanie przez wstawianie", { 300,100 }, sf::Color::Yellow, sf::Color::White);
	p3.setBtnPosition({ -50,200 });
	p3.setTextPosition({ 0,235 });
	p3.setFont(Exclusive);

	while (window.isOpen())
	{
		sf::Event klik;
		while (window.pollEvent(klik))
		{
			switch (klik.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseMoved:
				if (p1.IsMoveOver(window))	p1.setBackgColor(sf::Color::Blue);
				else p1.setBackgColor(sf::Color::Cyan);

				if (p2.IsMoveOver(window))	p2.setBackgColor(sf::Color::Blue);
				else p2.setBackgColor(sf::Color::Green);

				if (p3.IsMoveOver(window))	p3.setBackgColor(sf::Color::Blue);
				else p3.setBackgColor(sf::Color::Yellow);

				break;
			case sf::Event::MouseButtonPressed:
				if (p1.IsMoveOver(window))
					SortowaniePrzezWybor(tablica, wysokosc, jednostka);
				if (p2.IsMoveOver(window))
					SortowanieBombelkowe(tablica, wysokosc, jednostka);
				if (p3.IsMoveOver(window))
					SortowaniePrzezWstawianie(tablica, wysokosc, jednostka);
				break;
			}
		}
		window.clear(sf::Color::Black);
		p1.DrawTo(window);
		p2.DrawTo(window);
		p3.DrawTo(window);
		window.display();
	}

	return 0;
}

void SortowaniePrzezWybor(int t[], int height, float unit)
{
	bool koniec = false;
	sf::RenderWindow okno(sf::VideoMode(800, 600), "Wizualizer sortowania przez wybór");
	while (okno.isOpen())
	{
		sf::Event klik;
		while (okno.pollEvent(klik))
		{
			if (klik.type == sf::Event::Closed)
				okno.close();
		}
		int pozmax;
		for (int i = 0; i < rozm - 1; i++)
		{
			pozmax = i;
			for (int j = i + 1; j < rozm; j++)
			{
				for (int r = 0; r < rozm; r++)
				{
					if (r != j)
					{
						Kolumna kol;		//utworzenie obiektu 
						kol.dlugosc = unit - 1;
						kol.szerokosc = -t[r] * height;
						kol.x = r * unit;
						kol.y = 600;
						okno.draw(kol.Rysuj());
					}
				}
				Kolumna kol;		//utworzenie obiektu 
				kol.dlugosc = unit - 1;
				kol.szerokosc = -t[j] * height;
				kol.x = j * unit;
				kol.y = 600;
				kol.kolor = sf::Color::Red;
				okno.draw(kol.Rysuj());
				okno.display();

				okno.clear(sf::Color::Black);
				if (t[pozmax] < t[j])	pozmax = j;

				swap(t[pozmax], t[j]);
			}
		}
	}
	okno.display();
}

void SortowanieBombelkowe(int t[], int height, float unit)
{
	bool koniec = false;
	sf::RenderWindow okno(sf::VideoMode(800, 600), "Wizualizer sortowania bąbelkowego");
	while (okno.isOpen())
	{
		sf::Event klik;
		while (okno.pollEvent(klik))
		{
			if (klik.type == sf::Event::Closed)		//jak klikniemy na krzyzyk to okienko sie wylacza
				okno.close();
		}

		for (int i = 0; i < rozm - 1; i++)
		{
			for (int j = i + 1; j < rozm; j++)
			{
				for (int r = 0; r < rozm; r++)
				{
					if (r != j)
					{
						Kolumna kol;		//utworzenie obiektu 
						kol.dlugosc = unit - 1;
						kol.szerokosc = -t[r] * height;
						kol.x = r * unit;
						kol.y = 600;
						okno.draw(kol.Rysuj());
					}
				}
				Kolumna kol;		//utworzenie obiektu 
				kol.dlugosc = unit - 1;
				kol.szerokosc = -t[j] * height;
				kol.x = j * unit;
				kol.y = 600;
				kol.kolor = sf::Color::Red;
				okno.draw(kol.Rysuj());
				okno.display();

				okno.clear(sf::Color::Black);
				if (t[i] > t[j])
					swap(t[i], t[j]);
			}
			/*
			if (i == rozm - 1)
				koniec = true;
			if (koniec)
			{
				for (int r = 0; r < rozm; r++)
				{
					Kolumna kol;
					kol.dlugosc = unit - 1;
					kol.szerokosc = -t[r] * height;
					kol.x = r * unit;
					kol.y = 600;
					kol.kolor = sf::Color::Green;
					okno.draw(kol.Rysuj());
					okno.display();
				}
			}*/
		}
	}
	okno.display();
}

void SortowaniePrzezWstawianie(int t[], int height, float unit)
{
	bool koniec = false;
	sf::RenderWindow okno(sf::VideoMode(800, 600), "Wizualizer sortowania przez wstawianie");
	while (okno.isOpen())
	{
		sf::Event klik;
		while (okno.pollEvent(klik))
		{
			if (klik.type == sf::Event::Closed)		//jak klikniemy na krzyzyk to okienko sie wylacza
				okno.close();
		}

		int poz;
		for (int i = 0; i < rozm - 1; i++)
		{
			poz = i - 1;

			while (poz<rozm - 1 && t[poz]>t[poz + 1])
			{
				//poczatkowe namalowanie kolumn
				for (int r = 0; r < rozm; r++)
				{
					if (r != poz)
					{
						Kolumna kol;		//utworzenie obiektu 
						kol.dlugosc = unit - 1;
						kol.szerokosc = -t[r] * height;
						kol.x = r * unit;
						kol.y = 600;
						okno.draw(kol.Rysuj());
					}
				}
				Kolumna kol;
				kol.dlugosc = unit - 1;
				kol.szerokosc = -t[poz] * height;
				kol.x = poz * unit;
				kol.y = 600;
				kol.kolor = sf::Color::Red;
				okno.draw(kol.Rysuj());
				okno.display();

				okno.clear(sf::Color::Black);
				swap(t[poz], t[poz + 1]);
				poz++;
			}
			/*if (i == rozm - 1)
				koniec = true;
			if (koniec)
			{
				//wyswietlanie kolumny zakonczonej
				for (int r = 0; r < rozm; r++)
				{
					Kolumna kol;
					kol.dlugosc = unit - 1;
					kol.szerokosc = -t[r] * height;
					kol.x = r * unit;
					kol.y = 600;
					kol.kolor = sf::Color::Green;
					okno.draw(kol.Rysuj());
					okno.display();
				}
			}*/
		}
		
	}
	okno.display();
}

void losowanie(int t[])
{
	srand(time(NULL));
	for (int i = 0; i < rozm; i++) t[i] = rand() % maxwart;
}

