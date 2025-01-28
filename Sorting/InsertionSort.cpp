/************************************************************** 
 Algorithm 9.1: (Insertion Sort) INSERTION(A, N).
 This algorithm sorts the array A with N
 elements.
 1. Set A[0] := – . [Initializes sentinel element.]
 2. Repeat Steps 3 to 5 for K = 2, 3, …, N;
 3. Set TEMP := A[K] and PTR := K – 1.
 4. Repeat while TEMP < A[PTR]:
 (a) Set A[PTR + 1] := A[PTR]. [Moves
 element forward.]
 (b) Set PTR := PTR – 1
 [End of loop.]
 5. Set A[PTR + 1] := TEMP. [Inserts element in
 proper place.]
 [End of Step 2 loop.]
 6. Return.
 */

#include<bits/stdc++.h>
using namespace std;

void InsertionSort(int arr[],int n){
    int temp;
    int j;
for(int i=1;i<n;i++){
    j=i-1;
    temp = arr[i];

    while( j >=0 && arr[j] > temp){
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = temp;
}

}

int main(){
    int size;
    cout << "Enter Array size: ";
    cin >> size;

    int arr[size];
    for(int i=0;i<size;i++){
        cin >> arr[i];
    }

    InsertionSort(arr,size);

    cout << "sorted array: " << endl;
    for( int i: arr){
        cout << i << " ";
    }
    cout << endl;
}