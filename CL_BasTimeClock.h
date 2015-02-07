/* This Class is structed to support the Calculator myFile
   created in .cpp code (SW Calculator);
   
   It's a .h source code, less powerly than .hpp or .h++, but
   this is the constructed used in our school course.
   
   This class is created to see the time of last exit, last delete
   and last operation that is made with a backup of all of this
   in a .txt myFile (backup.txt).
   
*/

/****************************************************************************************/  
/****************************** LIBRARY INCAPSULATION ***********************************/
/****************************************************************************************/
#ifndef CLASS_CL_BASTIMECLOCK														//Used to define class in all cases
#define CLASS_CL_BASTIMECLOCK

#include <iostream>																		  //Used for input/output	
#include <math.h>																		    //Used for math operations		
#include <windows.h>																	  //Used for sleep functions	
#include <stdio.h>																		  //Used for old C - CLASSIC instructions 	
#include <conio.h>																		  //Used for old C - CLASSIC instructions	
#include <fstream>																		  //Used to manage the myFile (result.txt / backup.txt)
#include <string.h>																		  //Used to manage strings
#include <stdlib.h> 																	  //Used for old C - CLASSIC instructions	
#include <ctime>																		    //Used to control computer time	
using namespace std;
ofstream myClock;																		    //Declaration of file (will contain "backup.txt")	 


/****************************************************************************************/  
/******************************** CLASS DECLARATIONS ************************************/
/****************************************************************************************/
class CL_BasTimeClock
{
	public:
	CL_BasTimeClock();
	~CL_BasTimeClock();
	
	void currentDateToString_exit();											//When user exits	
	void currentDateToString_delete();										//When user deletes results.txt	
	void currentDateToString_delete_backup();							//When user deletes backup.txt 	
	
	/*protected:
	const time_t ctt = time(0);*/
};


/****************************************************************************************/  
/****************************** CLASS FUNCTION EXPLAIN **********************************/
/****************************************************************************************/
CL_BasTimeClock::CL_BasTimeClock()
{
	
}

CL_BasTimeClock::~CL_BasTimeClock()
{
	//cout<<"Oggetto distrutto"<<endl;
}


/****************************************************************************************/  
/******************************** FUNCTIONS EXPLAIN *************************************/
/****************************************************************************************/
//We've structed two similar function to demonstrate how it works.
void CL_BasTimeClock::currentDateToString_exit()
{
	myClock.open("backup.txt", fstream::app);
    
  time_t rawtime;
  struct tm * timeinfo;

  time ( &rawtime );
    
	/* Write in backup.txt when user exit */
	myClock<<"Last exit from program:   "<<ctime(&rawtime);                                  //Get time in this moment
	// << std::cout<< asctime(localtime(&ctt)) <<std::endl;                                  //Old instruction that run only in old version of Dev C++
  myClock.close();
}

void CL_BasTimeClock::currentDateToString_delete()
{
	myClock.open("backup.txt", fstream::app);
    
  time_t rawtime;
  struct tm * timeinfo;

  time ( &rawtime );
    
  /* Write in backup.txt when user clear result.txt */
  myClock<<"Last clear of result.txt: "<<ctime(&rawtime);                                  //Get time in this moment
  // << std::cout<< asctime(localtime(&ctt)) <<std::endl;                       				   //Old instruction that run only in old version of Dev C++
  myClock.close();
}

void CL_BasTimeClock::currentDateToString_delete_backup()
{
	myClock.open("backup.txt", fstream::app);
    
  time_t rawtime;
  struct tm * timeinfo;

  time ( &rawtime );
    
  /* Write in backup.txt when user clear backup.txt */
  myClock<<"Last clear of backup.txt: "<<ctime(&rawtime);                                  //Get time in this moment
  // << std::cout<< asctime(localtime(&ctt)) <<std::endl;                       				   //Old instruction that run only in old version of Dev C++
  myClock.close();
}

#endif //CLASS_CL_BASTIMECLOCK
