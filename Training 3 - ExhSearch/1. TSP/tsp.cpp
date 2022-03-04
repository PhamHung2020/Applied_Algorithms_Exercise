#include <iostream>
#include <algorithm>
using namespace std;

int qd[25][25];
int res = 1e9;
int visit[25];
int n;
void solve(int t, int tqd, int k)
{
    if (k > n)
    {
        if (qd[t][1] != 0)
            res = min(res, tqd + qd[t][1]);
        return;
    }
    for (int i = 2; i <= n; ++i)
    {
        if (!visit[i] && qd[t][i] != 0 && tqd + qd[t][i] <= res)
        {
            visit[i] = 1;
            solve(i, tqd + qd[t][i], k + 1);
            visit[i] = 0;
        }
    }
}

int main()
{
    int m;
    cin >> n >> m;

    int a, b, c;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> c;
        qd[a][b] = c;
    }

    visit[1] = 1;
    solve(1, 0, 2);
    cout << res;
    return 0;
}