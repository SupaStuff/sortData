//Jean Peña
//Patryck Piasecki
#include<iostream>
#include<fstream>
#include<cstring>
#include<ctime>

//delete
//statistics

using namespace std;

typedef void (*sortFunct) (int a[], int b);

/*
string createU(fstream&);
void appU(fstream&);
void removeU(fstream&);
void printU(istream&);
void createS(fstream&, string);
void printS(string);
*/

int menu();
int safeInt();
int sortExp();
int testRun();
int dataMan();
int typeMenu();
void worstCase(int[], int);
void bestCase(int[], int);
int randomCase();
void randomCase(int[], int);
int userCase();
void userCase(int[], int);

void dataManip();
void testRunit();
void makeData();
void addData();
void delData(); //no

void createF(int[], int, int);
void appF(int);
void delDat(int); //no
string fileName(int);
int lastInt(fstream&);

void bubbleSort(int[], int);
void selectionSort(int[], int);
int partitions(int[], int, int);
void quickSort(int[], int, int);
void quickSort(int[], int);
void swap(int&, int&);

void testTime();
void copyArray(int[], int[], int);

int main()
{
    int x = -1;
    while(x!=0)
    {
               x=sortExp();
               if(x==1) dataManip();
               else if(x==2) testRunit();
               else if(x==3) testTime();
    }
    return 0;
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


//4 menus, 4 functions. Self explanatory
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
     "3. Delete Data from File\n"
     "0. Go Back\n";
    
    //get an int from the user
     int x=safeInt();
     return x;
}
          
int testRun()
{
       
     cout<<"\nTest Run\n---------------------\n"
     "1. Bubble sort\n"
     "2. Quick sort\n"
     "3. Selection sort\n"
     "0. Go Back\n";

    //get an int from the user
     int x=safeInt();
     return x;
}

int typeMenu()
{
       
     cout<<"\nData File\n---------------------\n"
     "1. RandomData\n"
     "2. WorstCase\n"
     "3. BestCase\n" 
     "4. Saved File\n"
     "0. Go Back\n";

    //get an int from the user
     int x=safeInt();
     return x;
}

//Another "menu" for asking how many elements to generate... Or ask for.
int howMuch()
{
    cout<<"How many data items?\n";
    //get an int from the user
    int x=safeInt();
    return x;
}

//takes and array a of size b and creates each of these cases
void worstCase(int a[], int b){for(int i=0; i<b; i++) a[i] = b-i;}

void bestCase(int a[], int b){for(int i=0; i<b; i++) a[i] = i;}

void randomCase(int a[], int b)
{
     srand(time(NULL)); //clock seeds the rng
     for(int i=0; i<b; i++)a[i]=rand()%9002; //nmbers can be over 9000
}

void userCase(int a[], int b){for(int i=0; i<b; i++)a[i] = userCase();}
//not even recursion. Asks the user for ints to fill the file with
int userCase()
{
             cout<<"Enter an new integer\n";
             return safeInt();
}

//before this didn't work, it was used to fill the array. Now it's just used to get 1 random number
int randomCase()
{
     srand(time(NULL));
     return rand()%100;
}


//calls the Data Management menu and does stuff
void dataManip()
{
     int x=-1;
     while(x<0 || x>3)//force the user to enter a correct choice. 0 goes back
     {
               x = dataMan();
               if(x==1) makeData(); //creates new data files
               else if(x==2) addData(); //adds 1 new element to the data files
               else if(x==3) cout<<"Just a place holder\n";
               //else if(x==3) delData(); ///deletes a specified number from the data files
     }
}

