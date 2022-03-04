#include <iostream>
#include <algorithm>
using namespace std;

long long n, m, arr[1000010], top, bot, mid, ans;

bool check(long long mid)
{
    long long sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (arr[i] > mid)
            sum += arr[i] - mid;
    }
    return sum >= m;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
        top = max(top, arr[i]);
    }

    bot = 0;
    ans = -1;

    while (bot <= top)
    {
        mid = (bot + top) / 2;
        if (check(mid))
        {
            ans = mid;
            bot = mid + 1;
        }
        else
        {
            top = mid - 1;
        }
    }

    cout << ans;
    return 0;
}