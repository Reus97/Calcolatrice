/* This Class is structed to support the Calculator myFile
   created in .cpp code (SW Calculator);
   
   It's a .h source code, less powerly than .hpp or .h++, but
   this is the constructed used in our school course.
   
   This class is created to implements the "Cout File Functions".
   
*/

/****************************************************************************************/  
/****************************** LIBRARY INCAPSULATION ***********************************/
/****************************************************************************************/
#ifndef CLASS_FONT_DOC														      //Used to define class in all cases		
#define CLASS_FONT_DOC

#include "color.h"																		  //Self-made Class used yto change cout color		
#include <iostream>																		  //Used for input/output	
#include <math.h>																		    //Used for math operations		
#include <windows.h>																	  //Used for sleep functions	
#include <stdio.h>																		  //Used for old C - CLASSIC instructions 	
#include <conio.h>																		  //Used for old C - CLASSIC instructions	
#include <fstream>																		  //Used to manage the myFile (result.txt / backup.txt)
#include <string.h>																		  //Used to manage strings
#include <stdlib.h> 																	  //Used for old C - CLASSIC instructions
using namespace std;

int remove(const char *documentation);									//Function that remove txt and doc files	


/****************************************************************************************/  
/******************************** CLASS DECLARATIONS ************************************/
/****************************************************************************************/
class font_doc
{
	public:
	font_doc();
	~font_doc();
	
	void SaveDocumentationTxt();
	void SaveDocumentationDoc();
	//void SaveDocumentationDocx();
	bool DeleteDocumentationTxt();
	bool DeleteDocumentationDoc();
	
};


/****************************************************************************************/  
/******************************** FUNCTIONS EXPLAIN  ************************************/
/****************************************************************************************/
font_doc::font_doc()
{

}

font_doc::~font_doc()
{
	//cout<<"Oggetto distrutto"<<endl;
}

void SaveDocumentationTxt()
{
	int m = 0;
	
	//It runs twice beacue in first time creates .txt and in second time writes on it.
	while (m < 2)
	{
		ofstream myTxt;
		myTxt.open("documentation.txt", fstream::out | fstream::app);
		myTxt<<"// ============================ DOCUMENTATION ============================ //"<<endl;
		myTxt<<endl;
		myTxt<<"ASSISTITI MATTEO Software Engineer (c)"<<endl;
	
    	myTxt<<"The following software is structed to support a new calculator"<<endl;
    	myTxt<<"Software (c) based on the classics calculators that we use"<<endl;
    	myTxt<<"every day. (or not?)"<<endl;
    	myTxt<<"That calculator, only for this version, start with the "<<endl;
    	myTxt<<"basic instructions in a simple prompt program."<<endl;
    	myTxt<<endl<<endl;	
    	myTxt<<"The following program can make also other operand, if the clients will ask for them"<<endl; 
    	myTxt<<"the programmer will make it."<<endl; 
  
    	myTxt<<"It creates a .txt myFile called result.txt, that has some different things that"<<endl;
    	myTxt<<"I'll explain n the fix part."<<endl;
  
    	myTxt<<"It has a main.cpp that used the simple function of a Menu() and a"<<endl; 
    	myTxt<<"personal Library CL_BasInstruction, that offers some math types of"<<endl;
    	myTxt<<"calculations."<<endl;
  
    	myTxt<<"It has comment on the most difficult instructions to explain how they work,"<<endl;
    	myTxt<<"if the clients want more they have only to ask to me."<<endl;
    	myTxt<<endl<<endl;
   
    	myTxt<<"// ================================ HISTORY ================================ //"<<endl;
    	myTxt<<endl<<endl;
    	myTxt<<"FIX v1.0    -> The program was designed on Christmas Day, it has only the basic operation"<<endl;
    	myTxt<<"				  instructions."<<endl;
    	myTxt<<"FIX v1.0.1  -> The program has identated, commented and it has some basic variables"<<endl; 
    	myTxt<<"			      to resolve the crash problems."<<endl;
    	myTxt<<"FIX v1.1    -> The program resolves the sqrt, pow and int result of division instruction."<<endl;
    	myTxt<<"FIX v2.0    -> The program can create a result.txt myFile that contains the results of all"<<endl;
    	myTxt<<"				  operations, it lets you also see the type of instruction and the result of"<<endl;
    	myTxt<<"				  the same."<<endl;
    	myTxt<<"FIX v2.1    -> The program lets you choose a new option, if you want you can delete all"<<endl;
    	myTxt<<"               contenues inside the result.txt myFile, it could be choose in the menu."<<endl;
    	myTxt<<"FIX v2.2    -> The program resolves the log, sen and cos instructions."<<endl;
    	myTxt<<"FIX v3.0    -> The program creates another .txt myFile that contains the number of exit_time"<<endl; 
    	myTxt<<"               that the user has made with DD/MM/YYYY and H/MM/SS type. (backup.txt)"<<endl;
    	myTxt<<"				  That function is made in a new class library."<<endl;
    	myTxt<<"FIX v3.1    -> In the backup.txt myFile the program saves also the last clear of result.txt and"<<endl;
    	myTxt<<"				  writes the last operation that user has made."<<endl;
    	myTxt<<"FIX v3.2    -> This upgrade saves inside backup.txt if the user choose to delete the"<<endl;
    	myTxt<<"				  informations inside backup."<<endl;
    	myTxt<<"FIX 4.0     -> The user can save a documentation of this software."<<endl;
    	myTxt<<endl<<endl;
		
		m++;
		
	    myTxt.close();
	}
    
}

