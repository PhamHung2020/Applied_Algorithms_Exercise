#include <iostream>
#include <algorithm>
using namespace std;

int n, c, arr[100100], top, bot, mid, ans;

bool check(int mid)
{
    int previous = arr[0];
    int cnt = 1;
    for (int i = 1; i < n; ++i)
    {
        if (arr[i] - previous >= mid)
        {
            ++cnt;
            previous = arr[i];
        }
    }
    return cnt >= c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t > 0)
    {
        cin >> n >> c;
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);

        bot = 0;
        top = 1000000001;
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

        cout << ans << '\n';
        --t;
    }

    return 0;
}