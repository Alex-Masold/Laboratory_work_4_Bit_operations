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
    int N, t; // четвертая
    cin >> N;
    int num, idx, newval, left, right;
    bitword* arr = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> t;
        switch (t)
        {
        case 0:
            cin >> num;
            arr = bitsetZero(arr, num);
            cout << endl;
            break;
        case 1:
            cin >> idx;
            cout << bitsetGet(arr, idx) << endl;
            break;
        case 2:
            cin >> idx >> newval;
            bitsetSet(arr, idx, newval);
            break;
        case 3:
            cin >> left >> right;
            if (bitsetAny(arr, left, right) == 0)
                cout << "none" << endl;
            else
                cout << "some" << endl;
            break;
        }
    }
}