#ifndef SORTS_H
#define SORTS_H

#include<iostream>
#include<fstream>
#include<ctime>
#include<cstring>

using namespace std;

void mySort(int[], int);
void bubbleSort(int[], int);
int partitions(int[], int, int);
void quickSort(int[], int, int);
void quickSort(int[], int);
void swap(int&, int&);


void mySort(int a[], int b){for(int i=0; i<b; i++)for(int h=i+1; h<b; h++)if(a[h]<a[i])swap(a[h], a[i]);} //ridiculously slow sort

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




void deleteNumber (void)
{
ifstream NumberDelete ("numbers.txt");
    ofstream temp ("temp.txt");
    string del, line, deleted;
    bool flag = false;
    
    cout << "Which number you want to delete?? ";
    getline (cin, del);
    
    if (NumberDelete.is_open())
    {
    while (getline(NumberDelete,line))
    {
        if (line != del) 
        temp << line << "\n";
        
        else 
{
flag = true;
deleted = line;
}
    }
    
    if (flag) cout << "\nNumber \"" << deleted << "\" found and deleted.";
        else cout << "\nNumber not found.";
}
    else cout << "\nUnable to open file.";
    
    NumberDelete.close();
    temp.close();
    
    remove("numbers.txt");
    rename("temp.txt","numberstxt");
}





void SelectionSort(int a[]) 
	int tmp;
	for( int i = 0; i < 5; i++)
		
		cout << data[i] << " "; 

	

	for (int i = 0; i < 5 -1; i++)

		for (int j = i+1; j < 5; j++)

			if (data[i] > data[j])
			{
				tmp = data[i];
				data[i] = data[j];
				data[j] = tmp;


#endif
