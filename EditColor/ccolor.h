



#ifndef CCOLOR_H_								//ochrona przed wielokrotym wlaczeniem
#define CCOLOR_H_

#include <windows.h>
#include <string>
struct struk									//struktoura potrzebna do stworzenia manipulatora setcolor
{
	WORD A;
};

inline
struk SetColor(WORD A)							//manipulator set color
{
	struk t = { A };
	return t;

}

class ccolor
{
protected:										//protected w przypadku dziedziczenia
	static WORD get_default_color()																		//defaultowy kolor
	{
		CONSOLE_SCREEN_BUFFER_INFO buff_info;
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &buff_info);
		return buff_info.wAttributes;
	}
	
public:
	static const WORD defaultColor;
	ccolor();																				//konstruktor bezparametrowy
	ccolor(const ccolor &t);																	//konstruktor kopiujacy
	virtual ~ccolor();																		//destruktor wirtualny w razie dziedziczenia


};

 std::ostream& operator <<(std::ostream&, struk);					//deklaracja operatora dla setcolor
 std::ostream & red(std::ostream & t);
 std::ostream & blue(std::ostream & t);
std::ostream & green(std::ostream & t);
 std::ostream & white(std::ostream & t);
















#endif // !CCOLOR_H_