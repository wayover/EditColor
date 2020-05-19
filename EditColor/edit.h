
#ifndef EDIT_H_
#define EDIT_H_															
#include <windows.h>
#include <string>
#include <iostream>




class Edit
{
protected:																


	HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
	int dlugosc;
	std::string tekst;
	int bgcolor;
	int fgcolor;
	int x;
	int y;



public:


	enum color																				
	{
		Black = 1,
		DarkBlue = 2,
		DarkGreen = 3,
		DarkCyan = 4,
		DarkRed = 5,
		DarkMagenta = 6,
		DarkYellow = 7,
		Gray = 8,
		DarkGray = 9,
		Blue = 10,
		Green = 11,
		Cyan = 12,
		Red = 13,
		Magenta = 14,
		Yellow = 15,
		White = 16
	};


	Edit();																					
	Edit(int m_x,int m_y,int m_dlugosc,std::string m_tekst, int m_bgcolor,int m_fgcolor);
	Edit(const Edit &t);																	
	virtual ~Edit();																	
	void setPosition(int a_x,int a_y);														
	void setLength(int a_dlugosc);														
	void setText(std::string a_tekst);													
	void display();																			
	std::string getText();																
	void userText();																		
	BOOL setTextColor(color cl);															
	BOOL setBackgroundColor(color c2);														
};





#endif // !EDIT_H_
