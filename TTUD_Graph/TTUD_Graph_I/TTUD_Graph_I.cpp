#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int n, m, res = 0, numEdgeInTree = 0;
vector<pair<int, int>> edges;
vector<int> parents;

int FindRoot(int x)
{
	if (parents[x] == x)
		return x;
	return FindRoot(parents[x]);
}



void CountSpanningTree(int edgeIndex)
{
	if (edgeIndex > m)
		return;
	int rootFirst = FindRoot(edges[edgeIndex].first);
	int rootSecond = FindRoot(edges[edgeIndex].second);

	if (rootFirst != rootSecond)
	{
		++numEdgeInTree;
		if (numEdgeInTree == n - 1)
			++res;
		else
		{
			parents[rootFirst] = rootSecond;
			CountSpanningTree(edgeIndex + 1);
			parents[rootFirst] = rootFirst;
		}
		--numEdgeInTree;
	}
	CountSpanningTree(edgeIndex + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	edges.resize(m + 5);

	for (int i = 1; i <= m; ++i)
	{
		cin >> edges[i].first >> edges[i].second;
	}

	parents.resize(n + 5);
	for (int i = 1; i <= n; ++i)
		parents[i] = i;

	CountSpanningTree(1);
	cout << res;
	return 0;
}