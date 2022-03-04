#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int n, cnt;
pair<int, int> segments[100100];
pair<int, int> lastSegment;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> segments[i].second >> segments[i].first;
	}

	sort(segments + 1, segments + 1 + n);
	lastSegment = segments[1];
	cnt = 1;
	for (int i = 2; i <= n; ++i)
	{
		if (segments[i].second > lastSegment.first)
		{
			cnt++;
			lastSegment = segments[i];
		}
	}

	cout << cnt;
	return 0;
}