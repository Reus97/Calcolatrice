/* Software Engineer (c)
"MORE THAN A CALCULATOR.cpp" by Assistiti Matteo, Infanti Enrico

The following software is structed to support a New Calculator
Software (c) based on the classics calculators that we use
every day.
That calculator, only in this version, start with the
basic instructions in a simple prompt program.
The following program can make also other operand, if the clients will ask for them
the programmer will make it.
It creates some .txt Files that have some differents things that
will be explained in the fix part.
It has a main.cpp that used the simple function of a Menu() and some
personal Libraries, that offer some math types of calculations.
It has comment on the most difficult instructions to explain how they work,
if the clients want more they have only to ask to me.
//Modifica Sorgente

// ===================================== HISTORY ===================================== //
FIX v1.0 ->    The program was designed on Christmas Day, it has only the basic operation
               instructions.
FIX v1.0.1 ->  The program has identated, commented and it has some basic variables
               to resolve the crash problems.
FIX v1.1 ->    The program resolves the sqrt, pow and int result of division instruction.
FIX v2.0 ->    The program can create a result.txt myFile that contains the results of all
               operations, it lets you also see the type of instruction and the result of
               the same.
FIX v2.1 ->    The program lets you choose a new option, if you want you can delete all
               contenues inside the result.txt myFile, it could be choose in the menu.
FIX v2.2 ->    The program resolves the log, sen and cos instructions.
FIX v3.0 ->    The program creates another .txt myFile that contains the number of exit_time
               that the user has made with DD/MM/YYYY and H/MM/SS type. (backup.txt)
               That function is made in a new class library.
FIX v3.1 ->    In the backup.txt myFile the program saves also the last clear of result.txt and
               writes the last operation that user has made.
FIX v3.2 ->    This upgrade saves inside backup.txt if the user choose to delete the
               informations inside backup.
FIX 4.0 ->     User, for now, can only save (with a hide creation) a documentation of this software.
FIX 5.0 ->     The program have now tho differents Menu();
               The first one makes the classic operation and special operation like log, exp...
               with a return of int values also put in result.txt file.
               The second one makes special function, such as the creation of the documentation
               and the remove of the same, but can also clear the result.txt file, clear and
               create the backup of result.txt with exit time of the program, return to primary
               menu and quit from the program.
               It introduces the new struct called "enum" and a menu with enum string call.
FIX 5.0.1 ->   Bug fixed: the program compile in wrong way from first to second menu when you
               click 'x', this problem is solved with creation of a new enum variable that
               incapsulate all negative form of prequel conditions.
               (not savedoc, not deledoc, not clear_r, not backup_t, not ret_menu, not quit
FIX 6.0 ->     The program now has a new class called graphic.h where software generates a
               graphic interface creates in "ASCI Art".
FIX 6.0.1 ->   Bug Fixed: the program will not have problem (no more9 to delete documentation.txt
FIX 6.1 ->     The program has another hide class called font_doc.h where is all "cout<<inFile" code
               about documentation, it has also the possibility of creation .txt and .doc of the
               same documentation.
FIX 6.1.1 ->   User can choose if he wants only .txt documentation, only .doc documentation or both of
               them.
FIX 6.1.1.1 -> Bug fixed: remove the bug at CL_BasDoc self-made library, now it writes the correct cout
               in result.txt file.
FIX 7.0 ->     Adding of MessageBox Label Construct, they will appear to user on quit condition,
               on the create and the delete of documentation (.doc / .txt), both for BasicMenu and 
               SpecialMenu.
*/


/****************************************************************************************/
/****************************** LIBRARY INCAPSULATION ***********************************/
/****************************************************************************************/
#include <iostream>	                            //Used for input/output
#include <math.h>	                            //Used for math operations
#include <windows.h>	                            //Used for sleep functions
#include "graphic.h"	                            //Self-made Class used to make graphic effects
#include "color.h"                                        //Self-made Class used to change cout color
#include "CL_BasInstruction.h"	             //Self-made Class used to resolve operations and write on result.txt
#include "CL_BasTimeClock.h"	                            //Self-made Class used to write time in backup.txt
#include "CL_BasDoc.h"	                            //Self-made Class used to write documentation in documentation.txt
#include <stdio.h>                                        //Used for old C - CLASSIC instructions
#include <conio.h>	                            //Used for old C - CLASSIC instructions
#include <fstream>	                            //Used to manage the myFile (result.txt / backup.txt)
#include <string.h>	                            //Used to manage strings
using namespace std;


/****************************************************************************************/
/******************************* FUNCTION PROTOTYPES ************************************/
/****************************************************************************************/
char Menu_Basic();
void DisplayRecurceLBLBasic_Quit();


/****************************************************************************************/
/******************************** FUNCTION EXPLAIN **************************************/
/****************************************************************************************/
char Menu_Basic(CL_BasInstruction calculator)
{
    char scelta_basic;
    system("CLS");
    system("TITLE BASIC CALCULATOR");
    cout<<"s Setta | r Radice "<<endl;
    cout<<"+ Somma tra n numeri | e Elevamento a Potenza "<<endl;
    cout<<"- Differenza tra n numeri | i Divisione (int) "<<endl;
    cout<<"* Moltiplicazione tra n numeri | l Logaritmo (base 2) "<<endl;
    cout<<"/ Divisione (float) | g Gradi radianti (sen / cos) "<<endl;
    cout<<" |"<<endl;
    cout<<"=========================================|"<<endl;
    cout<<"x Se vuoi aprire la pagina per le |"<<endl;
    cout<<" funzioni soeciali |"<<endl;
    cout<<"=========================================|"<<endl;
    cout<<"q Esci (senza backup) |"<<endl;
    cout<<"=========================================|"<<endl;
    cout<<endl<<endl<<calculator.GetStatus();

    scelta_basic = getch();
    cout<<endl<<scelta_basic<<endl;
    return scelta_basic;
}

    void DisplayRecurceLBLBasic_Quit()
    {
               MessageBox(NULL,"     Thanks To Support This Sofrware.","GOODBYE USER",MB_ICONASTERISK | MB_OK | MB_DEFBUTTON2);    
    }


