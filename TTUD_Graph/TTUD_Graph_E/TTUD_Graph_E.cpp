#include <iostream>
#include <vector>

using namespace std;

long long n;
int C = 1000000000 + 7;
vector<long long> t, f;
int main()
{
	cin >> n;
	if (n == 1)
		cout << 1;
	else if (n == 2)
		cout << 4;
	else
	{
		t.resize(n + 1, 0);
		f.resize(n + 1, 0);
		t[1] = f[1] = 1;
		for (int i = 2; i <= n; ++i)
		{
			t[i] = (3 * t[i - 1] + f[i - 1]) % C;
			f[i] = (2 * t[i - 1] + f[i - 1]) % C;
		}
		cout << t[n];
	}

	return 0;
}