// C++ program to implement binary search in sorted array
#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <time.h>
#include <math.h>
#include <cstring>

using namespace std;
#include <iostream>

int binarySearch(int arr[], int low, int high, int key)
{
	if (high < low)
		return -1;
	int mid = (low + high) / 2; /*low + (high - low)/2;*/
	if (key == arr[mid])
		return mid;
	if (key > arr[mid])
		return binarySearch(arr, (mid + 1), high, key);
	return binarySearch(arr, low, (mid - 1), key);
}

int insertSorted(int arr[], int n, int key, int capacity)
{

	// Cannot insert more elements if n is already
	// more than or equal to capacity
	if (n >= capacity)
		return n;

	int i;
	for (i = n - 1; (i >= 0 && arr[i] > key); i--)
		arr[i + 1] = arr[i];

	arr[i + 1] = key;

	return (n + 1);
}

/* Driver code */
int main(int argc,char **argv)
{
    srand(time(NULL));
    int index=atoi(argv[1]);
    int size=pow(2, index);
    double time=0; 

    int *arr=new int [size];
	int n = 1;
	int i, key ;
    clock_t start,end;
    
    arr[0]=rand();
    start=clock();
	for (i = 1; i < size; i++){
		key=rand();
	    n = insertSorted(arr, n, key, size);
    }
    end=clock();
    double insert=double(end-start)/CLOCKS_PER_SEC;                             
    cout<<insert <<endl;

    int r;
    start=clock();
    for (int j=0;j<100000;j++){
        key=rand();
        r=binarySearch(arr,0,size-1,key);
    }
    end=clock();
    double search=double(end-start)/CLOCKS_PER_SEC;
    cout<<search <<endl;
    
    
    char *filename= new char[20];                                                                                                                                                                            
    strcpy(filename, argv[2]);
    ofstream f;
    f.open("result.csv",ios_base::app);
    f << index << ",";
    f << size << ",";
    f << insert <<' ' <<search << endl;


    delete []arr;
	return 0;

}

// This code is contributed by SHUBHAMSINGH10

