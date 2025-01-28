 /// ref: GFG

#include<iostream>
#include<vector>
using namespace std;

// Insertion sort Function to sort individual buckets

void InsertionSort(vector<float> & bucket){
    for(int i=1;i<bucket.size();i++){
        float temp = bucket[i];
        int j = i-1;

        while (j>=0 && bucket[j] > temp){
            bucket[j+1] = bucket[i];
            j--;
        }
        bucket[j+1] = temp ;
       
    }
}

// Function to sort arr[] of size n using Bucket sort

void BucketSort(float arr[],int n){
    // 1) Create n empty buckets
    vector<float> b[n];

    // 2) Put array elements in different buckets
    for(int i=0;i<n;i++){
        int bi = n * arr[i];
        b[bi].push_back(arr[i]);
    }

    // 3) sort individual buckets using insertion sort
    for(int i=0;i<n;i++){
        InsertionSort(b[i]);
    }

    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<b[i].size();j++){
            arr[index++] = b[i][j];
        }
    }
}

int main(){
    float arr[] = {0.897,0.565,0.656,0.1234,0.665,0.3434};

    int n = sizeof(arr) / sizeof(arr[0]);
    BucketSort(arr,n);

    cout << "Sorted array is \n";
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

    cout << "\n";
    return 0;
}
