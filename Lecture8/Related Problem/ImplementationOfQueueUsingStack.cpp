#include<bits/stdc++.h>
using namespace std;
class MyQueue {
    private:
       stack<int> s1;
       stack<int> s2;
   
   public:
       MyQueue() {}
       
       void push(int x) {
           while(!s1.empty()){
               s2.push(s1.top());
               s1.pop();
           }
   
           s1.push(x);
           while(!s2.empty()){
               s1.push(s2.top());
               s2.pop();
           }
       }
       
       int pop() {
           int temp = s1.top();
           s1.pop();
           return temp;
       }
       
       int peek() {
           return s1.top();
       }
       
       bool empty() {
           return s1.empty();
       }
   };

   int main(){
        MyQueue* obj = new MyQueue();
        obj->push(5);
        obj->push(10);
        obj->push(15);
        int param2 = obj->pop();
        int param3 = obj->peek();
        bool param4 = obj->empty();

        cout << param2 << endl;
        cout << param3 << endl;
        cout << param4 << endl;

        return 0 ;
   }
   
   /**
    * Your MyQueue object will be instantiated and called as such:
    * MyQueue* obj = new MyQueue();
    * obj->push(x);
    * int param_2 = obj->pop();
    * int param_3 = obj->peek();
    * bool param_4 = obj->empty();
    */