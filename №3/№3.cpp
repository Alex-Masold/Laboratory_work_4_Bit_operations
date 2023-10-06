#include <iostream>
using namespace std;

int main()
{
    int n, j, * arr;
    cin >> n;
    int r;
    arr = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (j = 0; j <= 16; j++)
        {
            if ((arr[i] & 1) == 1)
                break;
            arr[i] >>= 1;
        }
        cout << pow(2, j) << endl;
    }
}