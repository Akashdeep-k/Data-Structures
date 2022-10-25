#include<iostream>
using namespace std;
//Doubly ended queue (deque) implementation
class deque{
    //properties
    int len;
    int front;
    int rear;
    int* arr;
    public : 
    //behaviour
    deque(){}
    deque(int len){
        this->len = len;
        arr = new int[len];
        front = -1;
        rear = -1;
    }
    void push_front(int d){
        if((front == 0 && rear == len-1) || front==rear+1){//to check whether the deque is full
            cout<<"Deque overflow"<<endl;
        }
        else if(front == -1){//to check whether the queue is empty
            front = 0;
            rear = 0;
            arr[front] = d;
        }
        else if(front == 0){//to maintain the cyclic nature
            front = len-1;
            arr[front] = d;
        }
        else{//normal flow
            front--;
            arr[front] = d;
        }
    }
    void push_rear(int d){
        if((front == 0 && rear == len-1) || front==rear+1){//to check whether the deque is full
            cout<<"Deque overflow"<<endl;
        }
        else if(front==-1){//to check whether the deque is empty
            front = rear = 0;
            arr[rear] = d;
        }
        else if(rear==len-1){//to maintain the cyclic nature of deque
            rear = 0;
            arr[rear] = d;
        }
        else{//normal flow
            rear++;
            arr[rear] = d;
        }
    }
    void pop_front(){
        if(front==-1){//to check whether the deque is empty
            cout<<"Deque underflow"<<endl;
        }
        else if(front==rear){//to check if there is only one element in deque
            front = rear = -1;
        }
        else if(front == len-1){//to maintain the cyclic nature
            front = 0;
        }
        else{//normal flow
            front++;
        }
    }
    void pop_rear(){
        if(front==-1){//to check whether the deque is empty
            cout<<"Deque underflow"<<endl;
        }
        else if(front==rear){//to check if there is only one element in deque
            front = rear = -1;
        }
        else if(rear==0){//to maintain the cyclic nature
            rear = len-1;
        }
        else{//normal flow
            rear--;
        }        
    }
    bool empty(){
        if(front==-1)
        return true;
        else
        return false;
    }
    int get_front(){
        if(empty())
        return -1;
        else
        return arr[front];
    }
    int get_rear(){
        if(empty())
        return -1;
        else
        return arr[rear];
    }
};
int main(){
    //Enter your code here
    //Functions that can be used are : push_front(), push_rear(), pop_front(), pop_rear(), empty(), get_rear(), get_front().
    return 0;
}