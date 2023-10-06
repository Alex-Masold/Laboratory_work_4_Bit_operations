#include <iostream>
using namespace std;
typedef unsigned int bitword;

bitword* bitsetZero(bitword* arr, int num) // 0
{
    if (num % 32 == 0)
        return (bitword*)calloc(num / 32, sizeof(bitword));
    else
        return (bitword*)calloc(num / 32 + 1, sizeof(bitword));
}

int bitsetGet(const bitword* arr, int idx) // 1
{
    int number = idx / 32;
    idx = idx - number * 32;
    idx = 31 - idx;
    return ((arr[number] >> idx) & 1);
}

void bitsetSet(bitword* arr, int idx, int newval) // 2
{
    if (newval == 1) // то сложение
    {
        int number = idx / 32;
        idx = idx - number * 32;
        idx = 31 - idx;
        arr[number] |= (1 << idx);
    }
    else // то умножение
    {
        int number = idx / 32;
        idx = idx - number * 32;
        idx = 31 - idx;
        arr[number] &= ~(1 << idx);
    }
}

int bitsetAny(const bitword* arr, int left, int right) // 3
{
    if (left == right)
        return 0;
    int N1 = (left >> 5), N2 = ((right - 1) >> 5), bit1 = (left - (N1 << 5)), bit2 = (31 - (right - 1 - (N2 << 5)));
    for (int i = N1; i <= N2; i++)
    {
        if (N1 == N2) {
            if ((arr[i] >> bit2) << (bit1 + bit2) > 0)
                return 1;
        }
        else if (i == N1) {
            if ((arr[i] << bit1) > 0)
                return 1;
        }
        else if (i == N2) {
            if ((arr[i] >> bit2) > 0)
                return 1;
        }
        else {
            if (arr[i] > 0)
                return 1;
        }
    }
    return 0;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int newval, ind;
    for (int i = 0; i < m; i++)
    {
        cin >> newval >> ind;
        if (newval == 1) // то сложение
        {
            int number = ind / 32;
            ind = ind - number * 32;
            ind = 31 - ind;
            arr[number] |= (1 << ind);
        }
        else // то умножение
        {
            int number = ind / 32;
            ind = ind - number * 32;
            ind = 31 - ind;
            arr[number] &= ~(1 << ind);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
}