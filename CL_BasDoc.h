/* This Class is structed to support the Calculator myFile
   created in .cpp code (SW Calculator);
   
   It's a .h source code, less powerly than .hpp or .h++, but
   this is the constructed used in our school course.
   
   This class is created to save a completly documentation
   about this software.
   
*/

/****************************************************************************************/  
/****************************** LIBRARY INCAPSULATION ***********************************/
/****************************************************************************************/
#ifndef CLASS_CL_BASDOC															    //Used to define class in all cases		
#define CLASS_CL_BASDOC

#include "font_doc.h"																	  //Self-made Class that content documentation	
#include "color.h"																		  //Self-made Class used yto change cout color	
#include "CL_BasTimeClock.h"
#include <iostream>																		  //Used for input/output	
#include <math.h>																		    //Used for math operations		
#include <windows.h>																	  //Used for sleep functions	
#include <stdio.h>																		  //Used for old C - CLASSIC instructions 	
#include <conio.h>																		  //Used for old C - CLASSIC instructions	
#include <fstream>																		  //Used to manage the myFile (result.txt / backup.txt)
#include <string.h>																		  //Used to manage strings
#include <stdlib.h> 																	  //Used for old C - CLASSIC instructions
using namespace std;


char answer_clr;																		    //If user want or not to clear backup.txt
int var_up = 0;																			    //Used in while loop			
int var_cl = 0;																			    //Used in while loop				
int point_temp = 0;																		  //Used in while loop	
int point_cl = 0;																		    //Used in while loop			
	
CL_BasTimeClock timeClock;															//Instance of CL_BasTimeClock self-made library	
float temp = 0;																			    //'temp' Variable	
	
bool isDelete  = true;																  //Used to verify if .txt was deleted		 
bool isDeleDoc = true;																  //Used to verify if .doc was deleted			
char deleteMenuRequest;																  //If user want to delete only .txt, only .doc or both of them		

int remove(const char *documentation);									//Function that remove txt and doc files

//Enum struct that contains "string" variables
enum string_code
{
	 savedoc,
	 deledoc,
	 clear_r,
	 backup_t,
	 ret_menu,
	 //no_status,
	 quit
};

//String function that verify "mystring" and return struct enum strings
string_code hashit (string const& inString) 
{
    	if (inString ==  "savedoc")   return savedoc;
    	if (inString ==  "deledoc")   return deledoc;
    	if (inString ==  "clear_r")   return clear_r;
    	if (inString == "backup_t")   return backup_t;
		if (inString == "ret_menu")   return ret_menu;
		if (inString ==     "quit")   return quit;
}

char Menu_DeleteCondition()
{
	char choice;
	
	system("CLS");
	cout<<"Do you want to delete:"<<endl<<endl;
	cout<<"a) documentation.txt"<<endl;
	cout<<"b) documemntation.doc"<<endl;
	cout<<"c) Both of them"<<endl;
	cout<<endl<<endl;
	cout<<"'Anything else': Sorry, I got choice ";
	color_red();
	cout<<"wrong."<<endl;
	color_default();
	cout<<endl;
	cout<<"Choice -> ";
	cin>>choice;
	
	return choice;
}

        void DisplayRecurceLBLSpecial_Quit()
        {
        	MessageBox(NULL,"     Thanks To Support This Software.","GOODBYE USER",MB_ICONASTERISK | MB_OK | MB_DEFBUTTON2);
        }

        void DisplayRecurceLBLSpecial_CreateDoc()
        {
        	MessageBox(NULL,"Documentations are been created successfully.","Documentation",MB_ICONEXCLAMATION | MB_OK | MB_DEFBUTTON2);
        }

        void DisplayRecurceLBLSpecial_DeleteDoc()
        {
        	MessageBox(NULL,"Documentations are been deleted successfully.","Documentation",MB_ICONHAND | MB_OK | MB_DEFBUTTON2);
        }

/****************************************************************************************/  
/******************************** CLASS DECLARATIONS ************************************/
/****************************************************************************************/
class CL_BasDoc
{
	public:
	CL_BasDoc();
	~CL_BasDoc();
	
	void SaveDocumentation();
	bool DeleteDocumentation();
	bool DeleteDocumentationD();
	string Menu_Special();
	void Call();
	
};


/****************************************************************************************/  
/******************************** FUNCTIONS EXPLAIN  ************************************/
/****************************************************************************************/
CL_BasDoc::CL_BasDoc()
{

}

CL_BasDoc::~CL_BasDoc()
{
	//cout<<"Oggetto distrutto"<<endl;
}

void CL_BasDoc::SaveDocumentation()
{
    SaveDocumentationTxt();
    SaveDocumentationDoc();
    //SaveDocumentationDocx();
}

bool CL_BasDoc::DeleteDocumentation()
{	
	return DeleteDocumentationTxt();	  
}

bool CL_BasDoc::DeleteDocumentationD()
{	
	return DeleteDocumentationDoc(); 
}

