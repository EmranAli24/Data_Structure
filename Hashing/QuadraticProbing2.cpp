// cpp implementation of
// the Quadratic Probing
#include<bits/stdc++.h>
using namespace std;

// Function to print an array
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
} 

int nextPowerOf2(int m){
    m--;
    
    /*

    This step ensures that if m is already a power of 2,
    it doesn't return the same value but rather finds the next power of 2.

    Example: If m = 8, m-- makes it 7,
    so it ensures that m is not mistakenly considered as a power of 2.
***********************************************************************
    Suppose m = 19 (binary: 10011)

    After m |= m >> 1, m becomes 11011

    After m |= m >> 2, m becomes 11111

    Further shifts keep m as 11111

    This effectively makes m look like 111...111
    (all bits set to 1 up to the most significant set bit).
*****************************************************************
    Adding 1 to m (which is now all 1s) results in a power of 2.

    Example: 11111 (31) + 1 = 100000 (32), which is the next power of 2.


    
    */
    m |= m >> 1;
    m |= m >> 2;
    m |= m >> 4;
    m |= m >> 8;
    m |= m >> 16;
  //  m |= m >> 32;
    m++;

    return m;
   

}

// Function to implement the
// Quadratic probing
void hashing(int table[],int tsize,int arr[],int n){

    for(int i=0;i<n;i++){

        // computing the hash value
        int hv = arr[i] % tsize ;

        // Insert in the table if there is no collision
        if(table[hv] == -1)
            table[hv] = arr[i];
        else{
            // if there is collision 
            // iterating through all
            // possible quadratic values
            int m = nextPowerOf2(tsize);

            for(int j=1;j<= m;j++){
                // computing the new hash value
                int t = (hv + (j + j*j)/2) % m ;
                if(table[t] == -1){
                    // Break the loop after
                    // inserting the value in the table
                    table[t] = arr[i];
                    break;
                }

                if(t >= tsize)
                    continue;
            }
        }
    }

    printArray(table,tsize);
}  

int main(){

    int arr[] = {21,10,32,43,54,65,87,76};
    int n = sizeof(arr) / sizeof(arr[0]);

    int tsize = 11;
    int hash_table[tsize];

    // initializing the hash table
    for(int i=0;i<tsize;i++){
        hash_table[i] = -1 ;
    }

    // Function call
    hashing(hash_table,tsize,arr,n);
    return 0;
}