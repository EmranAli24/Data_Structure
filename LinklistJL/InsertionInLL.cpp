#include <iostream>
#include <cstdlib>

using namespace std;

class Node {
public:
    int data;
    Node* next;
};

int main() {
    Node *head = nullptr, *newnode, *temp;
    head = nullptr;
    int choice = 1;
    int count = 0;
    int i = 0;

    while (choice) {
        newnode = new Node();
        count++;
        cout << "Enter Data: ";
        cin >> newnode->data;
        newnode->next = nullptr;

        if (head == nullptr) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }

        cout << "Do you want to continue (0,1)? ";
        cin >> choice;
    }

    cout << "Before Inserting: \n";
    temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    int pos;
    cout << "\nAt which position you want to insert data? ";
    cin >> pos;

    if (pos == 0) {
        newnode = new Node();
        cout << "Enter data you want to insert: ";
        cin >> newnode->data;
        newnode->next = head;
        head = newnode;
    } else if (pos == count) {
        newnode = new Node();
        cout << "Enter data you want to insert: ";
        cin >> newnode->data;
        newnode->next = nullptr;
        temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newnode;
    } else {
        if (pos > count) {
            cout << "Invalid position.";
        } else {
            temp = head;
            i = 0;
            while (i < pos - 1) {
                temp = temp->next;
                i++;
            }
            newnode = new Node();
            cout << "Enter data: ";
            cin >> newnode->data;
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }

    cout << "After Inserting data: \n";
    temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    // Free allocated memory
    temp = head;
    while (temp != nullptr) {
        Node* del = temp;
        temp = temp->next;
        delete del;
    }

    return 0;
}
