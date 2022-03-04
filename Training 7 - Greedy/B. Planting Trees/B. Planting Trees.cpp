#include <iostream>
#include <algorithm>
using namespace std;

int n, a[100100], res;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	sort(a + 1, a + 1 + n, greater<int>());
	for (int i = 1; i <= n; ++i)
		res = max(res, i + a[i]);
	cout << res + 1;
	return 0;
}