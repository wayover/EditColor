#include <iostream>
#include <string>
#include "ccolor.h"
#include "edit.h"

int main()
{

	Edit e;
	e.setPosition(5, 3);
	e.setLength(10);   
	e.setText("Aluuuuaf");                
	e.setTextColor(Edit::White);    
	e.setBackgroundColor(Edit::Blue);
	e.display();           
	std::string s = e.getText();
	e.userText();   
	s = e.getText();
	std::cout << red << "A" << green << "l" << blue << "a" << white << "ma" << SetColor(FOREGROUND_RED | FOREGROUND_GREEN) << s << /*defcolor <<*/ std::endl;
																																	
	system("pause");																													

	return 0;
}
