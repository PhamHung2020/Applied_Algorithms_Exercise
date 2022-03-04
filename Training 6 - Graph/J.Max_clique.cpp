#include <iostream>
#include <vector>

using namespace std;

int n, m, res;
bool edge[15][15];
vector<int> subgraph;

bool Check(int u)
{
    for (const int& v : subgraph)
    {
        if (!edge[u][v])
            return false;
    }
    return true;
}

void Solve(int u)
{
    for (int i = u + 1; i <= n; ++i)
    {
        if (Check(i))
        {
            subgraph.push_back(i);
            if (subgraph.size() > res)
                res = subgraph.size();
            Solve(i);
            subgraph.pop_back();
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        edge[x][y] = edge[y][x] = true;
    }

    Solve(0);

    cout << res;
    return 0;
}