#include <iostream>

using namespace std;

long long w, c, s, n;
long long num[10] = { 0, 1, 1, 1, 2, 1, 2, 2, 2, 3 };
long long way[10] = { 1, 1, 1, 1, 2, 1, 2, 1, 1, 3 };

int main()
{
	int ntest;
	cin >> ntest;

	while (ntest--)
	{
		cin >> w >> c;
		if (w % 1000)
		{
			cout << "0\n";
			continue;
		}

		w /= 1000;
		n = 0;
		s = 1;
		for (long long i = 0; i < c; ++i)
		{
			long long x = w % 10;
			w /= 10;
			n += num[x];
			s *= way[x];
		}

		if (w >= 10)
		{
			long long x = (w - 5) / 5;
			n += x;
			w -= x * 5;
		}
		n += num[w];
		s *= way[w];
		cout << n << ' ' << s << '\n';
	}
	return 0;
}