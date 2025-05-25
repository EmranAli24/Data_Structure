// Cpp implementation of the
// quadratic probing 
#include<bits/stdc++.h>
using namespace std;

// function to print an array 
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

// Function to implement the 
//quadratic probing
void hashing(int table[],int tsize,int arr[],int n){
    for(int i=0;i<n;i++){

        // computing the hash value
        int hv = arr[i] % tsize;

        // insert in the table
        //if there is no collision
        if(table[hv] == -1){
            table[hv] = arr[i];
        }
        else{
            // if there is a collision
            // iterating through all
            // possible quadratic values
            for(int j=1;j<=tsize;j++){

                // computing the new hash value
                int t = (hv + j*j) % tsize;
                if(table[t] == -1){
                    // Break the loop
                    // after inserting the value 
                    // in the table
                    table[t] = arr[i];
                    break;
                }
            }
        }
    }
    printArray(table,tsize);
} 

int main(){
    int arr[] = {50,700,76,85,92,73,101};
    int n = sizeof(arr) / sizeof(arr[0]);

    // size of the hash table
    int tsize = 11;
    int hash_table[tsize];

    // initializing the hash table
    for(int i=0;i<tsize;i++){
        hash_table[i]=-1;
    }

    // Function call
    hashing(hash_table,tsize,arr,n);
    return 0;
}

/*
The above implementation of quadratic probing 
does not guarantee that we will always be able to use
a hast table empty slot. It might happen that some entries
do not get a slot even if there is a slot available. 
For example consider the input array {21, 10, 32, 43, 54, 65, 87, 76} 
and table size 11, we get the output as {10, -1, 65, 32, 54, -1, -1, -1, 43, -1, 21} 
which means the items 87 and 76 never get a slot. 
To make sure that elements get filled, we need to have a higher table size.


Iterate over the hash table to next power of 2 of table size. 
For example if table size is 11, then iterate 16 times. 
And iterate over the hash table using the below formula

hash(x) = [hash(x) + (j + j*j)/2] % (Next power of 2 of table size)

*/