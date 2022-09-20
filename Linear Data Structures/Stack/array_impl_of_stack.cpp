#include<iostream>
using namespace std;
//LIFO or FILO order implementation
class stack{
    int n;
    int* arr;
    int top;
    public : 
    stack(int n){
        this->n = n;
        arr = new int[n];
        top = -1;
    }
    void push(int d){
        if((top+1)<n){
        top++;
        arr[top] = d;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }
    void pop(){
        if(top==-1){
            cout<<"Stack Underflow"<<endl;
        }
        else{
            top--;
        }
    }
    int size(){
        return top+1;
    }
    bool empty(){
        if(top==-1)
        return true;
        else
        return false;
    }
    int peek(){
        if(top!=-1)
        return arr[top];
        else
        return -1;
    }
};
int main(){
    //enter your code here
    return 0;
}