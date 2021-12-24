// CPP program to implement hashing with chaining
#include<bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

class Hash
{
    int BUCKET; // No. of buckets

    // Pointer to an array containing buckets
    list<int> *table;
    public:
    Hash(int V); // Constructor

    // inserts a key into hash table
    void insertItem(int x);
    // search a key in hash table
    void searchItem(int key);

    // hash function to map values to key
    int hashFunction(int x);
    
    // use in hash function
    int r[5]={0};

   
};

Hash::Hash(int b)
{
    this->BUCKET = b;
    table = new list<int>[BUCKET];
}

void Hash::insertItem(int key)
{
    int index = hashFunction(key);
    table[index].push_back(key);
}



void Hash::searchItem(int key)
{
    int index = hashFunction(key);

    list <int> :: iterator i;
    for (i = table[index].begin();
            i != table[index].end(); i++) {
        if (*i == key)
            break;
    }
}

int Hash:: hashFunction(int x){
    int arr[5]={0},temp=x;
    arr[1]= x%256;
    
    for (int i=2;i<5;i++){
        for(int j=i-1;j>0;j--){
            temp=temp/256;
        }

        arr[i]=temp%256;
        temp=x;
    }
    for(int i=1;i<5;i++){
        arr[i]=arr[i]*r[i];
    }        


    int result=0;
    for(int i=1;i<5;i++){
        result+=arr[i];
    }


    return result%BUCKET;

}


// find prime 
int  findPrime(int a,int b){
    int x,y;
    while(true)  
    {
 
        if(b>a&&b>=2) 
        {
            if (a<=2) 
            cout << "2" << " ";
            for(x=a;x<=b;x++) 
            {
                for(y=2;y<=x;y++) 
               {
                   if(x%y==0) 
                    break;  
                   else if (x==y+1)
                    return x;
                 }
            }
        }
    }
    system ("pause");
}


int main(int argc, char** argv)
{
    srand((unsigned)time(NULL));     
    int index=atoi(argv[1]);
    int size=pow(2,index);
    double time=0;
    int key=0;
    clock_t start,end;
    
    int M=findPrime(size/2,size);
    

    Hash h(M);
    h.r[1]=970027;
    h.r[2]=970031;
    h.r[3]=970043;
    h.r[4]=970051;
    
    // insert
    start=clock();
    for (int i=0;i<size;i++){
        key=rand();
        h.insertItem(key);
    }
    end=clock();

    double insert=double(end-start)/CLOCKS_PER_SEC;
    cout<< "insert: "<<insert<<" ";

    //search
    start=clock();
    for (int i=0;i<100000;i++){
        key=rand();
        h.searchItem(key);
    }
    end=clock();
    double search=double(end-start)/CLOCKS_PER_SEC;
    cout<< "search: "<<search<<endl;

    // 將insert 和search 寫進檔案
       char *filename=new char [20];

         strcpy(filename, argv[2]);
         ofstream f;
         f.open("result.csv",ios_base::app);
         f<< index<< ' '<<size << ' ';
         f<<insert<<' '<<search<<endl;
     


    return 0;
}

