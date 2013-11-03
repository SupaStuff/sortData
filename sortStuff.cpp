#include<iostream>
#include<fstream>
#include<cstring>
#include "sorts.h"
#include "menus.cpp"

using namespace std;

int menu();
int safeInt();
string createU(fstream&);
void appU(fstream&);
void removeU(fstream&);
void printU(istream&);
void createS(fstream&, string);
void printS(string);

int main()
{
    int x = 0;
    string myFile="default.txt";
    //create if it doesn't exist
    fstream dataFile((char*)myFile.c_str(), ios::out|ios::in);
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
               else if(x==7) removeU(dataFile);
    }
    
    //flush and close the data file
    dataFile.flush();
    dataFile.close();
    return 0;
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

void removeU(fstream &fio)
{
     //set write position to the end of the file. like ios::app
     
     //cout<<"Enter an integer to delete\n";
     //int x = safeInt();
     //wait for user's int and put it in the file
     string s = "";
     while(!fio.eof())
     {
             getline(fio, s);
             int size = s.length();
             char num[size];
             fio.read(num, size);
             cout<<s<<endl;
             if(atoi(s.c_str()) == 53)
             {
                                fio.write("15\n", 3);
                                fio.flush();
                                fio.close();
             }
     }
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
