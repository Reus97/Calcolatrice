/* This Class is structed to support the Calculator myFile
   created in .cpp code (SW Calculator);
   
   It's a .h source code, less powerly than .hpp or .h++, but
   this is the constructed used in our school course.
   
   This class is created to print some little graphic effects.
   
*/

/****************************************************************************************/  
/****************************** LIBRARY INCAPSULATION ***********************************/
/****************************************************************************************/
#ifndef CLASS_GRAPHIC  																  //Used to define class in all cases		
#define CLASS_GRAPHIC

#include "color.h"																		  //Self-made Class used to change cout color	
#include <iostream>																		  //Used for input/output			
#include <windows.h>																	  //Used for sleep functions		
#include <conio.h>																		  //Used for old C - CLASSIC instructions
#include <stdio.h>																		  //Used for old C - CLASSIC instructions			
#pragma GCC diagnostic ignored "-Wwrite-strings"				//Used to disable deprecated conversion from 
																						            //string constant to ‘char*’ (no conditioning) warning	
using namespace std;


/****************************************************************************************/  
/****************************** C - CODE INCAPSULATION  *********************************/
/****************************************************************************************/
//Use extern "C" to incapsulate c (pure) code inside a .cpp or .c++ file 
extern "C" 
{
	//"Welcome" to program function
	void TextFile_with1500Sleep (char FileName[5])
	{
		FILE *fnum;
    	char char_scanned;

    	fnum = fopen(FileName,"r");
    	while(!feof(fnum))
    	{
    		color_yellow();
        	fscanf(fnum,"%c",&char_scanned);
        	printf("%c", char_scanned);
    	}
    	cout<<endl;
    	fclose(fnum);
    	Sleep(1500);
	}
	
	//Start in 3/2/1 function
	void TextFile_with350Sleep (char FileName[5])
	{
		FILE *fnum;
    	char char_scanned;

    	fnum = fopen(FileName,"r");
    	while(!feof(fnum))
    	{
    		color_aqua();
        	fscanf(fnum,"%c",&char_scanned);
        	printf("%c", char_scanned);
    	}
    	fclose(fnum);
    	Sleep(350);
	}
	
	//Menu (basic) function
	void TextFile_menub (char FileName[5])
	{
		FILE *fnum;
    	char char_scanned;

    	fnum = fopen(FileName,"r");
    	while(!feof(fnum))
    	{
    		color_aqua();
        	fscanf(fnum,"%c",&char_scanned);
        	printf("%c", char_scanned);
    	}
    	fclose(fnum);
	}
	
	//Menu (special) function
	void TextFile_menus (char FileName[5])
	{
		FILE *fnum;
    	char char_scanned;

    	fnum = fopen(FileName,"r");
    	while(!feof(fnum))
    	{
    		color_aqua();
        	fscanf(fnum,"%c",&char_scanned);
        	printf("%c", char_scanned);
    	}
    	fclose(fnum);
    }
}


/****************************************************************************************/  
/******************************** CLASS DECLARATIONS ************************************/
/****************************************************************************************/
class graphic
{
	public:
	graphic();
	~graphic();
	
	void print_graphic_calculator();
	void print_graphic_ready();
};


/****************************************************************************************/  
/******************************** FUNCTIONS EXPLAIN  ************************************/
/****************************************************************************************/
graphic::graphic()
{	
}

graphic::~graphic()
{
	//cout<<"Oggetto distrutto"<<endl;
}

void print_graphic_calculator()
{
	 //This Instruction will run only if the program has a static save_position
	 //TextFile_with1500Sleep("/Users/MATTEO/Desktop/CALC_PROJECT/tmp_graphic/Much More Calculator.txt");
	 TextFile_with1500Sleep("Much More Calculator.txt");
	 cout<<endl<<endl;
	 color_gray();
	 cout<<"Clicca un tasto per continuare...";
	 getch();
	 system("CLS");
}

void print_graphic_ready()
{
	 //This Instruction will run only if the program has a static save_position
	 //TextFile_with350Sleep("/Users/MATTEO/Desktop/CALC_PROJECT/tmp_graphic/Start_in_3.txt");
	 TextFile_with350Sleep("Start_in_3.txt");
	 Sleep(200);
	 system("CLS");
	 
	 //This Instruction will run only if the program has a static save_position
	 //TextFile_with350Sleep("/Users/MATTEO/Desktop/CALC_PROJECT/tmp_graphic/Start_in_3.txt");
	 TextFile_with350Sleep("Start_in_2.txt");
	 Sleep(200);
	 system("CLS");
	 
	 //This Instruction will run only if the program has a static save_position
	 //TextFile_with350Sleep("/Users/MATTEO/Desktop/CALC_PROJECT/tmp_graphic/Start_in_3.txt");
	 TextFile_with350Sleep("Start_in_1.txt");
	 Sleep(200);
	 system("CLS");
}

#endif //CLASS_GRAPHIC
