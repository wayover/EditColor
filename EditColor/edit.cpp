#include "edit.h"



Edit::Edit()																						//konstruktor bezparametrowy
{

	x = 0;
	y = 0;
	dlugosc=1;
	tekst="";
	bgcolor = 0;
	fgcolor = 1;

}



Edit::Edit(int m_x, int m_y, int m_dlugosc, std::string m_tekst, int m_bgcolor, int m_fgcolor)		//kostruktor parametrowy
{

	try
	{
		x = m_x;
		y = m_y;
		if (x < 0 || y < 0)
			throw 0;
	}
	catch (int x)
	{
		std::cout << "pozycja x i y nie moze byc ujemna" << std::endl;
		system("pause");
		exit(0);
	}




	try
	{
		dlugosc = m_dlugosc;
		if (dlugosc<0)
			throw 0;
	}
	catch (int x)
	{
		std::cout << "dlugosc nie moze byc ujemna" << std::endl;
		system("pause");
		exit(0);
	}

	tekst = m_tekst;
	bgcolor = m_bgcolor;
	fgcolor = m_fgcolor;

}



Edit::Edit(const Edit & t)																			//konstruktor kopujacy
{

	x = t.x;
	y = t.y;
	bgcolor = t.bgcolor;
	fgcolor = t.fgcolor;
	dlugosc = t.dlugosc;
	tekst = t.tekst;

}




Edit::~Edit()																						//destruktor pusty, poniewaz nie przydzielamy pamieci dynamicznej
{

}



void Edit::setPosition(int a_x, int a_y)															//seter przypisujacy wartosci dla x i y
{
	try
	{
		x = a_x;
		y = a_y;
		if (x < 0 || y < 0)
			throw 0;
	}
	catch (int x)
	{
		std::cout << "pozycja x i y nie moze byc ujemna"<<std::endl;
		system("pause");
		exit(0);
	}


}




void Edit::setLength(int a_dlugosc)																	//seter przypisujacy wartosci dla dlugosci tekstu
{

	try
	{
		dlugosc = a_dlugosc;
		if (dlugosc < 0)
			throw 0;
	}
	catch (int x)
	{
		std::cout << "dlugosc nie moze byc ujemna" << std::endl;
		system("pause");
		exit(0);
	}

}



void Edit::setText(std::string a_tekst)																//seter przypisujacy tekst oraz w warzie potrzeby dodajacy spacje albo usowajacy znaki
{

	int roz = 0;
	int dod = 0;
	int dltekst = a_tekst.length();


	if (dltekst == dlugosc)				//tekst rowny dlugosci podanej
	{
		tekst = a_tekst;
	}
	else if (dltekst < dlugosc)			//tekst krotszy niz podany tekst
	{
		tekst = a_tekst;
		roz = dlugosc - dltekst;
		for (int i = 0; i < roz; i++)
		{
			tekst = tekst + " ";		//uzupelnianie spacjami
		}
	}
	else								//usowanie tekstu jezeli jest go za duzo
	{
		dod = dltekst - dlugosc;
		a_tekst.erase(dlugosc, dod);
		tekst = a_tekst;
	}
}



void Edit::display()																				//metoda wyswietlajaca tekst
{

	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(hc, c);
	std::cout << tekst;

}



std::string Edit::getText()																			//metoda pobierajaca i zwracajaca tekst
{

	std::string text = tekst;
	return text;

}



void Edit::userText()																				//metoda do edycji tekstu
{

	COORD c;
	c.X = 40;
	c.Y = 5;
	SetConsoleCursorPosition(hc, c);					//"menu"
	std::cout << "<-/-> przesuniêcie w lewo/prawo";
	c.X = 40;
	c.Y = 6;
	SetConsoleCursorPosition(hc, c);
	std::cout << "Backspace - usuwanie";
	c.X = 40;
	c.Y = 7;
	SetConsoleCursorPosition(hc, c);
	std::cout << "enter - koniec";





	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(hc, c);
	int pozycja =0;
	int koniec = 1;




	while (koniec == 1)									//petla wykonuje sie dopoki koniec jest rowny 1
	{
		int a = 0;
		a = _getwch();									//pobranie znaku



		if (a == 224)
		{
			a = _getwch();


			if (a == 75)				//strzalka w lewo
			{
				if (pozycja !=0)
				{
					x--;
					pozycja--;
				}
			}


			else if (a == 77)			//strzalka w prawo
			{
				if (pozycja !=(dlugosc-1))
				{
					x++;
					pozycja++;
				}
			}
		}
		else if (a >= 32 && a <= 126)	//reszta znakow
		{

			char b;
			b = (int)a;


			if (pozycja == (dlugosc-1))
			{
				tekst[pozycja] = b;
				std::cout << tekst[pozycja];
			}
			else
			{
				tekst[pozycja] = b;
				std::cout << tekst[pozycja];
				x++;
				pozycja++;
			}
		}


		else if (a == 8)				//backspace
		{
			if (pozycja == 0)
			{
				tekst[pozycja] = ' ';
				std::cout << tekst[pozycja];
			}
			else if (pozycja !=0)
			{
				x--;
				pozycja--;
				tekst[pozycja] = ' ';
				std::cout << tekst[pozycja];
			}
		}


		else if (a == 13)				//enter
		{
			koniec = 0;
		}
		c.X = x;
		c.Y = y;
		SetConsoleCursorPosition(hc, c);
	}

}



BOOL Edit::setTextColor(color c1)													//metoda ustawiajaca kolor tekstu
{

	fgcolor = c1;
	return SetConsoleTextAttribute(hc, (fgcolor + (bgcolor - 1) * 16) - 1);

}



BOOL Edit::setBackgroundColor(color c2)												//metoda ustawiajaca kolor tla
{

	bgcolor = c2;
	return SetConsoleTextAttribute(hc, (fgcolor + (bgcolor - 1) * 16) - 1);

}


