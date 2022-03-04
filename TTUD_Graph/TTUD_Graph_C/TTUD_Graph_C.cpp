#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n, m, bridge = 0, curnum = 0;
vector<vector<int>> adjList;
vector<int> low, num;
set<int> artiPoint;

void Dfs(int u, int p)
{
	int numChild = 0;
	low[u] = num[u] = ++curnum;
	for (int i = 0; i < adjList[u].size(); ++i)
	{
		int v = adjList[u][i];
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
			low[u] = min(low[u], num[v]);
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;

	adjList.resize(n + 5, vector<int>());
	low.resize(n + 5, 0);
	num.resize(n + 5, -1);

	int x, y;
	for (int i = 0; i < m; ++i)
	{
		cin >> x >> y;
		adjList[x].push_back(y);
		adjList[y].push_back(x);
	}

	for (int i = 1; i <= n; ++i)
	{
		if (num[i] == -1)
			Dfs(i, i);
	}

	cout << artiPoint.size() << ' ' << bridge;
	return 0;
}