/* This Class is structed to support the Calculator myFile
   created in .cpp code (SW Calculator);
   
   It's a .h source code, less powerly than .hpp or .h++, but
   this is the constructed used in our school course.
   
   This class is created to print cout in different colors.
   
*/

/****************************************************************************************/  
/****************************** LIBRARY INCAPSULATION ***********************************/
/****************************************************************************************/
#ifndef CLASS_COLOR																		  //Used to define class in all cases		
#define CLASS_COLOR

#include <iostream>																		  //Used for input/output			
#include <windows.h>																	  //Used for sleep functions		
#include <conio.h>																		  //Used for old C - CLASSIC instructions	
using namespace std;


/****************************************************************************************/  
/******************************** CLASS DECLARATIONS ************************************/
/****************************************************************************************/
class color
{
	public:
	color();
	~color();
	
	void color_green();
	void color_green_bright();
	void color_red();
	void color_red_bright();
	void color_yellow();
	void color_yellow_bright();
	void color_aqua();
	void color_aqua_bright();
	void color_blue_bright();
	void color_default();
	void color_gray();
};


/****************************************************************************************/  
/******************************** FUNCTIONS EXPLAIN  ************************************/
/****************************************************************************************/
color::color()
{	
}

color::~color()
{
	//cout<<"Oggetto distrutto"<<endl;
}

void color_red()
{	
  int red = 4;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  red);
}

void color_red_bright()
{	
  int red_bright = 12;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  red_bright);
}

void color_green()
{
	int green = 2;
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  green);
}

void color_green_bright()
{
	int green_bright = 10;
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  green_bright);
}

void color_yellow()
{
	int yellow = 14;
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  yellow);
}

void color_yellow_bright()
{
	int yellow_bright = 6;
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  yellow_bright);
}

void color_default()
{
	int default_color = 7;
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  default_color);
}

void color_aqua()
{	
  int aqua = 3;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  aqua);
}

void color_aqua_bright()
{	
  int aqua_bright = 11;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  aqua_bright);
}

void color_blue_bright()
{
	int blue_light = 9;
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  blue_light);
}

void color_gray()
{
	int gray = 8;
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  gray);
}

#endif //CLASS_COLOR
