#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

int binary_search(const vector<int> &arr, int bot, int top, int key)
{
    int mid;
    while (bot <= top)
    {
        mid = bot + (top - bot) / 2;
        if (arr[mid] == key)
            return 1 + binary_search(arr, bot, mid - 1, key) + binary_search(arr, mid + 1, top, key);
        else if (arr[mid] > key)
            top = mid - 1;
        else
            bot = mid + 1;
    }
    return false;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a.begin(), a.end());
    int cnt = 0;
    for (int i = 0; i < n - 2; ++i)
    {
        for (int j = i + 1; j < n - 1; ++j)
        {
            int remain = k - a[i] - a[j];
            if (remain <= 0)
                continue;
            cnt += binary_search(a, j + 1, n - 1, remain);
        }
    }
    cout << cnt;

    return 0;
}