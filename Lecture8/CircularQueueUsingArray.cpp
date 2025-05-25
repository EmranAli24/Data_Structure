 #include<bits/stdc++.h>
using namespace std;

#define N  5
int Queue[N];
int front = -1;
int rear = -1;

bool isEmpty() {
    return front == -1;
}

bool isFull() {
    return (rear + 1) % N == front;
}

void enqueue(int x){
    if(isEmpty()){
        front = rear = 0; 
    
        Queue[rear] = x;

    } else if(isFull()){
        cout << "Queue is full." << endl;

    }
    else{
        rear = (rear + 1) % N ;
        Queue[rear] = x;
    }
}

void dequeue(){
    if(isEmpty()){
        cout << "Queue is empty." << endl;
    } else if( front == rear){
        cout << Queue[front] << endl;
        front = rear = -1;
    }
    else{
        cout << Queue[front] << endl;
        front = (front + 1) % N ;
    }
}

void display(){
    int i = front ;
    if(isEmpty()){
        cout << "Queue is empty." << endl;
    }
    else{
        cout << "Queue is : " ;
        while(i != rear){
            cout << Queue[i] << " ";
            i = (i+1) % N ;
        }

        cout << Queue[rear] << endl;
    }
}

void Qsize(){
    if(front == -1) 
        cout << "Queqe size: " << 0 << endl;
    else if(rear >= front)
        cout << "Queqe size: " << rear - front + 1 << endl ;
    else{
        cout << "Queqe size: " << N-front+rear+1 << endl;
    }
}

void getFront() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
    }
    cout << "Front value: " <<  Queue[front] << endl;
}


void getRear() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
    }
    cout << "Rear Value: " <<  Queue[rear] << endl;
}




int main(){

    enqueue(2);
    display();
    enqueue(3);
    enqueue(5);
    display();
    dequeue();
    display();
    dequeue();
    enqueue(10);
    display();
    enqueue(20);
    display();
    Qsize();
    getRear();
    getFront();
    dequeue();
    dequeue();
    dequeue();
    Qsize();


}


