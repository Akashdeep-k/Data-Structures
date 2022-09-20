#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node() {}
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
// LIFO or FILO order implementation using linked lists
class stack
{
    node *top;
    int s;

public:
    stack()
    {
        top = NULL;
        s = 0;
    }
    void push(int d)
    {
        s++;
        node *n = new node(d);
        n->next = top;
        top = n;
    }
    void pop()
    {
        if (top)
        {
            s--;
            node *temp = top;
            top = top->next;
            free(temp);
        }
        else
        {
            cout << "Stack Underflow" << endl;
        }
    }
    bool empty()
    {
        if (top)
            return false;
        else
            return true;
    }
    int peek()
    {
        if (top)
            return top->data;
        else
            return -1;
    }
    int size()
    {
        return s;
    }
    void display()
    {
        if(top){
        node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
        }
        else
        cout<<"Stack is empty\n";
    }
};
int main()
{
    // Enter your code here
    stack s;
    s.push(5);
    s.push(6);
    s.push(7);
    cout<<"Display : "<<endl;
    s.display();
    cout<<"Empty : "<<s.empty()<<endl;
    cout<<"Size : "<<s.size()<<endl;

    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;

    cout<<"Empty : "<<s.empty()<<endl;
    cout<<"Size : "<<s.size()<<endl;

    cout<<"Display : "<<endl;
    s.display();
    return 0;
}