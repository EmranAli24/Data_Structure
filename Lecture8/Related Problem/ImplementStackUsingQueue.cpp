// https://leetcode.com/problems/implement-stack-using-queues/

#include<bits/stdc++.h>
using namespace std; 


class MyStack {
    private:
          queue<int> q;
    public:
        MyStack() {}
        
        void push(int x) {
            q.push(x);
            for(int i=0;i<q.size()-1;i++){
                q.push(q.front());
                q.pop();
            }
        }
        
        int pop() {
            int top = q.front();
            q.pop();
            return top;
        }
        
        int top() {
            return q.front();
        }
        
        bool empty() {
            return q.empty();
        }
    };



int main(){

    MyStack *obj = new MyStack();
    obj->push(5);
    obj->push(10);
    obj->push(15);

    int para2 = obj->pop();
    int para3 = obj->pop();
    bool para4 = obj->empty();

    cout << para2 << " " << para3 << " " << para4 << endl;
    return 0;
}


/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */