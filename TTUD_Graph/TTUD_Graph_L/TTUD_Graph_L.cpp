#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int n, m, s, t;
vector<pair<int, int>> edges[100100];
vector<int> iDist(100100, 1e9);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void Dijkstra(int start, int end)
{
	iDist[start] = 0;
	pq.push({ iDist[start], start });
	while (!pq.empty())
	{
		int u = pq.top().second;
		if (u == end)
			break;
		pq.pop();
		for (const pair<int, int>& edge : edges[u])
		{
			int v = edge.second;
			int w = edge.first;
			if (w + iDist[u] < iDist[v])
			{
				iDist[v] = w + iDist[u];
				pq.push({ iDist[v], v });
			}
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int x, y, w;
		cin >> x >> y >> w;
		edges[x].push_back({ w, y });
	}

	cin >> s >> t;

	Dijkstra(s, t);

	cout << iDist[t];
	return 0;
}