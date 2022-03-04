#include <iostream>

using namespace std;

int n;
int arr[10];
bool isAssigned[10];
int cnt = 0;

void Try(int k)
{
    if (k == 7)
    {
        int ict = arr[0] * 100 + arr[1] * 10 + arr[2];
        int k62 = arr[3] * 100 + 62;
        int hust = arr[4] * 1000 + arr[5] * 100 + arr[6] * 10 + arr[2];
        if (ict - k62 + hust == n)
            ++cnt;
        return;
    }

    for (int i = 1; i <= 9; ++i)
    {
        if (!isAssigned[i])
        {
            isAssigned[i] = true;
            arr[k] = i;
            Try(k + 1);
            isAssigned[i] = false;
        }
    }
}

int main()
{
    cin >> n;
    Try(0);
    cout << cnt;
    return 0;
}