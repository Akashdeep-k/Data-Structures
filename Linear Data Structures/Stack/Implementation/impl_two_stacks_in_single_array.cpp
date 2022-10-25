#include<iostream>
using namespace std;
//LIFO or FILO order implementation
class TwoStack{
    int n;
    int* arr;
    int top1;
    int top2;
    public : 
    TwoStack(int n){
        this->n = n;
        arr = new int[n];
        top1 = -1;
        top2 = n;
    }
    void push1(int d){
        if((top2-top1)>1){
        top1++;
        arr[top1] = d;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }
    void push2(int d){
        if((top2-top1)>1){
        top2--;
        arr[top2] = d;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }
    void pop1(){
        if(top1==-1){
            cout<<"Stack Underflow"<<endl;
        }
        else{
            top1--;
        }
    }
    void pop2(){
        if(top2==n){
            cout<<"Stack Underflow"<<endl;
        }
        else{
            top2++;
        }
    }
    int size1(){
        return top1+1;
    }
    int size2(){
        return n-top2;
    }
    bool empty1(){
        if(top1==-1)
        return true;
        else
        return false;
    }
    bool empty2(){
        if(top2==n)
        return true;
        else
        return false;
    }
    int peek1(){
        if(top1!=-1)
        return arr[top1];
        else
        return -1;
    }
    int peek2(){
        if(top2!=n)
        return arr[top2];
        else
        return -1;
    }
};
int main(){
    //enter your code here
    return 0;
}