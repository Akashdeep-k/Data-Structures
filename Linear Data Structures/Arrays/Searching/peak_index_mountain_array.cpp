// Author  :  Akashdeep-k
// Program :  To find peak index in a mountain array
// Examples : 1. array = 1 2 3 4 2 1 (Peak index = 3)
//            2. array = 1 4 10 5 2 (Peak index = 2)
//            3. array = 0 1 0 (Peak index = 1)
#include <iostream>
using namespace std;
int peak(int arr[], int n)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e-s)/2;
    while(s < e){
        if(arr[mid] > arr[mid + 1])
            e = mid;
        else
            s = mid + 1;
        mid = s + (e-s)/2;
    }
    return s;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << peak(arr, n);
    return 0;
}