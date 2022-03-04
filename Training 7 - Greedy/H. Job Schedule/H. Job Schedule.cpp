#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
priority_queue<int> pq;
int n;
vector<int> profit[100100];

long long res;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n; 
	for (int i = 1; i <= n; ++i)
	{
		int d, p;
		cin >> d >> p;
		profit[d].push_back(p);
	}

	for (int i = 100005; i > 0; --i)
	{
		for (const int& p : profit[i])
			pq.push(p);

		if (!pq.empty())
		{
			res += pq.top();
			cout << i << ' ' << pq.top() << '\n';
			pq.pop();
		}
	}
	cout << res;
	return 0;
}