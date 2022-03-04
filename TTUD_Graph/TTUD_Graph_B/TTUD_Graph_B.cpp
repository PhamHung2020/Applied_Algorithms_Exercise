#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m;
vector<int> adjList[100100];
int iSide[100100];
int is_bipartie = 1;


void CheckBipartie(int u)
{
	for (int v : adjList[u])
	{
		if (iSide[v] == -1)
		{
			iSide[v] = 1 - iSide[u];
			CheckBipartie(v);
		}
		else if (iSide[v] == iSide[u])
			is_bipartie = 0;
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
		adjList[x].push_back(y);
		adjList[y].push_back(x);
	}

	memset(iSide, -1, sizeof(iSide));
	for (int i = 1; i <= n; ++i)
	{
		if (iSide[i] == -1)
		{
			iSide[i] = 0;
			CheckBipartie(i);
		}
	}

	cout << is_bipartie;
	return 0;
}