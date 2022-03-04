#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, b, temp;
    cin >> n >> b;

    vector<int> a(n + 1), maxLeft(n + 1), maxRight(n + 1);
    a[0] = maxLeft[0] = maxRight[0] = -1;

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        maxLeft[i] = max(maxLeft[i - 1], a[i]);
    }

    maxRight[n] = a[n];
    for (int i = n - 1; i > 0; --i)
    {
        maxRight[i] = max(maxRight[i + 1], a[i]);
    }

    int pos = 0;
    for (int i = 2; i < n; ++i)
    {
        if (maxLeft[i - 1] - a[i] >= b && maxRight[i + 1] - a[i] >= b)
        {
            pos = i;
            break;
        }
    }

    if (pos == 0)
    {
        cout << -1;
        return 0;
    }

    int result = 0;
    for (int i = 2; i < n; ++i)
    {
        temp = maxLeft[i - 1] - a[i] + maxRight[i + 1] - a[i];
        result = max(temp, result);
    }

    std::cout << result;
    return 0;
}