#include<iostream>
#include<ctime>
using namespace std;

int menu();
int safeInt();
int sortExp();
int testRun();
int dataMan();
int typeMenu();
void worstCase(int[], int);
void bestCase(int[], int);
void randomCase(int[], int);
/*
int menu()
{
     cout<<"Data File Operations\n---------------------\n"
     "1. Create new data file or open an existing one\n"
     "2. Add a new integer value to unsorted data file\n"
     "3. Print the contents of the unsorted data file\n"
     "4. Create a sorted data file\n"
     "5. Print the contents of the sorted file\n"
     "6. Quit\n"
     "7. new\n";
     
     //get an int from the user
     int x=safeInt();
     return x;
}
*/
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

int sortExp()
{
     cout<<"\nSorting Experiments\n---------------------\n"
     "1. Data Managment\n"
     "2. Test Run\n"
     "3. Statistics\n"
     "0. Quit\n";
     
    //get an int from the user
     int x=safeInt();
     return x;
}
     

int dataMan()
{
     cout<<"\nData Managment\n---------------------\n"
     "1. Create New Data File\n"
     "2. Add Data to file\n"
     "3. Delete Data from File\n";
    
    //get an int from the user
     int x=safeInt();
     return x;
}
          
int testRun()
{
       
     cout<<"\nTest Run\n---------------------\n"
     "1. Bubble sort\n"
     "2. Quick sort\n"
     "3. Selection sort\n" ;

    //get an int from the user
     int x=safeInt();
     return x;
}

int typeMenu()
{
       
     cout<<"\nData File\n---------------------\n"
     "1. RandomData\n"
     "2. WorstCase\n"
     "3. BestCase\n" ;
     "4. Saved File\n" ;

    //get an int from the user
     int x=safeInt();
     return x;
}

int howMuch()
{
    cout<<"How many data items?\n";
    //get an int from the user
    int x=safeInt();
    return x;
}

void worstCase(int a[], int b){for(int i=0; i<b; i++) a[i] = b-i;}

void bestCase(int a[], int b){for(int i=0; i<b; i++) a[i] = i;}

void randomCase(int a[], int b)
{
     srand(time(0));
     for(int i=0; i<b; i++) a[i]=rand()%9001;
}
