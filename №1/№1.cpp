# include <iostream>
using namespace std;

int main()
{
    int n;
    int count = 0, max = 0;
    cin >> n;

    for (int i = 0; i < 32; i++)
    {
        if ((n & 1) == 1)
        {
            count++;
            if (count > max)
                max = count;
        }
        else
        {
            count = 0;
        }
        n >>= 1;
    }
    cout << max;
}