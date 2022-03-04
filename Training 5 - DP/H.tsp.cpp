#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, c[25][25];
int iMem[25][1 << 21];

int tsp(int i, int S)
{
    if (S == ((1 << n) - 1))
        return c[i][0];
    if (iMem[i][S] != -1)
        return iMem[i][S];

    int res = 1e9;
    for (int j = 0; j < n; ++j)
    {
        if (S & (1 << j) || c[i][j] == 0)
            continue;
        if ((S | (1 << j)) == ((1 << n) - 1) && c[j][0] == 0)
            continue;
        res = min(res, c[i][j] + tsp(j, S | (1 << j)));
    }
    iMem[i][S] = res;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(iMem, -1, sizeof(iMem));
    cin >> n >> m;

    int x, y, d;
    for (int i = 0; i < m; ++i)
    {
        cin >> x >> y >> d;
        c[x - 1][y - 1] = d;
    }

    cout << tsp(0, 1 << 0);

    return 0;
}