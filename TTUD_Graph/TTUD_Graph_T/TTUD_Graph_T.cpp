// TTUD_Graph_T.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, res;
vector<int> d, t;
vector<vector<int>> aL;

void Dfs(int v)
{
    t[v] = 0;
    for (int i = 0; i < aL[v].size(); ++i)
    {
        int next = aL[v][i];
        if (t[next] == -1)
            Dfs(next);
        t[v] = max(t[next], t[v]);
    }
    t[v] += d[v];
    res = max(res, t[v]);
}

int main()
{
    cin >> n >> m;
    d.resize(n + 2, 0);
    t.resize(n + 2, -1);
    res = 0;
    for (int i = 1; i <= n; ++i)
        cin >> d[i];

    aL.resize(n + 2, vector<int>());
    int x, y;
    for (int i = 0; i < m; ++i)
    {
        cin >> x >> y;
        aL[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
        if (t[i] == -1)
            Dfs(i);

    std::cout << res;
    return 0;
}