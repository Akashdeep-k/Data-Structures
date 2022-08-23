// To find square root of a number using binary search
#include <iostream>
using namespace std;
int square_root(int n)
{
    int s = 0;
    int e = n;
    long long int mid = s + (e - s) / 2;
    long long ans = -1;
    while (s <= e)
    {
        if (mid * mid == n)
            return mid;
        if (mid * mid < n)
        {
            ans = mid;
            s = mid + 1;
        }
        else
                e = mid - 1;
        mid = s + (e - s) / 2;
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    cout << square_root(n) << endl;
    return 0;
}