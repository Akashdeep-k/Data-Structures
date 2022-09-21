#include <iostream>
using namespace std;
// FIFO or LILO order implementation
class queue
{
    // properties :
    int len;
    int front;
    int rear;
    int *arr;

public:
    // behaviour :
    queue() {} // non-parameterized constructor
    queue(int len)
    { // parameterized constructor
        this->len = len;
        arr = new int[len];
        front = rear = -1;
    }
    void enque(int d)
    { // push operation
        if ((front == 0 && rear == len - 1) || (rear == front - 1))
        { // to check whether queue is full
            cout << "Queue overflow" << endl;
        }
        else if (front == -1)
        { // to check if queue was empty
            front = rear = 0;
            arr[rear] = d;
        }
        else if (rear == len - 1 && front > 0)
        { // to maintain the cyclic nature
            rear = 0;
            arr[rear] = d;
        }
        else
        { // normal flow
            rear++;
            arr[rear] == d;
        }
    }
    void deque()
    {
        if (front == -1)
        { // to check if the queue is empty
            cout << "Queue underflow" << endl;
        }
        if (front == rear)
        { // to check if there is only a single element in queue
            front = rear = -1;
        }
        else if (front == len - 1)
        { // to maintain the cyclic nature
            front = 0;
        }
        else
        { // normal flow
            front++;
        }
    }
    bool empty()
    {
        if (front == -1)
            return true;
        else
            return false;
    }
    int peek()
    {
        if (front == -1)
            return -1;
        else
            return arr[front];
    }
    int size()
    {
        if (rear > front)
            return rear - front + 1;
        else if (rear == front)
        {
            if (front == -1)
                return 0;
            else
                return 1;
        }
        else
            return len - (front - rear - 1);
    }
};
int main()
{
    // Enter your code here
    return 0;
}