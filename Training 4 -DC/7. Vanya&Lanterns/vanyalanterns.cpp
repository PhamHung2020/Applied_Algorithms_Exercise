#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, l;
vector<int> arr;

bool check(double mid)
{
    double litPoint = 0;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] - mid - litPoint >= 1e-9)
            return false;
        litPoint = arr[i] + mid;
    }
    return l - litPoint < 1e-9;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> l;
    arr.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr.begin(), arr.end());

    double bot = 0;
    double top = l;
    double mid;
    double ans;
    while (top - bot >= 1e-9)
    {
        mid = (top + bot) / 2.0;
        if (check(mid))
        {
            ans = mid;
            top = mid;
        }
        else
            bot = mid;
    }
    printf("%.10f", ans);
    return 0;
}