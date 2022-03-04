#include<iostream>
#include<algorithm>
using namespace std;

int W, H, n;
int dp[610][610];

int main()
{
    cin >> W >> H;
    cin >> n;

    int w, h;
    for (int i = 0; i < n; ++i)
    {
        cin >> w >> h;
        dp[w][h] = w * h;
    }

    for (int i = 1; i <= W; ++i)
    {
        for (int j = 1; j <= H; ++j)
        {
            for (int i1 = 1; i1 < i; ++i1)
            {
                int i2 = i - i1;
                dp[i][j] = max(dp[i][j], dp[i1][j] + dp[i2][j]);
            }

            for (int j1 = 1; j1 < j; ++j1)
            {
                int j2 = j - j1;
                dp[i][j] = max(dp[i][j], dp[i][j1] + dp[i][j2]);
            }
        }
    }

    cout << W * H - dp[W][H];
    return 0;
}