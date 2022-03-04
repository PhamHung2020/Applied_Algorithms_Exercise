#include <iostream>
#include <algorithm>

using namespace std;

int cnk()
{
    int n, k, m;
    cin >> n >> k >> m;
    int diff = n - k;
    int res = 1;
    for (int i = 1; i <= k; ++i)
    {
        res *= ((diff + i) / i) % m;
    }
    return res % m;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        cout << cnk() << '\n';
    return 0;
}