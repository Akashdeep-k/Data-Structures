/*  n==7(odd)
    1 1 1 1 1 1 1
    1 1           1
    1   1           1
    1     1 1 1 1 1 1 1
    1     1           1
    1     1           1
    1     1           1
      1   1           1
        1 1           1
          1 1 1 1 1 1 1

    n==4(even)
    1 1 1 1
    1 1     1
    1   1 1 1 1
    1   1     1
      1 1     1
        1 1 1 1
*/
#include <iostream>
using namespace std;
void Ultimate_Cube(int n)
{
    for (int i = 1; i <= n + n / 2; i++) // total 10 rows = 7 + 7/2
    {
        if (i == 1) // 1st row
        {
            for (int j = 1; j <= n; j++)
            {
                cout << "1 ";
            }
            cout << endl;
        }
        if (i > 1 && i <= n / 2) // 2nd and 3rd row
        {
            int space = i - 2; // spaces after 1 in first column
            cout << "1 ";      // printing 1 in first column
            for (int j = 1; j <= n + i - 1; j++)
            {
                if ((j - space) == 1 || j == n + i - 1)
                    cout << "1 ";
                else if ((j - space) == 2)
                { /* skipping this extra iteration */
                }
                else
                    cout << "  ";
            }
            cout << endl;
        }
        if (i == (n / 2 + 1)) // 4th row
        {
            for (int j = 1; j <= n + (n / 2); j++)
            {
                if (j == 1)
                    cout << "1 ";
                else if (j <= n / 2)
                    cout << "  ";
                else
                    cout << "1 ";
            }
            cout << endl;
        }
        if ((i >= n / 2 + 2) && (i <= n)) // 5th, 6th, 7th row
        {
            for (int j = 1; j <= n + (n / 2); j++)
            {
                if (j == 1)
                    cout << "1 ";
                else if (j <= n / 2)
                    cout << "  ";
                else if (j == n / 2 + 1)
                    cout << "1 ";
                else if (j > (n / 2 + 1) && j != (n + n / 2))
                    cout << "  ";
                else
                    cout << "1 ";
            }
            cout << endl;
        }
        if (i > n && i < (n + n / 2)) // 8th
        {
            int space = i - n;
            for (int j = 1; j <= (n + n / 2); j++)
            {
                if (j <= space)
                    cout << "  ";
                else if (j - space == 1)
                    cout << "1 ";
                else if (j <= n / 2)
                    cout << "  ";
                else if (j == n / 2 + 1)
                    cout << "1 ";
                else if (j > n / 2 && j < (n + n / 2))
                    cout << "  ";
                else
                    cout << "1 ";
            }
            cout << endl;
        }
        if (i == (n + n / 2))
        {
            for (int j = 1; j <= n + (n / 2); j++)
            {
                if (j <= n / 2)
                    cout << "  ";
                else
                    cout << "1 ";
            }
            cout << endl;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    Ultimate_Cube(n);
    return 0;
}