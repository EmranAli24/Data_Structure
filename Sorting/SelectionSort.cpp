/***************************************************************************************
 * 
 *  MIN(A, K, N, LOC)
 An array A is in memory. This procedure
 finds the location LOC of the smallest
 element among A[K], A[K + 1], …, A[N].
 1. Set MIN := A[K] and LOC := K. [Initializes
 pointers.]
 2. Repeat for J = K + 1, K + 2, …, N:
 If MIN > A[J], then: Set MIN := A[J]
 and LOC := A[J] and LOC := J.
 [End of loop.]
 3. Return
***********************************************************************************************
  Algorithm 9.3: (Selection Sort) SELECTION(A, N)
 This algorithm sorts the array A with N
 elements.
 1. Repeat Steps 2 and 3 for K = 1, 2, …, N 
1:
 2. Call MIN(A, K, N, LOC).
 3. [Interchange A[K] and A[LOC].]
 Set TEMP := A[K], A[K] := A[LOC] and
 A[LOC] := TEMP.
 [End of Step 1 loop.]
 4. Exit
 * 
 ****************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

void MIN(int A[],int K,int N,int &LOC){
    int min = A[K];
    LOC = K;

    for(int i = K+1;i<N;i++){
        if(min > A[i]){
            min = A[i];
            LOC = i ;
        }
    }
}

void SelectionSort(int A[],int N){
    int LOC = 0;
    int temp;

    for(int i=0;i<N-1;i++){
        MIN(A,i,N,LOC);
        temp = A[i];
        A[i] = A[LOC];
        A[LOC] = temp ;
    }
}

int main(){
        int size;
        cout << "Enter Array size: " << endl;
        cin >> size;

        int A[size];
        for(int i=0;i<size;i++){
            cin >> A[i];
        }
  //  int A[] = {2,7,4,1,5,3};
    SelectionSort(A,size);

    for(int i:A){
        cout << i << " ";
    }
    cout << endl;
}








