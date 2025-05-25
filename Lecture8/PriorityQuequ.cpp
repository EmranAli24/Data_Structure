#include<iostream>
#include<queue>
using namespace std;

int main(){
    priority_queue<int> pqu;
    pqu.push(21);
    pqu.push(22);
    pqu.push(24);
    pqu.push(25);

    pqu.pop();

    while (!pqu.empty())    
    {
        cout << pqu.top() << " ";
        pqu.pop();
    }
    
}