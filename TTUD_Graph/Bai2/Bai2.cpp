#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int n, k;
pair<int, int> xy[550];
bool visited[550];
vector<int> iDist(550, 1e9 + 5);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int dist(int i, int j)
{
    int x1 = xy[i].first;
    int x2 = xy[j].first;
    int y1 = xy[i].second;
    int y2 = xy[j].second;
    return (int)sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void dijkstra(int start, int end)
{
	visited[start] = true;
	iDist[start] = 0;
	pq.push({ iDist[start], start });
	while (!pq.empty())
	{
		int u = pq.top().second;
		visited[u] = true;
		if (u == end)
			break;
		pq.pop();
		for (int i = 2; i <= n; ++i)
		{
			if (visited[i])
				continue;
			int w = dist(u, i);
			if (w > k)
				continue;
			if (w + iDist[u] < iDist[i])
			{
				iDist[i] = w + iDist[u];
				pq.push({ iDist[i], i });
			}
		}
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> xy[i].first >> xy[i].second;
    }

	dijkstra(1, n);
	if (iDist[n] == 1e9 + 5)
		cout << -1;
	else
		cout << iDist[n];
}