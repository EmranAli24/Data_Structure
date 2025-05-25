#ifndef Sort_H
#define Sort_H
#include <iostream>
#include <algorithm>
//Bubble  Sort:
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

//Merge Sort:
void mergeSort(int num[], int low, int mid, int high)
{
    int a1 = mid - low + 1;
    int b2 = high - mid;
    int a[a1], b[b2];

    
    for (int i = 0; i < a1; i++)
        a[i] = num[low + i];
    for (int j = 0; j < b2; j++)
        b[j] = num[mid + 1 + j];

    
    int i = 0, j = 0, k = low;
    while (i < a1 && j < b2)
    {
        if (a[i] <= b[j])
            num[k++] = a[i++];
        else
            num[k++] = b[j++];
    }

    
    while (i < a1)
        num[k++] = a[i++];

    
    while (j < b2)
        num[k++] = b[j++];
}

//selection sort:
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) minIdx = j;
        }
        std::swap(arr[i], arr[minIdx]);
    }
}

//Quick Sort:
int partition(int num[], int low, int high) {
    int index = low - 1;
    int pivot = num[high];
    for (int i = low; i < high; i++) {
        if (num[i] <= pivot) {
            index++;
           std:: swap(num[i], num[index]);
        }
    }
    index++;
   std:: swap(num[high], num[index]);
    return index;
}

void QuickSort(int num[], int low, int high) {
    if (low < high) {
        int pivot = partition(num, low, high);
        QuickSort(num, low, pivot - 1);
        QuickSort(num, pivot + 1, high);
    }
}

//Count sort:
void CountSort(int arr[], int n)
{
    // Step-1: Find Max value:
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    // Step-2: Create new array with max value size:
    int frequency[max + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        frequency[arr[i]] += 1;
    }

    // Step-3: Update frequency table: updated value = current value + previous value:
    for (int i = 1; i <= max; i++)
    {
        frequency[i] = frequency[i] + frequency[i - 1];
    }

    // Step-4: Sort values:

    // i. Iterate given array from last position
    // ii. Get value and use this as index in updated array
    // iii. Get value from updated array and decrease one
    // iv. Use this value as an index in new array
    // v. Set newArray[value] = Givenarr[i]
    int newArray[n];
    for (int i = n - 1; i >= 0; i--)
    {
        newArray[--frequency[arr[i]]] = arr[i];
    }

    // Step-5: Copy newArray to given array:
    for (int i = 0; i < n; i++)
    {
        arr[i] = newArray[i];
    }
}

// Insertion Sort:
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

//Redix Sort:
void CountSort(int arr[], int n, int pos) {
    int frequencyArry[10] = {0};


    // Count occurrences
    for (int i = 0; i < n; i++) {
        frequencyArry[(arr[i] / pos) % 10]++;
    }

    // Calculate cumulative frequency
    for (int i = 1; i < 10; i++) {
        frequencyArry[i] += frequencyArry[i - 1];
    }



    int newArray[n];
    for (int i = n - 1; i >= 0; i--) {
        newArray[--frequencyArry[(arr[i] / pos) % 10]] = arr[i];
    }

    // Copy the sorted values back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = newArray[i];
    }
}

void RadixSort(int arr[], int n) {
    int max = arr[0];

    // Find the maximum value
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    
    
    for (int pos = 1; max / pos > 0; pos *= 10) {
        CountSort(arr, n, pos);
    }
}




#endif