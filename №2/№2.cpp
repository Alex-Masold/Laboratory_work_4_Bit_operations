#include <iostream>
using namespace std;

int main()
{
    int n, n1, x = 0;
    cin >> n;

    for (int i = 0; i < 32; i++)
    {
        cout << ((n >> (31 - i)) & 1);
    }
    cout << endl;

    for (int i = 0; i < 32; i++)
    {
        n1 = ((n >> (i)) & 1);
        if (n1 == 1)
        {
            x += pow(2, 31 - i);
        }
    }
    cout << x << endl;

    for (int i = 0; i < 32; i++)
    {
        cout << ((n >> (i)) & 1);
    }
}