/****************************************************************************************/
/*********************************** MAIN EXPLAIN ***************************************/
/****************************************************************************************/
// Initialization of basic and complex instruction to resolve maths operands.
// At the end of program the complile Borland DEV C++ will create a .txt myFile called
// 'resolve.txt' that will contain the result of operand that client has chosen and
// the type of operand of the same.
// It could creates another myFile called backup.txt that is the result of a special
// exit, only if the client clicks 'b', else if it clicks 'q' it exit in regular mode.

int main()
{
    char answer_clr;
    char temp_sen_or_cos;
    
    int var_up = 0;
    int var_cl = 0;
    int point_temp = 0;
    int point_cl = 0;
    
    CL_BasTimeClock timeClock;
    CL_BasInstruction calculator;
    CL_BasDoc DocFXVersion;
    
    fstream myFile;
    fstream myClock;
    
    float temp = 0;
    
    bool isDelete = true;
    //myFile APPEND -> myFile.open ("result.txt", fstream::app);
    //myClock APPEND -> myClock.open("backup.txt", fstream::app);
    //myFile TRUNC -> myFile.open ("result.txt", fstream::trunc);
    //myClock TRUNC -> myClock.open("backup.txt", fstream::trunc);
    
    print_graphic_calculator();
    print_graphic_ready();
    
    color_default();
    
while (true)
{
    char menu = Menu_Basic(calculator);
    //exit on quit 'q'
    if (menu == 'q')
    {
        myFile.open("result.txt", fstream::out | fstream::app);
        system("CLS");
        cout<<"Exit ";
        color_green();
        cout<<"success!"<<endl;
        color_default();
        myFile<<"You are exit. (Basic Menu)"<<endl;
        myFile<<"************************************************"<<endl<<endl;
        myFile.close();
        timeClock.currentDateToString_exit();
        DisplayResurcesLBLBasic_Quit();
        break;
    }
    
    switch (menu)
    {
        //Type S: Set to n number
        case 's':
        cin>> temp;
        calculator.SetStatus(temp);
        break;
        
        
        //Type +: Set an add situation
        case '+':
        cin>> temp;
        calculator.Somma(temp);
        break;


        //Type -: Set a minus situation
        case '-':
        cin>> temp;
        calculator.Differenza(temp);
        break;
        
        
        //Type *: Set a moltiplication situation
        case '*':
        cin>> temp;
        calculator.Moltiplicazione(temp);
        break;


        //Type /: Set a division with float result
        case '/':
        cin>> temp;
        //validation of temp
        
        if (temp == 0)
        {
          cout<<"You can't ";
          color_red();
          cout<<"divide 0."<<endl;
          color_default();
          getch();
          break;
        }
        
      calculator.Divisione(temp);
      break;
      
      
      //Type R: Set a square operation
      case 'r':
      //validation of temp
      
      if (temp < 0)
      {
          cout<<"You can't make a ";
          color_red(),
          cout<<"negative sqrt. ";
          color_default();
          cout<<"Re-insert value."<<endl;
          getch();
          break;
      }
      
      calculator.Radice();
      getch();
      Sleep(500);
      break;
      
      
      //Type E: Set a power elevation
      case 'e':
      cin>> temp;
      //validation of temp

      if (temp < 0)
      {
          cout<<"You can't make a ";
          color_red();
          cout<<"negative power elevation."<<endl;
          color_default();
          getch();
          break;
      }
      
      calculator.Elevamento(temp);
      break;
      
      
      //Type I: Set a division with int result
      case 'i':
      cin>> temp;
      //validation of temp
      
      if (temp == 0)
      {
          cout<<"You can't";
          color_red();
          cout<<" divide 0."<<endl;
          color_default();
          getch();
          break;
      }
      
      calculator.DividiInt(temp);
      break;
      
      
      //Type L: Set a base2 log
      case 'l':
      if (temp < 0)
      {
        cout<<"You can't make a ";
        color_red();
        cout<<"negative log."<<endl;
        color_default();
        getch();
        break;
      }
      
      calculator.Logaritmo();
      getch();
      Sleep(500);
      break;
      
      
      //Type G: Set a sen or cos condition
      case 'g':
      cout<<endl;
      cout<<"\tDo you want sen or cos?"<<endl;
      cout<<"\t-> ";
      cout<<"\t ";
      cin>> temp_sen_or_cos;
      
      if (temp_sen_or_cos == 's')
      {
          calculator.SenoGrad();
      }
      
      else if (temp_sen_or_cos == 'c')
      {
          calculator.CosenoGrad();
      }

      else
      {
          color_yellow();
          cout<<"\tYou've choosen a wrong chance'..."<<endl;
          Sleep(1000);
          color_default();
          break;
      }
      break;
      
      
      //Type x: Go to Special Menu
      case 'x':
      system("CLS");
      DocFXVersion.Call();
      //getch();
      break;
      
      
      //default case
      default:
      color_yellow();
      cout<<endl<<"You've choosen a wrong chance (default)'..."<<endl;
      myFile.open("result.txt", fstream::out | fstream::app);
      myFile<<"If you see that, you have made a mistake..."<<endl;
      myFile<<"...and your PC will be destroyed in 1 minute (BYE)"<<endl<<endl;
      myFile.close();
      getch();
      color_default();
      break;
    }
  }
//return EXIT_SUCCESS;
system("PAUSE");
}
