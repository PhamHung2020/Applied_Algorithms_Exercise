#include <iostream>
#include <vector>

using namespace std;

int n, m, res;
bool edge[15][15];
vector<int> subgraph;

bool check(int u)
{
	for (const int& v : subgraph)
	{
		if (!edge[u][v])
			return false;
	}
	return true;
}

void solve(int u)
{
	for (int i = u + 1; i <= n; ++i)
	{
		if (check(i))
		{
			subgraph.push_back(i);
			int size = subgraph.size();

			if (size > res)
				res = size;

			if (size < n)
				solve(i);

			subgraph.pop_back();
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
		int x, y;
		cin >> x >> y;
		edge[x][y] = true;
		edge[y][x] = true;
	}

	solve(0);
	cout << res;
	return 0;
}