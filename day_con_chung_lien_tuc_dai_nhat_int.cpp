// C++ implementation of the above approach
#include <bits/stdc++.h>
using namespace std;


int a[10010], b[10010];

// Function to find the length of the
// longest LCS
int LCSubStr(int n, int m)
{

    // Create DP table
    int dp[2][m + 1];
    int res = 0;

    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= m; j++) 
        {
            if (a[i - 1] == b[j - 1]) 
            {
                dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1;
                if (dp[i % 2][j] > res)
                    res = dp[i % 2][j];
            }
            else
                dp[i % 2][j] = 0;
        }
    }
    return res;
}

// Driver Code
int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
        cin >> b[i];

    cout << LCSubStr(n, m);
    return 0;
}
