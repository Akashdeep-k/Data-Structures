// Traversal, Insertion, Deletion, Rotation, Searching(Linear Searching), Sorting(Bubble Sort in asc. order), Exit
#include <iostream>

using namespace std;

int main()
{
    int arr[50], size, pos, num, k, choice = 1, search;
    cout << "Enter the size of the array : " << endl;//Array input
    cin >> size;
    cout << "Enter the elements of the array : " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int flag;
    while (choice)
    {
        cout << "Enter a number : " << endl;//Menu of array operations
        cout << "1. Traversal" << endl;
        cout << "2. Insertion" << endl;
        cout << "3. Deletion" << endl;
        cout << "4. Rotation" << endl;
        cout << "5. Searching" << endl;
        cout << "6. Sorting" << endl;
        cout << "7. Exit" << endl;
        cin >> flag;

        if (flag == 1)//Traversal
        {
            for (int i = 0; i < size; i++)
            {
                cout << arr[i] << endl;
            }
        }
        if (flag == 2)//Insertion
        {
            cout << "Enter the position : " << endl;
            cin >> pos;
            cout << "Enter the number : " << endl;
            cin >> num;
            if (pos <= 0 || pos > size + 1)
            {
                cout << "Invalid position" << endl;
            }
            else
            {
                for (int i = size; i >= pos - 1; i--)
                {
                    arr[i + 1] = arr[i];
                }
                arr[pos - 1] = num;
                size++;
                cout << "The final array after insertion is : " << endl;
                for (int i = 0; i < size; i++)
                {
                    cout << arr[i] << endl;
                }
            }
        }
        if (flag == 3)//Deletion
        {
            cout << "Enter the position of the element you want to delete :" << endl;
            cin >> pos;
            for (int i = pos - 1; i <= size - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            size--;
            cout << "The final array after deletion is : " << endl;
            for (int i = 0; i < size; i++)
            {
                cout << arr[i] << endl;
            }
        }
        if (flag == 4)//Rotation
        {
            cout << "Enter the number of elements you want to rotate to right side : " << endl;
            cin >> k;
            while (k--)
            {
                int num = arr[size - 1];
                for (int i = size - 1; i >= 1; i--)
                {
                    arr[i] = arr[i - 1];
                }
                arr[0] = num;
            }
            cout << "The final array after rotation is : " << endl;
            for (int i = 0; i < size; i++)
            {
                cout << arr[i] << endl;
            }
        }
        if (flag == 5)//Searcing
        {
            cout << "Enter the element you want to search :" << endl;
            cin >> num;
            for (int i = 0; i < size; i++)
            {
                if (arr[i] == num)
                {
                    search = 1;
                    pos = i;
                    break;
                }
            }
            if (search == 1)
            {
                cout << "Element is found at position : " << pos + 1 << endl;
            }
            else
            {
                cout << "Element is not found " << endl;
            }
        }
        if (flag == 6)//Sorting
        {
            for (int j = 0; j < size; j++)
            {
                for (int i = 0; i < size - 1 - j; i++)
                {
                    if (arr[i] > arr[i + 1])
                    {
                        int temp = arr[i + 1];
                        arr[i + 1] = arr[i];
                        arr[i] = temp;
                    }
                }
            }
            cout << "After sorting the array is : " << endl;
            for (int i = 0; i < size; i++)
            {
                cout << arr[i] << endl;
            }
        }
        if (flag == 7)//Exit
        {
            exit(0);
        }
    }
    return 0;
}