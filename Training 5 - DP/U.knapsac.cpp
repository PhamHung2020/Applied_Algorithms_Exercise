#include<iostream>

using namespace std;

int n, b, res;
int a[50], c[50], f[1000100];

int main()
{
    cin >> n >> b;
    for (int i = 1; i <= n; ++i)
        cin >> a[i] >> c[i];
    
    for (int i = 1; i <= n; ++i)
    {
        for (int t = b; t >= a[i]; --t)
        {
            f[t] = max(f[t], f[t - a[i]] + c[i]);
        }
    }

    res = f[0];
    for (int t = 1; t <= b; ++t)
        res = max(res, f[t]);
    cout << res;
    return 0;
}