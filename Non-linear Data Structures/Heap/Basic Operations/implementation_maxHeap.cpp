// Max heap implementation with Insert, Delete, Display, HeapSort functions
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
            int i = ++size;
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
    void Delete()
    {
        if (size != 0)
        {
            swap(arr[1], arr[size]);
            int i = 1;
            int j = 2 * i;
            while (j < size)
            {
                if (arr[j] < arr[j + 1] && (j+1) < size)
                    j = j + 1;
                if (arr[i] < arr[j])
                    swap(arr[i], arr[j]);
                i = j;
                j = 2 * i;
            }
            size--;
        }
        else
        {
            cout << "Heap Overflow" << endl;
        }
    }
    void HeapSort(){
        int temp = size;
        while (temp != 0)
        {
            swap(arr[1], arr[temp]);
            int i = 1;
            int j = 2 * i;
            while (j < temp)
            {
                if (arr[j] < arr[j + 1] && (j+1) < temp)
                    j = j + 1;
                if (arr[i] < arr[j])
                    swap(arr[i], arr[j]);
                i = j;
                j = 2 * i;
            }
            temp--;
        }
    }
    void Display()
    {
        cout<<"The elements in heap are : ";
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    cout<<"Enter size of heap : ";
    int size;
    cin>>size;
    heap h1(size);
    int d;
    cout<<"Enter sequence for elements of heap : ";
    for (int i = 0; i < size; i++)
    {
        cin >> d;
        h1.Insert(d);
    }
    h1.Display();
    h1.HeapSort();
    h1.Display();
    return 0;
}