string CL_BasDoc::Menu_Special()
{
	string scelta;
	
	cout<<"=========================================|"<<endl;    
	cout<<"savedoc  Salva la documentazione e 	 |   "<<endl;	
	cout<<"         la timeline delle versioni      |"<<endl;
	cout<<"=========================================|"<<endl;
	cout<<"deledoc  Elimina la documentazione e     |"<<endl;
	cout<<"         la timeline delle versioni      |"<<endl;
	cout<<"=========================================|"<<endl;
	cout<<"clear_r  Pulisci myFile result.txt       |"<<endl;
	cout<<"=========================================|"<<endl;
	cout<<"backup_t Backup myFile result.txt in     |"<<endl;
	cout<<"         backup.txt ed esci	         |   "<<endl;
	cout<<"=========================================|"<<endl;
	cout<<"quit     Esci (senza backup)             |"<<endl;
	cout<<"=========================================|"<<endl;
	cout<<"ret_menu Torna al Menu                   |"<<endl;
	cout<<"=========================================|"<<endl;

	cout<<endl;
	getline(cin, scelta);
	
	return scelta;
}

void CL_BasDoc::Call()
{
	string menu;
	menu = Menu_Special();
	
    switch (hashit(menu)) 
	{
    	   case quit:
		   		myFile.open("result.txt", fstream::out | fstream::app);
				myFile<<"You are exit. (Special Menu)"<<endl;
		   		myFile<<"************************************************"<<endl<<endl;
		  		myFile.close();
				system("CLS");
		   		cout<<"Exit ";
		   		color_green();
		   		cout<<"success!"<<endl;
		   		color_default();	 	 
		  		timeClock.currentDateToString_exit();
		  		color_default();
                                DisplayResourceLBLSpecial_Quit();
				exit(0);
				break;
				
				
			//Type backup_t: create backup.txt	
			case backup_t:
				system("CLS");	 
		   		cout<<"Exit success!"<<endl;
		   		cout<<endl<<"Backup created. Do you want to clear the backup?"<<endl;
		   		cout<<"\t-> Yes (y) - No (n)"<<endl;
		   		cout<<"\t   ";
		   		cin>>answer_clr;
		   
		   		//DELETE CACHE and CLEAR BACKUP
		   		if ((answer_clr == 'y') || (answer_clr == 'Y'))
		   		{
		   	       /* It deletes twice because the trunc function in first loop 
					  it deletes only phisical words inside .txt but leaves
		   	          the cache iSntact and it could restore the informations by
				      itself, in the second loop it removes completly all 
				      informations contain in the cache-memory.
				   */
				   
				   while (var_cl < 2)
			       {
			    		myClock.open("backup.txt", fstream::out | fstream::trunc);
						var_cl++;
				        myClock.close();
			       }
				
				   cout<<endl<<"\t   I'm ";
				   color_red();
				   cout<<"deleting ";
				   color_default();
				   cout<<"backup.txt informations";
				
				   //Creates the "... thinking effect" 
				   while (point_cl < 3)
				   {
					   Sleep(1000);
					   cout<<".";
					   point_cl++;
				   }
				
				   timeClock.currentDateToString_delete_backup();
				
				   point_cl = 0;
				   var_cl = 0;
			       //getch();
			       cout<<endl;
			  	   cout<<endl<<"\t   ";
		        } 
		   
		        //SAVE without DELETING ANYTHING 		
		   		else if ((answer_clr == 'n') || (answer_clr == 'N'))
		   		{
                   cout<<endl<<"\t   I'm ";
                   color_green();
				   cout<<"creating and saving ";
				   color_default();
				   cout<<"backup.txt informations";
				
				   //Creates the "... thinking effect"
				   while (point_cl < 3)
			   	   {
					  Sleep(1000);
					  cout<<".";
					  point_cl++;
				   }
				   point_cl = 0;
				
		   		   timeClock.currentDateToString_exit();
				   Sleep(250);
				   cout<<endl<<"\t   ";
		        }
		   
		   
		   		//DEFAULT OPTION		
		   		else
		   		{	
		   	       color_yellow();		 
				   cout<<"\tYou've choosen a wrong chance'..."<<endl;
				   Sleep(1000);
				   cout<<endl<<"\t   ";
				   color_default();
		  	 	}
		   
		        myFile.open("result.txt", fstream::out | fstream::app);
		   		myFile<<"You are ";
				color_green();   
				cout<<"exit and have made a backup with success."<<endl;
				color_default();
		   		myFile<<"**********************************************************"<<endl<<endl;
		   		cout<<endl;
		   		myFile.close();
		   		break;
		   	
		
			//Type clear_r: clear result.txt
			case clear_r:
				system("CLS");
				while (var_up < 2)
			    {
			    	myFile.open("result.txt", fstream::out | fstream::trunc);
			    	myFile.close();
					Sleep(250);
					var_up++;
					myFile.close();
			    }
			    
				timeClock.currentDateToString_delete();
				cout<<endl<<"I'm ";
				color_red();
				cout<<"deleting ";
				color_default();
				cout<<"result.txt informations";
				
				while (point_temp < 3)
				{
					  Sleep(1000);
					  cout<<".";
					  point_temp++;
				}
				point_temp = 0;
				var_up = 0;
				cout<<endl;
				break;
				
			
			//Type savedoc: save documentation
			case savedoc:
				system("CLS");
			    
				SaveDocumentation();
				
				cout<<endl<<"I'm ";
				color_green();
				cout<<"saving ";
				color_default();
				cout<<"documentation";
				
				while (point_temp < 3)
				{
					  Sleep(1000);
					  cout<<".";
					  point_temp++;
				}
				point_temp = 0;
				var_up = 0;
				cout<<endl;
				DisplayResourceLBLSpecial_CreateDoc();
				break;
				
			
			//Type deledoc: delete documentation
			case deledoc:
			    deleteMenuRequest = Menu_DeleteCondition();
				system("CLS");
				
				if ((deleteMenuRequest == 'a') || (deleteMenuRequest == 'A'))
				{
				   if (isDelete == DeleteDocumentation()) 
			 	   {
					  cout<<"I'm ";
					  color_red();
					  cout<<"deleting ";
					  color_default();
					  cout<<"documentation.txt";
				
					  while (point_temp < 3)
					  {
						    Sleep(1000);
					  	    cout<<".";
					  	    point_temp++;
					  }
					
					  cout<<endl<<"File ";
					  color_green();
					  cout<<"successfully deleted"<<endl;
					  color_default();
					  point_temp = 0;
					  var_up = 0;
					  cout<<endl;
					  DisplayResourceLBLSpecial_DeleteDoc();
				    }
				    
				    else if (isDelete != DeleteDocumentation())
					{	
					  color_red();
					  cout<<"I can't delete documentation.txt";
				 	  break;
					  color_default();
					  cout<<endl;
				    }
				    
				    else
				    {
				    	color_yellow();
				    	cout<<"An error has occured!"<<endl;
				    	color_default();
						//getch();
				    }
				}
					
				else if ((deleteMenuRequest == 'b') || (deleteMenuRequest == 'B'))
				{
				   if (isDeleDoc == DeleteDocumentationD()) 
			 	   {
					  cout<<"I'm ";
					  color_red();
					  cout<<"deleting ";
					  color_default();
					  cout<<"documentation.doc";
				
					  while (point_temp < 3)
					  {
						    Sleep(1000);
					  	    cout<<".";
					  	    point_temp++;
					  }
					
					  cout<<endl<<"File ";
					  color_green();
					  cout<<"successfully deleted"<<endl;
					  color_default();
					  point_temp = 0;
					  var_up = 0;
					  cout<<endl;
					  DisplayResourceLBLSpecial_DeleteDoc();
				    }
				    
				    else if (isDelete != DeleteDocumentation())
					{	
					  color_red();
					  cout<<"I can't delete documentation.doc";
				 	  break;
					  color_default();
					  cout<<endl;
				    }
				    
				    else
				    {
				    	color_yellow();
				    	cout<<"An error has occured!"<<endl;
				    	color_default();
						//getch();
				    }
				}
				
				else if ((deleteMenuRequest == 'c') || (deleteMenuRequest == 'C'))
				{
				   if ((isDeleDoc == DeleteDocumentationD()) && (isDelete == DeleteDocumentation())) 
			 	   {
					  cout<<"I'm ";
					  color_red();
					  cout<<"deleting ";
					  color_default();
					  cout<<"documentation.txt ";
					  color_aqua();
					  cout<<"& ";
					  color_default();
					  cout<<"documentation.doc";
				
					  while (point_temp < 3)
					  {
						    Sleep(1000);
					  	    cout<<".";
					  	    point_temp++;
					  }
					
					  cout<<endl<<"Files ";
					  color_green();
					  cout<<"successfully deleted"<<endl;
					  color_default();
					  point_temp = 0;
					  var_up = 0;
					  cout<<endl;
					  DisplayResourceLBLSpecial_DeleteDoc();
				    }
				    
				    else if ((isDelete != DeleteDocumentation()) && (isDeleDoc == DeleteDocumentationD()))
					{	
					  cout<<"I ";
					  color_green();
					  cout<<"can ";
					  color_default();
					  cout<<"delete documentation.doc, but ";
					  color_red();
					  cout<<"I can't delete documentation.txt";
				 	  break;
					  color_default();
					  cout<<endl;
				    }
				    
				    else if ((isDeleDoc != DeleteDocumentationD()) && (isDelete == DeleteDocumentation()))
					{	
					  cout<<"I ";
					  color_green();
					  cout<<"can ";
					  color_default();
					  cout<<"delete documentation.txt, but ";
					  color_red();
					  cout<<"I can't delete documentation.doc";
				 	  break;
					  color_default();
					  cout<<endl;
				    }
				    
				    else
				    {
				    	color_yellow();
				    	cout<<"An error has occured!"<<endl;
				    	color_default();
						//getch();
				    }
				}
								
				else
				{
					cout<<"I got choice ";
					color_red();
					cout<<"wrong.";
					color_default();
				}
				
				cout<<endl;
				color_default();
				getch();
				break;
				
			
			//menu
			case ret_menu:
				break;

				
			//default case
			default:			
				break;
    }
}

#endif //CLASS_CL_BASDOC
