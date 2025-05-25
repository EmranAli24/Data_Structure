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
    int choice = 1;  

    while (choice) {
        newnode = new Node();
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
