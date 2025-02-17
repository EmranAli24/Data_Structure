#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> Stack; 
int top = -1;

void push()
{
    int x;
    cout << "Enter data: ";
    cin >> x;
    if (top == N - 1)
    {
        cout << "Stack Overflow.\n";
    }
    else
    {
        top++;
        Stack[top] = x;
    }
}

void pop()
{
    int item;

    if (top == -1)
    {
        cout << "Stack Underflow.\n";
    }
    else
    {
        item = Stack[top];
        top--;
        cout << "Poped item: " << item << endl;
    }
}

void peek()
{
    if (top == -1)
    {
        cout << "Stack is empty.\n";
    }
    else
    {
        cout << "Top item: " << Stack[top] << endl;
    }
}

void display()
{
    int i;
    cout << "Stack Elements: ";
    for (int i = top; i >= 0; i--)
    {
        cout << Stack[i] << " ";
    }
    cout << endl;
}

void isFull(){
    if(top == N-1) {
        cout << "Stack is Full.\n";
    }
    else{
        cout << "Stack is not Full.\n";
    }
}

void isEmpty(){
    if(top == -1 ){
        cout << "Stack is Empty.\n";
    }
    else{
        cout << "Stack is not Empty.\n";
    }
}

int main()
{

    cout << "Enter the size of the stack: ";
    cin >> N;
    Stack.resize(N);

    int choice;
    do
    {
        cout << "Stack Operations Menu:\n";
        cout << "1. Push\n";
        cout << "2.Pop\n";
        cout << "3.Peek\n";
        cout << "4.Display\n";
        cout << "5.Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            isFull();
            break;
        case 6:
            isEmpty();
            break;
        case 7:
            cout << "Exiting ...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}