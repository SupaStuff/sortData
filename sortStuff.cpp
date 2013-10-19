#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

class fiostream: public fstream
{
      public:
             string filename;
             fiostream(string s):fstream((char*)s.c_str()){filename=s;};
             void open(string s)
             {
                  fstream:open((char*)s.c_str());
                  filename=s;
             }
             string getFileName(){return filename;};
};

int menu();
string createU(fiostream&);
void appU(fiostream&);
void printU(fiostream&);
void createS(string);
void printS(string);
int main()
{
    int x = 0;
    string myFile="default.txt";
    fiostream dataFile(myFile);
    while(x!=6)
    {
               myFile="sorted_"+myFile;
               dataFile.clear();
               x=menu();
               if(x==1) myFile = createU(dataFile);
    }
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
     
     //x
     int x;
     cin>>x;
     return x;
}


string createU(fiostream &fio)//create a new data file or open an existing one
{
       string f;
       fio.flush();
       fio.close(); //close the previously open file
       
       cout<<"name of the file: ";
       cin>>f;
       fio.open(f);
       return f;
}

void appU(fiostream &fio)
{
     int x;
     
     do
     {
         cin.clear();
         cin.ignore(INT_MAX, '\n');
         cout<<"Enter a new integer, please: ";
         cin>>x;
     }while(cin.fail());
     
     //set write position to the end of the file. like ios::app
     fio.seekp(0, fio.end);
     //*************************************************
     fio<<x<<endl;
}

void printU(fiostream &fio)
{
     int x = 0;
     //set the read position to the beginning of the file
     fio.seekg(0, fio.beg);
     while(!fio.eof())
     {
                      //***********************************
                      fio>>x;
                      cout<<x<<endl;
     }
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
