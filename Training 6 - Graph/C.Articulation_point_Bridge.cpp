#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

int n, m, cur, bridge;
vector<int> adjList[100100];
set<int> artiPoint;
bool visited[100100];
int low[100100], num[100100];

void Dfs(int u, int p)
{
    int numChild = 0;
    low[u] = num[u] = ++cur;
    for (const int& v : adjList[u])
    {
        if (v == p)
            continue;
        if (num[v] == -1)
        {
            ++numChild;
            Dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (u == p)
            {
                if (numChild >= 2)
                    artiPoint.insert(u);
            }
            else
            {
                if (low[v] >= num[u])
                    artiPoint.insert(u);
            }

            if (low[v] >= num[v])
                ++bridge;
        }
        else
        {
            low[u] = min(low[u], num[v]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }

    memset(num, -1, sizeof(num));
    memset(low, -1, sizeof(low));
    for (int i = 1; i <= n; ++i)
    {
        if (num[i] == -1)
        {
            Dfs(i, i);
        }
    }

    cout << artiPoint.size() << ' ' << bridge;
    return 0;
}