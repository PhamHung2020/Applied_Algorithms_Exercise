#include <iostream>
#include <vector>

using namespace std;

int n, m, cnt;
vector<int> adjList[100100];
bool visited[100100];

void Dfs(int u)
{
    visited[u] = true;
    for (const int& v : adjList[u])
    {
        if (!visited[v])
        {
            Dfs(v);
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

    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            ++cnt;
            Dfs(i);
        }
    }

    cout << cnt;
    return 0;
}