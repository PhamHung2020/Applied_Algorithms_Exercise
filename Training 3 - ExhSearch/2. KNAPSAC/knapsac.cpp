#include <iostream>
#include <algorithm>

using namespace std;

int n, b, res = 0, value = 0, weight = 0;
int a[32], c[32];

void solve(int t)
{
    if (t > n)
    {
        res = max(res, value);
        return;
    }

    solve(t + 1);

    if (weight + a[t] > b)
    {
        res = max(res, value);
        return;
    }
    value += c[t];
    weight += a[t];
    solve(t + 1);
    value -= c[t];
    weight -= a[t];
}

int main()
{
    cin >> n >> b;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i] >> c[i];
    }

    solve(1);
    cout << res;
    return 0;
}