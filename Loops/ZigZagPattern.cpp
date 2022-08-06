/*
for n = 9
        *      *
      *   *  *   *
    *      *      *
*/
#include <iostream>
using namespace std;
void ZigZag(int n)
{
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (((i + j) % 4 == 0) || ((i == 2) && (j % 4 == 0)))
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    ZigZag(n);
    return 0;
}