#include <bits/stdc++.h>
using namespace std;

int a[10010], b[10010], dp[10010][10010];


int lcs(int i, int j)
{
    if (i == 0 || j == 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int res = 0;
    res = max(res, lcs(i, j - 1));
    res = max(res, lcs(i - 1, j));
    if (a[i] == b[j])
        res = max(res, 1 + lcs(i-1, j-1));
    dp[i][j] = res;
    return res;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= m; ++i)
        cin >> b[i];

    memset(dp, -1, sizeof(dp));
    cout<< lcs(n, m) ;

    return 0;
}