#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> adjList[100100];
bool visited[100100];
int parent[100100];

void Dfs(int u)
{
	visited[u] = true;
	for (const int& v : adjList[u])
	{
		if (visited[v])
		{
			parent[u] = v;
			continue;
		}
		Dfs(v);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n - 1; ++i)
	{
		int x, y;
		cin >> x >> y;
		adjList[x].push_back(y);
		adjList[y].push_back(x);
	}

	Dfs(1);
	for (int i = 2; i <= n; ++i)
		cout << parent[i] << ' ';
	return 0;
}