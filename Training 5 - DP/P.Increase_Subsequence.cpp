#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, a[10100], iMem[10100];

int Lis(int i)
{
    if (iMem[i] != -1)
        return iMem[i];
    int res = 1;
    for (int j = 1; j < i; ++j)
    {
        if (a[j] < a[i])
        {
            res = max(res, 1 + Lis(j));
        }
    }
    iMem[i] = res;
    return res;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    memset(iMem, -1, sizeof(iMem));
    for (int i = 1; i <= n; ++i)
        Lis(i);
    int res = iMem[1];
    for (int i = 2; i <= n; ++i)
        res = max(res, iMem[i]);
    cout << res;
    return 0;
}