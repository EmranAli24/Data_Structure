
#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[],int size){
 for(int i=0;i<size;i++){
    cout << arr[i] << " ";
 }
 cout << endl;
}

// Merge two subarrays L and M into arr
void merge(int arr[],int p,int q,int r){
    // create L <- A[p...q] and M <- A[q+1...r]

    int n1= q-p+1;
    int n2 = r-q;

    int L[n1],M[n2];

    for(int i=0;i<n1;i++)
        L[i] = arr[p+i];
    for(int j=0;j<n2;j++){
        M[j] = arr[q+1+j];
    }


    // Maintain current index of sub-arrays and main array
int i,j,k;
i=0;
j=0;
k=p;

// Untill we reach either end of L or M, pick larger among 
// elements L and M and place them in the correct position

while (i<n1 && j <n2)
{
    if(L[i] <= M[j]){
        arr[k++] = L[i++];
    }
    else{
        arr[k++] = M[j++];
    }
}

// when we run out of elements in either L or M,pick up
// the remaining elements and put into the arr[]

while(i < n1){
    arr[k++] = L[i++];
}

while(j < n2){
    arr[k++] = M[j++];
}

    
}

// Divide the array into two subarrays, sort them and merge them
void MergeSort(int arr[],int l,int r){

    if(l<r){
        // m is the point where the array is divided into two subarrays   
        int m = l + (r-l)/2;

        MergeSort(arr,l,m);
        MergeSort(arr,m+1,r);

        // Merge the sorted subarrays
        merge(arr,l,m,r);
    }

}

int main(){

    int size;
    cout << "Array size: " << endl;
    cin >> size;

    int arr[size];

    cout << "Enter Array elements: " << endl;
    for(int i=0;i<size;i++){
        cin >> arr[i];
    }

    MergeSort(arr,0,size-1);

    cout << "Sorted array: \n";
    printArray(arr,size);
    return 0;
}
