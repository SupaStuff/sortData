#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

int menu();
string createU();
void appU(string);
void printU(string);
void createS(string);
void printS(string);
int main()
{
    int x = 0;
    string myFile="default.txt";
    while(x!=6)
    {
               x=menu();
               if(x==1) myFile = createU();
    }
    return 0;
}

int menu()
{
     cout<<"Data File Operations\n---------------------\n"
     "1. Create new data file\n"
     "2. Add a new integer value to unsorted data file\n"
     "3. Print the contents of the unsorted data file\n"
     "4. Create a sorted data file\n"
     "5. Print the contents of the sorted file\n"
     "6. Quit\n";
     
     //x
     int x;
     cin>>x;
     return x;
}


string createU()
{
       string f;
       cout<<"name of the file: ";
       cin>>f;
       ofstream fio((char*)f.c_str());
       fio.close();
       return f;
}

void appU(string f)
{
     int x;
     ofstream fio((char*)f.c_str(), ios::app);
     cout<<"new int: ";
     cin>>x;
     fio<<x<<endl;
     fio.flush();
     fio.close();
}

void printU(string f)
{
     int x = 0;
     ifstream fio((char*)f.c_str());
     while(!fio.eof())
     {
                      fio>>x;
                      cout<<x<<endl;
     }
     fio.close();
}

void createS(string f)
{
     int x = 0;
     string temp;
     ifstream fio((char*)f.c_str());
     while(!fio.eof())
     {
                      getline(fio, temp);
                      x++;
     }
     fio.clear();
     fio.seekg(0, ios::beg);
     int a[x];
     for(int i=0; i<x; i++)
     {
              fio>>a[i];
              cout<<a[i]<<endl;
     }
}

void printS(string f)
{
     f="sorted_"+f;
     int x = 0;
     ifstream fio((char*)f.c_str());
     while(!fio.eof())
     {
                      fio>>x;
                      cout<<x<<endl;
     }
     fio.close();
}
