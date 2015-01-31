/* This Class is structed to support the Calculator myFile
   created in .cpp code (SW Calculator);
   
   It's a .h source code, less powerly than .hpp or .h++, but
   this is the constructed used in our school course.
   
   This class is created to resolve all operations, it also
   writes the results in a .txt myFile (result.txt).
   
*/

/****************************************************************************************/  
/****************************** LIBRARY INCAPSULATION ***********************************/
/****************************************************************************************/
#ifndef CLASS_CL_BASINSTRUCTION													//Used to define class in all cases		
#define CLASS_CL_BASINSTRUCTION												


#define PI 3.14159265																	  //Define declaration of 'Pi-Greco'			


#include <tgmath.h>																		  //Used for special math operation (sin, cos, tg, cotg...)	
#include <iostream>																		  //Used for input/output	
#include <math.h>																		    //Used for math operations		
#include <windows.h>																	  //Used for sleep functions	
#include <cstdio>																		    //Used for old C - CLASSIC instructions 	
#include <conio.h>																		  //Used for old C - CLASSIC instructions	
#include <fstream>																		  //Used to manage the myFile (result.txt / backup.txt)
#include <string.h>																		  //Used to manage strings
#include <stdlib.h> 																	  //Used for old C - CLASSIC instructions				
#include <cstdlib>																		  //Used for old C - CLASSIC instructions	
#include <sstream>																		  //Used to print stream string		
using namespace std;
fstream myFile;																			    //Declaration of file (will contain "result.txt")
int id = 0;																				      //Global variable used to write in txt a numerical progressive list	


/****************************************************************************************/  
/******************************** CLASS DECLARATIONS ************************************/
/****************************************************************************************/
class CL_BasInstruction
{
	public:
	CL_BasInstruction();
	~CL_BasInstruction();
	
	void Somma (float a);
	void Differenza (float a);
	void Moltiplicazione (float a);
	void Divisione (float a);
	void Radice();
	void Elevamento (int a);
	void DividiInt (float a);
    void Logaritmo();
    void SenoGrad();
    void CosenoGrad();

	float GetStatus();
	void SetStatus(float value);	
	
	
	//If some future programers will modify software
	//with ereditary or polimorphism structs, the class
	//is already passed as 'protected'.
	protected:
    float status;
    int ans;
};


/****************************************************************************************/  
/******************************** FUNCTIONS EXPLAIN  ************************************/
/****************************************************************************************/
CL_BasInstruction::CL_BasInstruction()
{
	status = 0;
}

CL_BasInstruction::~CL_BasInstruction()
{
	//cout<<"Oggetto distrutto"<<endl;
}

float CL_BasInstruction::GetStatus()
{
	return status;
}

void CL_BasInstruction::SetStatus(float value)
{
	status = value;
	myFile.open("result.txt", fstream::out |  fstream::app);
	myFile<<"Status set to "<<status<<" completed."<<endl<<endl;
    myFile.close();
}

void CL_BasInstruction::Somma(float a)
{   
    id++;
	status = status + a;
	myFile.open("result.txt", fstream::out | fstream::app);
	myFile<<id<<". "<<"Somma = "<<status<<endl<<endl;
    myFile.close();
}

void CL_BasInstruction::Differenza(float a)
{
	id++;
	status = status - a;
	myFile.open("result.txt", fstream::out | fstream::app);
	myFile<<id<<". "<<"Differenza = "<<status<<endl<<endl;
    myFile.close();
}

void CL_BasInstruction::Moltiplicazione(float a)
{
	id++;
	status = status * a;
	myFile.open("result.txt", fstream::out | fstream::app);
	myFile<<id<<". "<<"Moltiplicazione = "<<status<<endl<<endl;
    myFile.close();
}

void CL_BasInstruction::Divisione(float a)
{
	id++;
	status = status / a;
	myFile.open("result.txt", fstream::out | fstream::app);
	myFile<<id<<". "<<"Divisione fratta = "<<status<<endl<<endl;
    myFile.close();
}

void CL_BasInstruction::Radice()
{
	id++;
	status = sqrt(status);
	myFile.open("result.txt", fstream::out | fstream::app);
	myFile<<id<<". "<<"Radice = "<<status<<endl<<endl;
    myFile.close();
}

void CL_BasInstruction::Elevamento(int a)
{
	id++;
	
	if (a == 0)
	{
		//status = 1;
		myFile.open("result.txt", fstream::out | fstream::app);
		myFile<<id<<". "<<"Elevamento = 1"<<endl<<endl;
		myFile.close();
	}
	
	else
	{
	    status = pow(status, a);
	    myFile.open("result.txt", fstream::out | fstream::app);
	    myFile<<id<<". "<<"Elevamento = "<<status<<endl<<endl;
	    myFile.close();
	}
}

void CL_BasInstruction::DividiInt(float a)
{
	id++;
	status = (int)status / (int)a;
	myFile.open("result.txt", fstream::out | fstream::app);
	myFile<<id<<". "<<"Divisione intera = "<<status<<endl<<endl;
	myFile.close();
}

void CL_BasInstruction::Logaritmo()
{
	id++,
	status = log2(status);
	myFile.open("result.txt", fstream::out | fstream::app);
	myFile<<id<<". "<<"Logaritmo in base 2 = "<<status<<endl<<endl;
    myFile.close();
}

void CL_BasInstruction::SenoGrad()
{
	id++;
	status = sin(status * PI / 180.0);
	myFile.open("result.txt", fstream::out | fstream::app);
	myFile<<id<<". "<<"Seno (gradi) = "<<status<<endl<<endl;
    myFile.close();
}

void CL_BasInstruction::CosenoGrad()
{
	id++;
	status = cos(status * PI /180);
	myFile.open("result.txt", fstream::out | fstream::app);
	myFile<<id<<". "<<"Coseno (gradi) = "<<status<<endl<<endl;
    myFile.close();
}

#endif //CLASS_CL_BASINSTRUCTION
