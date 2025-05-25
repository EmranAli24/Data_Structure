#include <iostream>
using namespace std;

class twoStack {
  int * arr;
  int size;
  int top1;
  int top2;
  public:
    twoStack(int n) {
      arr = new int[n];
      size = n;
      top1 = n / 2 + 1;
      top2 = n / 2;
    }
  void pushStack1(int data) {
    if (top1 > 0) {
      top1--;
      arr[top1] = data;
      cout << "Element pushed" << "\n";
    } else {
      cout << "Stack Overflow" << "\n";
    }
  }
  void pushStack2(int data) {
    if (top2 < size - 1) {
      top2++;
      arr[top2] = data;
      cout << "Element pushed" << "\n";
    } else {
      cout << "Stack Overflow" << "\n";
    }
  }
  void popStack1() {
    if (top1 <= size / 2) {
      top1++;
      cout << "top element popped" << "\n";
    } else {
      cout << "Stack Underflow" << "\n";
    }
  }
  void popStack2() {
    if (top2 >= size / 2 + 1) {
      top2--;
      cout << "top element popped" << "\n";
    } else {
      cout << "Stack underflow" << "\n";
    }
  }
};
int main() {
  twoStack ts(5);
  ts.pushStack1(10);
  ts.pushStack1(22);
  ts.popStack1();
  ts.popStack2();
  ts.popStack1();
}


/*

//This approach is super efficient when you want to dynamically
// expand the stack in which an element needs to be inserted
// when the top pointer exceeds half of the array.


#include <iostream>
using namespace std;

class twoStack {
  int * arr;
  int size;
  int top1;
  int top2;
  public:
    twoStack(int n) {
      arr = new int[n];
      size = n;
      top1 = -1;
      top2 = size;
    }
  void pushStack1(int data) {
    if (top1 < top2 - 1) {
      top1++;
      arr[top1] = data;
      cout << "Element pushed" << "\n";
    } else cout << "Stack Overflow" << "\n";
  }
  void pushStack2(int data) {
    if (top1 < top2 - 1) {
      top2--;
      arr[top2] = data;
      cout << "Element pushed" << "\n";
    } else cout << "Stack Overflow" << "\n";
  }
  void popStack1() {
    if (top1 >= 0) {
      top1--;
      cout << "Element popped" << "\n";
    } else cout << "Stack Underflow" << "\n";
  }
  void popStack2() {
    if (top2 < size) {
      top2++;
      cout << "Element Popped" << "\n";
    } else cout << "Stack Underflow" << "\n";
  }
};
int main() {
  twoStack ts(6);
  ts.pushStack1(10);
  ts.popStack2();
  return 0;
}



*/
/*
push1(10): Insert 10 in stack1
push2(21): Insert 21 in stack2
pop2(): Pop top element from stack2

*/