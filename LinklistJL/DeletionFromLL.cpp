#include <iostream>
#include <cstdlib>

using namespace std;

class Node {
public:
    int data;
    Node* next;
};

int main() {
    Node *head = nullptr, *newnode, *temp, *nextNode;
    int choice = 1;
    int count = 0;
    int i = 1;

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

    cout << "Before Deleting any element: \n";
    temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    int pos;
    cout << "\nFrom which position you want to Delete data? ";
    cin >> pos;

    if (pos == 0) {
        temp = head;
        head = head->next;
        delete temp;
    } else if (pos == count) {
        Node* prev = nullptr;
        temp = head;
        while (temp->next != nullptr) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == head) {
            head = nullptr;
        } else {
            prev->next = nullptr;
        }
        delete temp;
    } else {
        if (pos > count || pos < 0) {
            cout << "Invalid position.";
        } else {
            temp = head;
            i = 0;
            while (i < pos - 1) {
                temp = temp->next;
                i++;
            }

            nextNode = temp->next;
            temp->next = nextNode->next;
            delete nextNode;
        }
    }

    cout << "\nAfter Deleting the element: \n";
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
