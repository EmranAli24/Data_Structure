#include <iostream>
using namespace std;

// Size of the hash table
const int TABLE_SIZE = 7;

// HashNode class to represent a key-value pair
class HashNode {
public:
    int key;
    int value;

    // Constructor
    HashNode(int key, int value) {
        this->key = key;
        this->value = value;
    }
};

// HashTable class
class HashTable {
private:
    HashNode** table; // Array of pointers to HashNode
    int capacity;     // Capacity of the hash table

public:
    // Constructor
    HashTable() {
        capacity = TABLE_SIZE;
        table = new HashNode*[capacity];

        // Initialize all elements of the table to NULL
        for (int i = 0; i < capacity; i++) {
            table[i] = NULL;
        }
    }

    // First hash function: h1(k) = k mod 7
    int hashFunction1(int key) {
        return key % capacity;
    }

    // Second hash function: h2(k) = 1 + (k mod 5)
    int hashFunction2(int key) {
        return 1 + (key % 5);
    }

    // Insert a key-value pair into the hash table using double hashing
    void insert(int key, int value) {
        int hashIndex = hashFunction1(key);
        int stepSize = hashFunction2(key);

        // Double hashing to handle collisions
        while (table[hashIndex] != NULL && table[hashIndex]->key != -1) {
            hashIndex = (hashIndex + stepSize) % capacity;
        }

        // If the slot is empty or marked as deleted, insert the new node
        if (table[hashIndex] == NULL || table[hashIndex]->key == -1) {
            table[hashIndex] = new HashNode(key, value);
        }
    }

    // Display the hash table
    void display() {
        for (int i = 0; i < capacity; i++) {
            if (table[i] != NULL && table[i]->key != -1) {
                cout << "Index " << i << ": Key = " << table[i]->key << ", Value = " << table[i]->value << endl;
            } else {
                cout << "Index " << i << ": Empty" << endl;
            }
        }
    }

    // Destructor
    ~HashTable() {
        for (int i = 0; i < capacity; i++) {
            if (table[i] != NULL) {
                delete table[i];
            }
        }
        delete[] table;
    }
};

// Main function to test the hash table
int main() {
    HashTable hashTable;

    // Insert keys into the hash table
    hashTable.insert(27, 270);
    hashTable.insert(43, 430);
    hashTable.insert(692, 6920);
    hashTable.insert(72, 720);

    // Display the hash table
    cout << "Hash Table after insertion:" << endl;
    hashTable.display();

    return 0;
}