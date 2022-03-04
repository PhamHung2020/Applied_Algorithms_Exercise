#include <iostream>
#include <algorithm>

using namespace std;

struct block
{
    int x, y, z;
};

int n, m, res;
block a[100001];
int dp[100001];

bool cmp(block a, block b)
{
    return (a.x < b.x || a.x == b.x && a.y < b.y);
}

void add(int x, int y, int z)
{
    m++;
    a[m].x = min(x, y);
    a[m].y = max(x, y);
    a[m].z = z;
}

int main()
{
    int cnt = 0;
    while (true)
    {
        cin >> n;
        if (n == 0)
            return 0;
        ++cnt;
        m = 0;
        res = 0;
        int x, y, z;
        for (int i = 1; i <= n; ++i)
        {
            cin >> x >> y >> z;
            add(x, y, z);
            add(y, z, x);
            add(z, x, y);
        }

        sort(a + 1, a + 1 + m, cmp);

        for (int i = 1; i <= m; ++i)
        {
            dp[i] = a[i].z;
            for (int j = 1; j <= i; ++j)
            {
                if (a[j].x < a[i].x && a[j].y < a[i].y)
                {
                    dp[i] = max(dp[i], dp[j] + a[i].z);
                }
            }
            res = max(res, dp[i]);
        }

        cout << "Case " << cnt << ": maximum height = " << res << '\n';
    }
}