void SaveDocumentationDoc()
{
	ofstream myDoc;
	myDoc.open("documentation.doc", fstream::out | fstream::app);
	myDoc<<"DOCUMENTATION "<<endl;
	myDoc<<endl;
	myDoc<<"ASSISTITI MATTEO Software Engineer (c)"<<endl;
	
    myDoc<<"The following software is structed to support a new calculator"<<endl;
    myDoc<<"Software (c) based on the classics calculators that we use"<<endl;
    myDoc<<"every day. (or not?)"<<endl;
    myDoc<<"That calculator, only for this version, start with the "<<endl;
    myDoc<<"basic instructions in a simple prompt program."<<endl;
    myDoc<<endl<<endl;	
    myDoc<<"The following program can make also other operand, if the clients will ask for them"<<endl; 
    myDoc<<"the programmer will make it."<<endl; 
  
    myDoc<<"It creates a .txt myFile called result.txt, that has some different things that"<<endl;
    myDoc<<"I'll explain n the fix part."<<endl;
    
	myDoc<<"It has a main.cpp that used the simple function of a Menu() and a"<<endl; 
   	myDoc<<"personal Library CL_BasInstruction, that offers some math types of"<<endl;
    myDoc<<"calculations."<<endl;
  
    myDoc<<"It has comment on the most difficult instructions to explain how they work,"<<endl;
    myDoc<<"if the clients want more they have only to ask to me."<<endl;
    myDoc<<endl<<endl;
   
    myDoc<<endl<<"HISTORY "<<endl;
    myDoc<<"FIX v1.0    -> The program was designed on Christmas Day, it has only the basic operation"<<endl;
    myDoc<<"				  instructions."<<endl;
    myDoc<<"FIX v1.0.1  -> The program has identated, commented and it has some basic variables"<<endl; 
    myDoc<<"			      to resolve the crash problems."<<endl;
    myDoc<<"FIX v1.1    -> The program resolves the sqrt, pow and int result of division instruction."<<endl;
    myDoc<<"FIX v2.0    -> The program can create a result.txt myFile that contains the results of all"<<endl;
    myDoc<<"				  operations, it lets you also see the type of instruction and the result of"<<endl;
    myDoc<<"				  the same."<<endl;
    myDoc<<"FIX v2.1    -> The program lets you choose a new option, if you want you can delete all"<<endl;
    myDoc<<"               contenues inside the result.txt myFile, it could be choose in the menu."<<endl;
    myDoc<<"FIX v2.2    -> The program resolves the log, sen and cos instructions."<<endl;
    myDoc<<"FIX v3.0    -> The program creates another .txt myFile that contains the number of exit_time"<<endl; 
    myDoc<<"               that the user has made with DD/MM/YYYY and H/MM/SS type. (backup.txt)"<<endl;
    myDoc<<"				  That function is made in a new class library."<<endl;
    myDoc<<"FIX v3.1    -> In the backup.txt myFile the program saves also the last clear of result.txt and"<<endl;
    myDoc<<"				  writes the last operation that user has made."<<endl;
    myDoc<<"FIX v3.2    -> This upgrade saves inside backup.txt if the user choose to delete the"<<endl;
    myDoc<<"				  informations inside backup."<<endl;
    myDoc<<"FIX 4.0     -> The user can save a documentation of this software."<<endl;
    myDoc<<endl<<endl;
	myDoc.close();
}

bool DeleteDocumentationTxt()
{	
	if(remove("documentation.txt") != 0)
    {  
	    //perror("Error deleting file");
        cout<<"File 'documentation.txt' ";
        color_red();
        cout<<"non found"<<endl;
        color_default();
        return false;
    }
	
	else
    {
        //puts("File successfully deleted");
		cout<<"File 'documentation.txt' ";
        color_green();
        cout<<"found"<<endl;
        color_default();
    	return true;
	}  
}

bool DeleteDocumentationDoc()
{	
	if(remove("documentation.doc") != 0)
    {  
	    //perror("Error deleting file");
        cout<<"File 'documentation.doc'";
        color_red();
        cout<<"non found"<<endl;
        color_default();
        return false;
    }
	
	else
    {
        //puts("File successfully deleted");
		cout<<"File 'documentation.doc'";
        color_green();
        cout<<"found"<<endl;
        color_default();
    	return true;
	}  
}

#endif //CLASS_FONT_DOC
