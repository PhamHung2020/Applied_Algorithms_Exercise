#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int n, res;
vector<vector<pair<int, int>>> adjList;
vector<bool> isVisited;

int LongestPath(int u)
{
	int longestSubPath = 0;
	int secondLongestSubPath = 0;
	for (int i = 0; i < adjList[u].size(); ++i)
	{
		int v = adjList[u][i].first;
		int weight = adjList[u][i].second;
		if (isVisited[v])
			continue;
		isVisited[v] = true;
		int length = weight + LongestPath(v);
		if (length > longestSubPath)
		{
			secondLongestSubPath = longestSubPath;
			longestSubPath = length;
		}
		else if (length > secondLongestSubPath)
			secondLongestSubPath = length;
	}
	res = max(res, longestSubPath + secondLongestSubPath);
	return longestSubPath;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	adjList.resize(n + 5, vector < pair<int, int>>());
	isVisited.resize(n + 5, false);

	int x, y, z;
	for (int i = 1; i < n; ++i)
	{
		cin >> x >> y >> z;
		adjList[x].push_back({ y, z });
		adjList[y].push_back({ x, z });
	}

	isVisited[1] = true;
	LongestPath(1);
	cout << res;
	return 0;
}