/*
Implementation of Deque using Circular Array asks to implement the following functions of a Deque using a circular array:

insertFront(x) : inserts an element x at the front of the deque
insertRear(x)  : inserts an element x at the rear of the deque
deleteFront(x) : delete an element x at the front of the deque
deleteRear(x)  : delete an element x at the rear of the deque
getFront()     : return the element present at the front of the deque
getRear()     : return the element present at the rear of the deque
isEmpty()     : return whether or not the Deque is empty
isFull()     : return whether or not the Deque is full

*/
#include <iostream>
using namespace std;
const int MAX_SIZE = 100;
int deque[MAX_SIZE];
 
int front = -1;
int rear = -1;
 
bool isEmpty() {
    if (front == -1) {
        return true;
    }
    return false;
}
 
bool isFull() {
    if ((rear + 1) % MAX_SIZE == front) {
        return true;
    }
    return false;
}
void insertFront(int x) {
    if (!isFull()) {
        if (front == -1) {
            front = rear = 0;
            deque[front] = x;
        } 
        else {
            if (front == 0) {
                front = MAX_SIZE - 1;
            } else {
                front--;
            }  
            deque[front] = x;
        }
    }
}
void insertRear(int x) {
    if (!isFull()) {
        if (rear == -1) {
            front = rear = 0;
            deque[rear] = x;
        } 
        else {
            if (rear == MAX_SIZE - 1) {
                rear = 0;
            } else {
                rear++;
            }
            
            deque[rear] = x;
        }
    }
}
void deleteFront() {
    if (!isEmpty()) {
        if (front == rear) {
            front = rear = -1;
        } 
        else {
            if (front == MAX_SIZE - 1) {
                front = 0;
            } else {
                front++;
            }
        }
    }
}
void deleteRear() {
    if (!isEmpty()) {
        if (front == rear) {
            front = rear = -1;
        } 
        else {
            if (rear == 0) {
                rear = MAX_SIZE - 1;
            } else {
                rear--;
            }
        }
    }
}
int getFront() {
    if (!isEmpty()) {
        return deque[front];
    }
    return -1;
}
int getRear() {
    if (!isEmpty()) {
        return deque[rear];
    }
    return -1;
}
int main() {
    insertFront(5);
    insertRear(10);
    insertRear(11);
    insertFront(19);
    cout<<getFront()<<endl;
    cout<<getRear()<<endl;
    if (isFull()) {
        cout<<"true"<<endl;
    } else {
        cout<<"false"<<endl;
    }
    deleteRear();
    cout<<getRear()<<endl;
    deleteFront();
    cout<<getFront()<<endl;
    if (isEmpty()) {
        cout<<"true"<<endl;
    } else {
        cout<<"false"<<endl;
    }
    
    return 0;
}