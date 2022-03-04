#include <iostream>

using namespace std;

int n;
int s[2000100], t[2000100];
int m[2000100], dp[2000100];
int res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> s[i] >> t[i];
        m[t[i]] = max(m[t[i]], t[i] - s[i]);
    }

    for (int i = 1; i <= 2e6; ++i)
    {
        dp[i] = max(dp[i - 1], m[i]);
    }

    for (int i = 1; i <= n; ++i)
    {
        res = max(res, dp[s[i] - 1] + t[i] - s[i]);
    }

    cout << res;
    return 0;
}