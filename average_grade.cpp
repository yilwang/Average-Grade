/***********************************************************************
* Program:
*    Project Average Grades 
*   
* Summary: 
*    This is the program that prompts the file from the user. Then this 
*    program will average the grades from the file input by the user.
*    
************************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;
#include <fstream>

/**********************************************************************
 * This function displays the result.
 ***********************************************************************/
void display( int data[], int count)
{

  cout.setf(ios::fixed);
  cout.precision(1);
  
  float total = 0;
  
  for (int i = 0 ; i < count ; i++ )
  {
     total += data[i];
  }

  float average = total * 100 / (count * 40) ;
  cout << "The average grade on the midterm is " << average; 
  cout << "%" << endl;

}

/**********************************************************************
 * This function reads the file from the user.
 ***********************************************************************/
void readFile(char fileName[])
{ 
   int data[100];
   int count = 0;

  // open the file
  ifstream fin(fileName);
  
  // chekc for failure;
  if (fin.fail())
  {
    cout << "Unble to open or read file " << fileName << "." << endl;
    return;
  }
  else 
  {
    //read it
    while (fin >> data[count])
    {
      fin.ignore();
      count++;
      cout << data[count] << ' ';
    }  
    display(data, count);  
  }
  //close it
  fin.close();
}

/**********************************************************************
 * This function gets the file from the user.
 ***********************************************************************/
void getFile(char filename[])
{
   cout << "Please specify the file name: ";
   cin >> filename;
   cin.ignore();
  
}

/**********************************************************************
 * This is the function that tells the computer where to start.
 ***********************************************************************/
int main()
{
   char fileName[256];
   getFile(fileName);

   readFile(fileName);
  
   return 0;
}