//try out each of the sorts
void testRunit()
{
     int x=-1;
     while(x<0 || x>3)//force correct choice.
     {
               x = testRun(); //ask for sort to use
               if(x>=0 && x<=3)
               {
                       int y = -1;
                       while(y<0 || y>4) y = typeMenu(); //ask which file to sort
                       string f = fileName(y-1);
                       ifstream fio((char*)f.c_str()); //open the file
                       if(!fio.is_open()) cout<<"can't open the file\n"; //or not
                       else
                       {
                           f = "sorted."+f;
                           ofstream sorted((char*)f.c_str());//create a file to store the sorted data
     
                           int z=0;
                           while(fio>>y)z++; //count how many numbers are in the data file
     
                           //reposition the reading pointer to the beinning of the file
                           fio.clear();
                           fio.seekg(0, ios::beg);
     
                           int a[z]; //create an array of the correct size
                           for(int i=0; i<z; i++)
                           fio>>a[i];//fill the array with data
                       
                           //use the sort the user asked for
                           if(x==1) bubbleSort(a, z);
                           else if(x==2)quickSort(a, z);
                           else if(x==3)selectionSort(a, z);
                       
                           for(int i=0; i<z; i++)sorted<<a[i]<<endl;//save the sorted array to file
     
                           //flush and close the sorted file
                           sorted.flush();
                           sorted.close();
                      }
                      fio.close(); //close the data file
               }
     }
}

void makeData()
{
     int b = howMuch(); //ask the user how many elements they want in the file
     int a[b]; //create an appropriate array
     int x=-1;
     while(x<0 || x>4) //force correct choice
     {
               x = typeMenu(); //ask what kind of data file the user wants
               //populate the array accordingly
               if(x==1) randomCase(a, b);
               else if(x==2) worstCase(a, b);
               else if(x==3) bestCase(a, b);
               else if(x==4) userCase(a, b);
               else continue; //skip the rest if not a valid choice or "Go Back"
               
               //create the appropriate file
               createF(a, b, x);
     }
}

void addData()
{
     int x=-1;
     while(x!=0)
     {
               x=typeMenu(); //ask what file to add data too
               appF(x); //add data to it
     }
}

void delData()
{
     int x=-1;
     while(x!=0)
     {
               x=typeMenu(); //ask what file to add data too
               appF(x); //add data to it
     }
}

int lastInt(fstream &fio) //returns the last int in a file
{
    char ch='\0';
    fio.seekg(-3, ios_base::cur); //um. idk. going back less positions doesn't work
    while(ch!='\n')//read until the 2nd to last line feed.
    {
             fio.get(ch);
             if((int)fio.tellg()<=1) ch = '\n';
             else fio.seekg(-3, ios_base::cur);
    }
    int x=0;
    fio>>x; //get the int after the line feed
    //clear any wierd flags and go to the end of the file
    fio.clear();
    fio.seekp(0, fio.end);
    return x;
}

string fileName(int x)
{
     //an array of names
     string fName[4] = {"random.txt","worst.txt","best.txt","default.txt"};
     //x is the choice from the menufor data files -1
     if(x==3)//if user defined file is selected, let the user define it.
     {
       cout<<"\nName of the file(leave blank for default.txt): ";
       getline(cin, fName[3]);
       if (fName[3].length()==0) fName[3]="default.txt";
     }
     return fName[x]; //return the file name
}

//store the contents of the array a into a file defined by the choice (x)
void createF(int a[], int b, int x)
{
     string f = "";
     if(x>4)
     {
            f="stat.";
            x-=4;
     }
     //get the correct name of the file to create
     f += fileName(x-1);

     ofstream fio((char*)f.c_str());//create a file to store the data
     for(int i=0; i<b; i++) fio<<a[i]<<endl;//save the array to file
     //flush and close the file
     fio.flush();
     fio.close();
}

//add a new element to the file defined by the choice (x)
void appF(int x)
{
     //get the file name
     string f = fileName(x-1);
     
     if(x>=1 && x<=4)
     {
             fstream fio((char*)f.c_str(), ios::out|ios::in);//open a file to store the data
             fio.seekg(0,fio.end); //got to the end of the file
             int y = lastInt(fio); //get the last int
             
             if(x==1) fio<<randomCase(); //if random, put a random
             else if(x==2)fio<<y-1<<endl; //if worst, put 1 less than the last
             else if(x==3)fio<<y+1<<endl; //if best, put 1 more than the last
             else if(x==4) fio<<userCase(); //if user defined, let them enter it
             
             //flush and close the file
             fio.flush();
             fio.close();
     }
}


