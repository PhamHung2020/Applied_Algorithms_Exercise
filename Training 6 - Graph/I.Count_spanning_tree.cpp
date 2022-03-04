#include <iostream>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;

int n, m, res, num;
pair<int, int> edges[30];
int root[25];

int getroot(int u)
{
    return root[u]? getroot(root[u]) : u;
}

void Solve(int edgeIndex)
{
    if (edgeIndex > m)
        return;
    
    int rootA = getroot(edges[edgeIndex].first);
    int rootB = getroot(edges[edgeIndex].second);
    if (rootA != rootB)
    {
        ++num;
        if (num == n-1)
            ++res;
        else
        {
            root[rootA] = rootB;
            Solve(edgeIndex + 1);
            root[rootA] = 0;
        }
        --num;
    }
    Solve(edgeIndex + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> edges[i].first >> edges[i].second;
    }

    Solve(1);

    cout << res;
    return 0;
}