#include <iostream>
#include <vector>

using namespace std;

int n, m, k, res, first, numVertex;
vector<int> adjList[35];
bool visited[35];

void Dfs(int u)
{
	for (const auto& v : adjList[u])
	{
		if (v == first && numVertex == k - 1)
		{
			++res;
			return;
		}
		if (!visited[v])
		{
			visited[v] = true;
			++numVertex;
			Dfs(v);
			--numVertex;
			visited[v] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i)
	{
		int x, y;
		cin >> x >> y;
		adjList[x].push_back(y);
		adjList[y].push_back(x);
	}

	for (int i = 1; i <= n; ++i)
	{
		first = i;
		visited[i] = true;
		Dfs(i);
		visited[i] = false;
	}

	cout << res / k / 2;

	return 0;
}