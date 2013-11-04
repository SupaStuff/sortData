#include<iostream>
#include<fstream>
#include<cstring>
#include "sorts.h"
#include "menus.cpp"
#include "filemanage.cpp"

using namespace std;

int main()
{
    int x = 0;
    string myFile="default.txt";
    //create if it doesn't exist
    fstream dataFile((char*)myFile.c_str(), ios::out|ios::in);
    dataFile.close();//close it because it's only open for write
    dataFile.open((char*)myFile.c_str());//open it again, properly this time
    
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
