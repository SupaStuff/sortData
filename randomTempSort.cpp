#include<iostream>
#include<fstream>
#include<ctime>
#include<cstring>

using namespace std;

#define t000 10000
//say T thousand


//Jean Peña

//function prototypes
void makeF(const char, int[]);
void fillArray(int[]);
void fillArray(int[], const char);
void mySort(int[]);
void bubbleSort(int[]);
int partitions(int[], int, int);
void quickSort(int[], int, int);
void quickSort(int[], int);
void quickSort(int[]);
void displayData(int[]);
void swap(int&, int&);
void testTime(void(), ofstream, string);
void testTime();

void makeF(const char *f, int a[])
{
    ofstream tempOut;
    tempOut.open(f); //creates or overwrites a file named f
    for(int x=0; x<t000; x++) tempOut<<a[x]<<endl; //fills the file with the contents of a[]
    tempOut.close();
}

void fillArray(int a[])
{
    srand(time(0));
    for(int x=0; x<t000; x++) a[x]=rand()%100+1; //fill an array with random numbers
}

void fillArray(int a[], const char *f)
{
     ifstream tempIn(f);
     if(tempIn.is_open()) while(tempIn.good()) for(int i=0; i<t000; i++) tempIn>>a[i]; //fill an array with stuff from file f
     else cout<<"hadouken"; //error message if it can't be opened
     tempIn.close();
}



void mySort(int a[]){for(int i=0; i<t000; i++)for(int h=i+1; h<t000; h++)if(a[h]<a[i])swap(a[h], a[i]);} //ridiculously slow sort

void bubbleSort(int a[])
{
     bool swapped = true;
     //this was 999, not t000, so it might be why it was a quicker sort than quicksort. probably doesn't finish sorting
     for(int i=t000-1; i>1 && swapped; i--) //loop as many times as the size of the array or stop when the array is sorted
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

void quickSort(int a[]){quickSort(a, 0, t000-1);} //used for passing this function.
void quickSort(int a[], int b){quickSort(a, 0, b-1);}

void displayData(int a[]){for(int i=0; i<t000; i++) cout<<a[i]<<endl;}//output each element in the array

void swap(int &a, int &b) //swaps the values of 2 ints. the passed ints are affected
{
     //
     int t = a;
     a=b;
     b=t;
}

void testTime(void(*funct)(int[]), ofstream &timeOut, string s) //pass a function, a file to write to, and a string
                                            //describing the function. tests the amount of time it takes to run sorting functions
{
    double tiem = 0.0, min = 9000.0, max = 0.0, temp; //some variables to hold stats
    int a[t000]; //create an array
    for(int i=0; i<t000; i++) //run t000 tests
    {
            //fillArray(a, "tempFile.txt");
            fillArray(a); //fill the array with randome numbers
            clock_t start; //honestly, I'm not sure what a clock_t is. It's just some data time in ctime to me
            start = clock(); //system time before the function is called
            funct(a); //call the function that was passed
            temp = (double)(clock() - start) / CLOCKS_PER_SEC; //subtract start from the system time after the function runs,
                                      //cast it to double, and divide by some constant that's in ctime.
                                      //temp=number seconds the function took to run
            cout<<s<<" "<<i<<endl; //output the string that describes the function with the current iteration
                                   //to see the progress.
            
            if(temp<min) min=temp; //store in min if the time was a record low
            if(temp>max) max=temp; //store in max if the time was a record high
            tiem+=temp; //add to tiem for average later
    }
    tiem/=t000; //divide by t000 to get the average
    timeOut<<fixed;
    timeOut.precision(6);
    timeOut<<s<<"\t|"<<tiem<<"\t|"<<min<<"\t|"<<max<<endl; //outputs a new row for the table in the file
}

void testTime() //this will run the t000 tests 10 times
{
    ofstream timeOut;
    timeOut.open("timelog.txt", ios::app); //create or open the file
    
    //table heading
    timeOut<<"function()\t|Average Time\t|Shortest\t|Longest\n=========================================================\n";
    for(int i=0; i<10; i++)//run tests 10 times
    {
        testTime(bubbleSort, timeOut, "bubbleSort()"); //test bubbleSort()
        //testTime(mySort, timeOut, "mySort()"); //not worth it
        testTime(quickSort, timeOut, "quickSort()"); //test quickSort()
        timeOut<<"---------------------------------------------------------"<<endl; //new row
        for(int j=0; j<50; j++)cout<<i; //supposed to show the current iteration for progress
                                        //but it zips by and gets lost because of the line limit
        cout<<endl;
    }
    timeOut<<endl<<endl;
    timeOut.flush(); //potentially a lot of data. might not be saved yet
    timeOut.close(); //close the file
}
/*
int main()
{
    int data[t000]; //array of size t000
        
    fillArray(data); //fill the array with random numbers
    makeF("tempFile.txt", data); //create a file with the contents of the data
    fillArray(data, "tempFile.txt"); //read from the file
    displayData(data); //display the data
    
    quickSort(data); //sort the data
    makeF("sortedData.txt", data); //create a new file with the sorted data
        
    cout<<endl<<endl;
    displayData(data); //display the sorted data
    
    testTime(); //run some tests
    
    system("pause");
    return 0;
}
*/
