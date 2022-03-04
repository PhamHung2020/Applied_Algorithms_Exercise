#include <iostream>

using namespace std;

int n, L1, L2;
long long res, a[100100], dp[100100];

int main()
{
    cin >> n >> L1 >> L2;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    dp[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        long long tmp = 0;
        int st = max(0, i - L2);
        int fi = max(0, i - L1);

        for (int j = st; j <= fi; ++j)
            tmp = max(tmp, dp[j]);

        dp[i] = a[i] + tmp;
        res = max(res, dp[i]);
    }

    cout << res;
    return 0;
}