#include <bits/stdc++.h>
using namespace std;

class BinaryHeap {
public:
    int capacity; 
    int size; 
    int *arr; 

    BinaryHeap(int cap) {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
    }

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    // Insert: Now ensures parent >= child (Max Heap property)
    void Insert(int x) {
        if (size == capacity) {
            cout << "Binary Heap Overflow" << endl;
            return;
        }
        arr[size] = x;
        int k = size;
        size++;

        // Changed to arr[parent(k)] < arr[k] (for Max Heap)
        while (k != 0 && arr[parent(k)] < arr[k]) {
            swap(&arr[parent(k)], &arr[k]);
            k = parent(k);
        }
    }

    // Heapify: Now ensures parent >= children (Max Heap)
    void Heapify(int ind) {
        int ri = right(ind);
        int li = left(ind);
        int largest = ind;  // Renamed 'smallest' to 'largest' for clarity

        if (li < size && arr[li] > arr[largest])  // Changed to '>'
            largest = li;
        if (ri < size && arr[ri] > arr[largest])  // Changed to '>'
            largest = ri;

        if (largest != ind) {
            swap(&arr[ind], &arr[largest]);
            Heapify(largest);
        }
    }

    // Renamed getMin() to getMax()
    int getMax() { return arr[0]; }

    // Renamed ExtractMin() to ExtractMax()
    int ExtractMax() {
        if (size <= 0) return INT_MIN;  // Changed from INT_MAX to INT_MIN
        if (size == 1) {
            size--;
            return arr[0];
        }
        int maxi = arr[0];
        arr[0] = arr[size - 1];
        size--;
        Heapify(0);
        return maxi;
    }

    // Decreasekey renamed to IncreaseKey (since we're in Max Heap)
    void IncreaseKey(int i, int val) {
        arr[i] = val;
        // Changed to arr[parent(i)] < arr[i] (Max Heap fix)
        while (i != 0 && arr[parent(i)] < arr[i]) {
            swap(&arr[parent(i)], &arr[i]);
            i = parent(i);
        }
    }

    void Delete(int i) {
        IncreaseKey(i, INT_MAX);  // Use INT_MAX to ensure it bubbles up
        ExtractMax();
    }

    void swap(int *x, int *y) {
        int temp = *x;
        *x = *y;
        *y = temp;
    }

    void print() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    BinaryHeap h(20);
    h.Insert(45);
    h.Insert(36);
    h.Insert(54);
    h.Insert(27);
    h.Insert(63);
    h.Insert(72);
    h.Insert(61);
    h.Insert(18);
    // cout << "Max value is " << h.getMax() << endl;  // Now outputs max
    // h.Insert(9);
    // cout << "Max value is " << h.getMax() << endl;
    // h.IncreaseKey(3, 10);  // Renamed from Decreasekey
    // cout << "Max value is " << h.getMax() << endl;
    // h.ExtractMax();
    // cout << "Max value is " << h.getMax() << endl;
    // h.Delete(0);
    // cout << "Max value is " << h.getMax() << endl;
    h.print();
    

    return 0;
}