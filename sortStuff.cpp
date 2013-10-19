#include<iostream>
#include<fstream>
#include<cstring>
#include "sorts.h"

using namespace std;

int menu();
int safeInt();
string createU(fstream&);
void appU(fstream&);
void printU(istream&);
void createS(fstream&, string);
void printS(string);

int main()
{
    int x = 0;
    string myFile="default.txt";
    //create if it doesn't exist
    fstream dataFile((char*)myFile.c_str(), ios::out|ios::app);
    dataFile.close();//close it because it's only open for write
    dataFile.open((char*)myFile.c_str());//open it again, properly this time
    myFile="sorted_"+myFile;//keeps the sorted file's name in mind
    
    while(x!=6)
    {
               dataFile.clear();//clear the data file's flags
               
               //set the read position to the beginning of the file
               dataFile.seekg(0, dataFile.beg);
               
               x=menu();//bring up the menu and use the user's input for:

               //creates or opens a user defined file
               if(x==1) myFile = createU(dataFile);
               else if(x==2) appU(dataFile);//add integers to the file
               else if(x==3) printU(dataFile);//display file contents
               else if(x==4) createS(dataFile, myFile);//creates a sorted file
               else if(x==5) printS(myFile);//display sorted contents
    }
    
    //flush and close the data file
    dataFile.flush();
    dataFile.close();
    return 0;
}

int menu()
{
     cout<<"Data File Operations\n---------------------\n"
     "1. Create new data file or open an existing one\n"
     "2. Add a new integer value to unsorted data file\n"
     "3. Print the contents of the unsorted data file\n"
     "4. Create a sorted data file\n"
     "5. Print the contents of the sorted file\n"
     "6. Quit\n";
     int x=safeInt();
     return x;
}

int safeInt()//people like to enter nonsense
{
     int x;
     do
     {
         if(cin.fail())
         {
                       cin.clear();//clear cin's flags
                       cin.ignore(INT_MAX, '\n');//ignore any nonsense up to a new line
         }
         cout<<"user: ";
         cin>>x;
     }while(cin.fail());//if the user enters a non integer, ask again
     return x;
}

string createU(fstream &fio)//create a new data file or open an existing one
{
       string f;
       fio.flush();
       fio.close(); //close the previously open file
       
       cout<<"name of the file: ";
       cin>>f;
       fio.open((char*)f.c_str(), ios::out|ios::app);
       fio.close();
       fio.open((char*)f.c_str());
       return "sorted_"+f;
}

void appU(fstream &fio)
{
     //set write position to the end of the file. like ios::app
     fio.seekp(0, fio.end);
     
     cout<<"Enter an new integer\n";
     int x = safeInt();
     //wait for user's int and put it in the file
     fio<<x<<endl;
}

//read the next int and print it until the file is no good.
void printU(istream &fio){for(int x=0; fio>>x;) cout<<x<<endl;}

void createS(fstream &fio, string f)
{
     int x = 0, y;
     ofstream sorted((char*)f.c_str());//create a file to store the sorted data
     
     while(fio>>y)x++; //count how many numbers are in the data file
     
     //reposition the reading pointer to the beinning of the file
     fio.clear();
     fio.seekg(0, ios::beg);
     
     int a[x]; //create an array of the correct size
     for(int i=0; i<x; i++) fio>>a[i];//fill the array with data
     
     quickSort(a, x);//sort the array using quick sort(sorts.h)
     
     for(int i=0; i<x; i++)sorted<<a[i]<<endl;//save the sorted array to file
     
     //flush and close the sorted file
     sorted.flush();
     sorted.close();
}

void printS(string f)
{
     ifstream sorted((char*)f.c_str());//open the sorted file
     printU(sorted);//print it's contents
     sorted.close();//and close it
}
