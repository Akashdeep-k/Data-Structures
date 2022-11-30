//Floor of a number present in array using binary search
#include <iostream>
#include <vector>
using namespace std;
int Floor(vector<int> &arr, int target)
{
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (arr[mid] == target)
            return arr[mid];
        else if (arr[mid] < target)
            s = mid + 1;
        else
            e = mid - 1;
        mid = s + (e - s) / 2;
    }
    return e;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    int d;
    for (int i = 0; i < n; i++)
    {
        cin >> d;
        arr.push_back(d);
    }
    int target;
    cin >> target;
    int val = Floor(arr, target);
    if (val > -1)
        cout << "Floor is : " << arr[val] << endl;
    else
        cout << "Floor not found (out of bounds)" << endl;
    return 0;
}