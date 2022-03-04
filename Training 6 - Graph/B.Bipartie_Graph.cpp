#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m, cnt;
vector<int> adjList[100100];
int bipartie[100100];
bool isPartie = true;

void Dfs(int u)
{
    for (const int& v : adjList[u])
    {
        if (bipartie[v] == -1)
        {
            bipartie[v] = 1 - bipartie[u];
            Dfs(v);
        }
        else if (bipartie[u] == bipartie[v])
        {
            isPartie = false;
            break;
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

    memset(bipartie, -1, sizeof(bipartie));

    for (int i = 1; i <= n; ++i)
    {
        if (bipartie[i] == -1)
        {
            bipartie[i] = 1;
            Dfs(i);
        }
        if (!isPartie)
            break;
    }

    cout << isPartie;

    return 0;
}