#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int n, m, s, t;
vector<pair<int, int>> adjList[100005];
vector<int> dist(100005, 1e9);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void Dijkstra(int start, int end)
{
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty())
    {
        int u = pq.top().second;
        if (u == end)
            return;
        pq.pop();
        for (const auto& edge : adjList[u])
        {
            int v = edge.second;
            int w = edge.first;
            if (w + dist[u] < dist[v])
            {
                dist[v] = w + dist[u];
                pq.push({dist[v], v});
            }
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
        int x, y, w;
        cin >> x >> y >> w;
        adjList[x].push_back({y, w});
    }
    cin >> s >> t;

    Dijkstra(s, t);
    cout << dist[t];
    return 0;
}