#include<iostream>
using namespace std;
//FIFO or LILO order implementation
class queue{
    int n;
    int* arr;
    int front;
    int rear;
    public :
    queue(){}
    queue(int n){
        this->n = n;
        arr = new int[n];
        front = 0;
        rear = 0;
    }
    void enque(int d){
        if(front==rear){
            front = 0;
            rear = 0;
        }
        if(rear==n){
            cout<<"Queue overflow"<<endl;
        }
        else{
        arr[rear] = d;
        rear++;
        }
    }
    void deque(){
        if(front==rear){
            cout<<"Queue underflow"<<endl;
            front = 0;
            rear = 0;
        }
        else{
            arr[front] = -1;
            front++;
        }
    }
    int size(){
        return rear - front;
    }
    bool empty(){
        if(front==rear)
        return true;
        else
        return false;
    }
    int peek(){
        if(front==rear)
        return -1;
        else
        return arr[front];
    }
};
int main(){
    //Enter your code here
    return 0;
}