#include "ccolor.h"


ccolor::ccolor()									//puste z powodu braku zmiennych do przypisania
{
}

ccolor::ccolor(const ccolor & t)					//puste z powodu braku zmiennych do kopiowania
{
}

ccolor::~ccolor()									//puste z powodu braku alokowaniej pamieci
{
}







std::ostream & red(std::ostream & t)						//manipolator zmieniajacy kolor tekstu na czerwony
{
	HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hc, FOREGROUND_RED);
	return t;
}



std::ostream & blue(std::ostream & t)						//manipolator zmieniajacy kolor tekstu na niebieski
{
	HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hc, FOREGROUND_BLUE);
	return t;
}




std::ostream & green(std::ostream & t)						//manipolator zmieniajacy kolor tekstu na zielony
{
	HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hc, FOREGROUND_GREEN);
	return t;
}




std::ostream & white(std::ostream & t)						//manipolator zmieniajacy kolor tekstu na bia³y
{
	HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hc, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
	return t;
}



const WORD ccolor::defaultColor = ccolor::get_default_color();				





std::ostream& operator <<(std::ostream& p, struk t)			//operator<< dla SetColor
{
	HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hc,t.A);
	return p;
}


