//Implementing Count Sort
#include<bits/stdc++.h>
using namespace std;
int main(){

    cout << "Enter number of items: ";
    int num,i;
    cin >> num;

   int arr[num];
   cout << "Enter the items: ";

   for(i=0;i<num;i++)
    cin >> arr[i];

    int max = arr[0];
    int min = arr[0];

    for(i=0;i<num;i++){
        if(max < arr[i])
            max = arr[i];

        if(min > arr[i])
         min = arr[i];
    }

    int* sums;
    int sumSize = max - min + 1;

    // creating an array with an index for each element between minimum and maximum items of given array
    sums = (int*) calloc(sumSize,sizeof(int));// using calloc so that memory allocation and initialization (to 0) happens in one go
    for(i=0;i<num;i++)
        sums[arr[i]-min]++; // storing count of each unique item in sums array at its index
    
    for(i=1;i<sumSize;i++){
        sums[i] = sums[i] + sums[i-1]; // Cumulating sums of all items   
    }

    int sorted[num]; // for sorted items

    for(i=0;i<num;i++){
        sorted[--sums[arr[i]-min]] = arr[i]; // checking values in sums array and inserting items in sorted array at appropriate indices
    }

    for(i=0;i<num;i++)
        cout << sorted[i] << " ";

    return 0;

}