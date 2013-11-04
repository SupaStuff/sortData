#include<iostream>
#include<fstream>
#include<cstring>
#include "menus.cpp"

string createU(fstream&);
void appU(fstream&);
void removeU(fstream&);
void printU(istream&);
void createS(fstream&, string);
void printS(string);
void createF(int[], int, int);
void appF(int);
string nameChange();
int lastInt(fstream&);

string nameChange()
{
       string s;
       cout<<"\nName of the file(leave blank for default.txt): ";
       getline(s, cin);
       if (s.length()==0) s="default.txt";
       return s;
}

int lastInt(fstream &fio)
{
    char ch='\0';
    fio.seekg(-1, ios_base::eof);
    while((int)fio.tellg()>=1 && ch != '\n')
    {
                              fio.get(ch);
                              if(ch!='\n') fio.seekg(-2,ios_base::cur);
    }
    int x;
    fio>>x;
    fio.clear();
    fio.seekp(0, fio.end);
    return x;
}

void createF(int a[], int b, int x)
{
     x--;
     string fName[4] = {"random.txt","worst.txt","best.txt","default.txt"};
     
     if(x==3)fName[x] = nameChange();

     ofstream fio((char*)fName[x].c_str());//create a file to store the data
     for(int i=0; i<b; i++) fio<<a[i]<<endl;//save the array to file
     fio.flush();
     fio.close();
}

void appF(int x)
{
     x--;
     string fName[4] = {"random.txt","worst.txt","best.txt","default.txt"};
     
     if(x==3)fName[x] = nameChange();
     
     fstream fio((char*)fName[x].c_str(), ios::out|ios::in);//open a file to store the data
     int y = lastInt(fio);
     x++;
     
     if(x==1) fio<<randomCase();
     else if(x==2)fio<<y-1<<endl;
     else if(x==3)fio<<y+1<<endl;
     else if(x==4) fio<<userCase();
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
