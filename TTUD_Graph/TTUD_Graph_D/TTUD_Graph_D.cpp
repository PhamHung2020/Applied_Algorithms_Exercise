#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n, m, curnum, res = 0;
vector<vector<int>> adjList;
vector<int> low, num, isConnect;
stack<int> iComp;

void Scc(int u)
{
	low[u] = num[u] = ++curnum;
	isConnect[u] = 1;
	iComp.push(u);

	for (int i = 0; i < adjList[u].size(); ++i)
	{
		int v = adjList[u][i];
		if (num[v] == -1)
		{
			Scc(v);
			low[u] = min(low[u], low[v]);
		}
		else if (isConnect[v])
			low[u] = min(low[u], num[v]);
	}

	if (num[u] == low[u])
	{
		++res;
		while (true)
		{
			int cur = iComp.top();
			isConnect[cur] = 0;
			iComp.pop();
			if (cur == u)
				break;
		}
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
	isConnect.resize(n + 5, 0);

	int x, y;
	for (int i = 0; i < m; ++i)
	{
		cin >> x >> y;
		adjList[x].push_back(y);
	}

	for (int i = 1; i <= n; ++i)
	{
		if (num[i] == -1)
			Scc(i);
	}

	cout << res;

	return 0;
}