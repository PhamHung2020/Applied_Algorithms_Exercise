#include <iostream>
#include <cmath>

using namespace std;

int f[1000005], n, res = -1e9;

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int x;
    for(int i = 1;i <= n; ++i)
    {
        cin >> x;
        f[i] = f[i-1] < 0 ? x : f[i-1]+x;
        if (abs(f[i]) % 2 == 0)
            res = max(res, f[i]);
    }

    if (res > -1e9)
        cout << res;
    else
        cout << "NOT_FOUND";
    return 0;
}
