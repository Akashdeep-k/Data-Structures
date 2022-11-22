// Max heap implementation
#include <iostream>
using namespace std;
class heap
{
    int n;
    int size;
    int *arr;

public:
    heap() {}
    heap(int n)
    {
        this->n = n + 1;
        this->size = 0;
        this->arr = new int[n];
        this->arr[0] = 0;
    }
    void Insert(int data)
    {
        if (size < n - 1)
        {
            arr[++size] = data;
            int i = size;
            while (data > arr[i / 2] && i > 1)
            {
                arr[i] = arr[i / 2];
                i = i / 2;
            }
            arr[i] = data;
        }
        else
        {
            cout << "Heap Overflow" << endl;
        }
    }
    void Display()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    int size = 20;
    heap h1(size);
    int d;
    for (int i = 0; i < size; i++)
    {
        cin >> d;
        h1.Insert(d);
    }
    h1.Display();
    return 0;
}