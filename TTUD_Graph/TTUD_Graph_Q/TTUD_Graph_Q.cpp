#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int n, m, cnt;
vector<int> b[100100];
vector<pair<int, int>> bridges, a[100100];
int num[100100], low[100100], dir[100100];
bool c[100100];
long long res;

void dfs(int x)
{
	num[x] = low[x] = ++cnt;

	for (auto w : a[x])
	{
		int y = w.first;
		int i = w.second;

		if (dir[i] != 0) continue;
		dir[i] = y;

		if (num[y] == 0)
		{
			dfs(y);
			low[x] = min(low[x], low[y]);
			if (num[y] <= low[y])
				bridges.push_back({ x, y });
		}
		else
			low[x] = min(low[x], num[y]);
	}
}


void dfs1(int x)
{
	cnt++;
	c[x] = true;

	for (int y : b[x])
	{
		if (c[y]) continue;
		dfs1(y);
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
	{
		int x, y;
		cin >> x >> y;
		a[x].push_back({ y, i });
		a[y].push_back({ x, i });
	}

	for (int i = 1; i <= n; ++i)
		if (num[i] == 0) dfs(i);

	for (auto x : bridges)
	{
		int y = x.first;
		int z = x.second;

		b[y].push_back(z);
		b[z].push_back(y);
	}

	for (int i = 1; i <= n; ++i)
	{
		if (c[i] == false)
		{
			cnt = 0;
			dfs1(i);
			res += 1LL * (cnt * (cnt - 1) / 2 - (cnt - 1));
		}
	}

	cout << res;
	return 0;
}