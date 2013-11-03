#include<iostream>
using namespace std;

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




#include<iostream>

using namespace std;

int menu()
{
    
    int a,b,c,d;
 cout<<"Sorting Experiments\n---------------------\n"
     "1. Data Managment\n"
     "2. Test Run\n"
     "3. Statistics\n"
     "4. Quit\n";
     
    
     cin>>a;
     
     

       if(a ==1){ 
        cout<<"Data Managment\n---------------------\n"
     "1. Create New Data File\n"
     "2. Add Data to file\n"
     "3. Delete Data from File\n";
     cin>>b;
     }
     
     
        if(a ==2){
       
       cout<<"Test Run\n---------------------\n"
     "1. Bubble sort\n"
     "2. Quick sort\n"
     "3. Selection sort\n" ;
      cin>>c;
     
     }
     
       if (a ==3){
  
        cout<<"Statisticsn\n---------------------\n"
      
        
    
       
       }
      
      else if(a ==4){
    cout << "you quit ";

} 
    
system("pause");
return 0;
}

