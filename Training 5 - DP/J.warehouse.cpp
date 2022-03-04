#include <iostream>

using namespace std;

int n, t, d;
int a[1005], td[1005];
int f[1005][1005];
int res;

int main()
{
    cin >> n >> t >> d;

    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
        cin >> td[i];

    for (int i = 1; i <= t; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            for (int k = 1; k <= d; ++k)
            {
                if (i - td[j] >= 0 && j - k >= 0)
                {
                    f[i][j] = max(f[i][j], f[i - td[j]][j - k] + a[j]);
                    res = max(res, f[i][j]);
                }
            }
        }
    }

    cout << res;

    return 0;
}