void bubbleSort(int a[], int b)
{
     bool swapped = true;
     //this was 999, not t000, so it might be why it was a quicker sort than quicksort. probably doesn't finish sorting
     for(int i=b-1; i>1 && swapped; i--) //loop as many times as the size of the array or stop when the array is sorted
     {
             swapped=false; //will be false if it goes through this next loop without swapping 2 numbers
             for(int h=1; h<=i; h++) //go through each element starting with the second one
             {
                     if(a[h]<a[h-1]) //if this element is less than the element before it
                     {
                                  swapped = true; //will have to run through this loop again
                                  swap(a[h], a[h-1]); //swap the 2 elements
                     }
             }
     }
}

void selectionSort(int a[], int b) 
{	
    int tmp, min;
	for (int i = 0; i < b-1; i++)
    {
        min=i;
		for (int j = i+1; j < b; j++) if (a[j] < a[min]) min=j;
		
        tmp = a[i];
		a[i] = a[min];
		a[min] = tmp;
    }
}

int partitions(int a[], int p, int r)
{
   int i = p-1;
   //srand(time(0));
   //swap(a[rand()%((r-p)-2)+p+1], a[r-1]);
   for(int j=p; j<r; j++)
   {
           if(a[j] <= a[r])
           {
                   i++;
                   swap(a[i], a[j]);
           }
   }
   swap(a[i+1], a[r]);
   return i+1;
}

void quickSort(int a[], int p, int r)//p=first element, r=last element
{
     if(p<r) //if the first element is not the only element
     {
            int q = partitions(a, p, r); //choose a position to split at with the stuff before being somewhat sorted
            //recursive calls
            quickSort(a, p, q-1); //sort from the starting element to the split position
            quickSort(a, q+1, r); //sort from the split position to the ending element
     }
}

void quickSort(int a[], int b){quickSort(a, 0, b-1);}

void swap(int &a, int &b) //swaps the values of 2 ints. the passed ints are affected
{
     //
     int t = a;
     a=b;
     b=t;
}


void testTime() //this will run the t000 tests 10 times
{
     int t000 = 10000;
     int functs = 3;
     sortFunct functions[] = {bubbleSort, quickSort, selectionSort};
     sortFunct cases[3] = {randomCase, worstCase, bestCase};
     
     string functionss[] = {"bubbleSort", "quickSort", "selectionSort"};
     string casess[3] = {"randomCase", "worstCase", "bestCase"};
     
     int a[t000], b[t000];
     
     ofstream timeOut("timelog.txt", ios::app); //create or open the file
    
     //table heading
     timeOut<<"function()\t|";
     for(int i=0; i<functs; i++) timeOut<<functionss[i]<<"\t|";
     timeOut<<"# of elements: "<<t000<<"\n=========================================================\n";
     timeOut<<fixed;
     timeOut.precision(6);
     for(int i=0; i<3; i++)
     {
             timeOut<<casess[i]<<"\t|";
             for(int j=0; j<functs; j++)
             {
                     cases[i](a, t000);
                     copyArray(a, b, t000);
                     clock_t start; //honestly, I'm not sure what a clock_t is. It's just some data time in ctime to me
                     start = clock(); //system time before the function is called
                     functions[j](b, t000); //call the function that was passed
                     double tiem = (double)(clock() - start) / CLOCKS_PER_SEC; //subtract start from the system time after the function runs,
                                      //cast it to double, and divide by some constant that's in ctime.
                                      //temp=number seconds the function took to run
                     timeOut<<tiem<<"\t|";
             }
             timeOut<<endl; //outputs a new row for the table in the file
             createF(b, t000, i+5);
     }
     timeOut<<"---------------------------------------------------------"<<endl; //new row
     timeOut<<endl<<endl;
     timeOut.flush(); //potentially a lot of data. might not be saved yet
     timeOut.close(); //close the file
     
     ifstream timeIn("timelog.txt");
     char ch;

     while(!timeIn.eof())
     {
      timeIn.get (ch);
      cout<<ch;
      }
      timeIn.close();
      }

void copyArray(int a[], int b[], int c){for(int i=0; i<c; i++) b[i] = a[i];}


void delDat(int x)
{
     //get the file name
     string f = fileName(x-1);
     
     if(x>=1 && x<=4)
     {
             int search;
             cout<<"what number? ";
             cin>>search;
             
             fstream fio((char*)f.c_str(), ios::out|ios::in);//open a file to store the data
             
             fio.flush();
             fio.close();
     }
}
/*
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

*/
