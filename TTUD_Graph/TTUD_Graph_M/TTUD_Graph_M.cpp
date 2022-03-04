#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge
{
	int u;
	int v;
	int weight;
};

int n, m;
long long res;
vector<edge> edges;
int parents[100100];

int findRoot(int x)
{
	if (parents[x] == 0)
		return x;
	parents[x] = findRoot(parents[x]);
	return parents[x];
	//return findRoot(parents[x]);
}


bool edge_cmp(const edge& a, const edge& b)
{
	return a.weight < b.weight;
}

void mst()
{
	sort(edges.begin(), edges.end(), edge_cmp);
	for (int i = 0; i < m; ++i)
	{
		int rootU = findRoot(edges[i].u);
		int rootV = findRoot(edges[i].v);
		if (rootU != rootV)
		{
			parents[rootU] = rootV;
			res += edges[i].weight;
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
		edge newEdge;
		cin >> newEdge.u >> newEdge.v >> newEdge.weight;
		edges.push_back(newEdge);
	}

	mst();
	cout << res;
	return 0;
}