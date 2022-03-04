#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> adjList[100100];


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

	int cnt = 0;
	for (int i = 2; i <= n; ++i)
	{
		if (adjList[i].size() == 1)
			++cnt;
	}

	cout << cnt;

	return 0;
}